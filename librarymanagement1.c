//LIBRARY MANAGEMENT SYSTEM
//C-ASSIGNMENT
//VRINDA ARORA-590020058=B.TECH CSE-B2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct book 
{
    int id;
    char title[50];
    char author[50];
    int issued;
    int copies;
};
void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();
void IssuedBooks();
void editBook();
void deleteBook();
void backupBook();
void printBook();
int main() 
{
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    printf("1.Add Book\n");
    printf("2.View Issued Books\n");
    printf("3.Edit Book\n");
    printf("4.Delete Book\n");
    printf("5. Backup Data\n");
    printf("6.View Books\n");
    printf("7.Search Book\n");
    printf("8.Issue Book\n");
    printf("9.Return Book\n");
    printf("10.Exit\n");
    char ch;
    printf("Enter L for librarian and S for student\n");
    scanf("%c", &ch);
    if(ch=='L' || ch=='l')
    {
    int choice;
    do
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        getchar();
        switch (choice) 
        {
            case 1:
             addBook(); 
             break;
            case 2:
             IssuedBooks(); 
             break;
             case 3:
             editBook(); 
             break;
             case 4:
             deleteBook(); 
             break;
            case 5:
             backupBook();
             break;
             case 10:
             printf("Exit\n");
             break;
            default:
             printf("Invalid choice!\n");
        }
    } while(choice!=10);
}
else if(ch=='S' || ch=='s')
{
    int choice;
    do
    { 
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 6:
    viewBooks();
    break;
    case 7:
    searchBook(); 
    break;
    case 8:
    issueBook();
    break;
    case 9:
    returnBook();
    break;
    case 10:
    printf("Exit\n");
    break;
    default:
    printf("Invalid choice\n");
    }
    } while (choice!=10);
}
else
{
    printf("Invalid choice\n");
}
printf("The receipt is as follows-");
return 0;
}
//Add books
void addBook()
 {
    FILE *fp;
    struct book b;
    fp=fopen("library.txt", "a");
    if (fp==NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Book ID\n");
    scanf("%d", &b.id);
    printf("Enter Title\n");
    getchar();
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title,"\n")]=0;
    printf("Enter Author\n");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author,"\n")] = 0;
    b.issued=0;
    printf("Enter number of copies\n");
    scanf("%d", &b.copies);
    printf("Number of the books are-%d\n", b.copies);
    b.issued=0;
    fprintf(fp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    fclose(fp);
    printf("Book added\n");
 }
 //View Books
void viewBooks() 
{
    FILE *fp;
    struct book b;
    fp=fopen("library.txt","r");
    if (fp==NULL) 
    {
        printf("No books found!\n");
        return;
    }
    printf("\nBOOKS\n");
    while(fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5) 
    {
        printBook(b);
    }
    fclose(fp);
}
//Search Books
void searchBook() 
{
    FILE *fp;
    struct book b;
    char name[50];
    int found=0;
    fp=fopen("library.txt", "r");
    if (fp==NULL) 
    {
        printf("No books found!\n");
        return;
    }
    printf("Enter book title\n");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    while(fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5) 
    {
        if (strcmp(b.title, name)==0) 
        {
            printf("Book Found!\n");
            printBook(b);
            found=1;
            break;
        }
    }
    if (!found) 
    printf("Book not found!\n");
    fclose(fp);
}
//Issue Books
void issueBook() 
{
    FILE *fp, *temp;
    struct book b;
    char name[50];
    int found=0;
    fp=fopen("library.txt", "r");
    temp=fopen("temp.txt", "w");
    if (!fp || !temp) 
    {
        printf("ERROR!\n");
        return;
    }
    printf("Enter title of book to issue\n");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")]=0;
    while (fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5) 
    {
        if (strcmp(b.title, name)==0)
        {
            if (b.issued<b.copies)
            {
                b.issued++;
                printf("Book issued successfully!\n");
            }
            else
            {
                printf("No copies available!\n");
            }
            found=1;
        }
        fprintf(temp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    if (!found)
    {
        printf("Book not found\n");
    }
    fclose(fp);
    fclose(temp);
    fp = fopen("library.txt", "w");
    temp = fopen("temp.txt", "r");
    if (!fp || !temp)
    {
        printf("Error while rewriting file!\n");
        if(fp) 
        fclose(fp);
        if(temp) 
        fclose(temp);
        return;
    }
    while (fscanf(temp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5)
    {
        fprintf(fp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    fclose(fp);
    fclose(temp);
}
//Return Books
void returnBook() 
{
    FILE *fp, *temp;
    struct book b;
    char name[50];
    int found=0;
    fp=fopen("library.txt", "r");
    temp=fopen("temp.txt", "w");
    if (!fp||!temp) 
    {
        printf("ERROR!\n");
        return;
    }
    printf("Enter title of book you wish to return\n");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")]=0;
    while (fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5) 
    {
        if (strcmp(b.title, name)==0 && b.issued>0) 
        {
            if (b.issued>0)
            {
                b.issued--;
                printf("Book returned!\n");
            }
            else
            {
                printf("This book is not issued!\n");
            }
            found=1;
        }
        fprintf(temp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    if (!found) 
    printf("Book not found!\n");
    fclose(fp);
    fclose(temp);
   fp = fopen("library.txt", "w");
    temp = fopen("temp.txt", "r");
    if (!fp || !temp)
    {
        printf("Error while rewriting file!\n");
        if(fp) 
    {
        fclose(fp);
    }
        if(temp) 
        {
        fclose(temp);
        }
        return;
    }
    while (fscanf(temp, "%d %49s %49s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5)
    {
        fprintf(fp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    fclose(fp);
    fclose(temp);
}
//Issued
void IssuedBooks()
 {
    FILE *fp;
    struct book b;
    int found=0;
    fp=fopen("library.txt","r");
    if (fp==NULL) 
    {
        printf("No books found!\n");
        return;
    }
    printf("\nISSUED BOOKS\n");
    while(fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5)
    {
        if (b.issued>0) 
        {
            printBook(b);
            found=1;
        }
    }
    if (!found)
    printf("No issued books\n");
    fclose(fp);
}
//Edit Book Details
void editBook() 
{
    FILE *fp=fopen("library.txt", "r");
    FILE *temp=fopen("temp.txt", "w");
    struct book b;
    int id,found=0;
    if(fp==NULL || temp==NULL)
    {
        printf("Error!\n");
        return;
    }
    printf("Enter Book ID to edit\n");
    scanf("%d", &id);
    getchar();
    while (fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author, &b.copies, &b.issued)==5) 
    {
        if (b.id==id) 
        {
           printf("Enter New Title\n");
            fgets(b.title, sizeof(b.title), stdin);
            b.title[strcspn(b.title, "\n")] = 0;
            printf("Enter New Author\n");
            fgets(b.author, sizeof(b.author), stdin);
            b.author[strcspn(b.author, "\n")] = 0;
            printf("Enter new number of copies\n");
            scanf("%d", &b.copies);
            getchar();
            if (b.issued>b.copies) 
            b.issued=b.copies;
            found=1;
        }
        fprintf(temp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    fclose(fp);
    fclose(temp);
    fp=fopen("library.txt", "w");
    temp=fopen("temp.txt", "r");
    if (!fp || !temp)
    {
        printf("Error while rewriting file!\n");
        if(fp) 
        {
            fclose(fp);
        }
        if(temp) 
        {
            fclose(temp);
        }
        return;
    }
    while(fscanf(temp, "%d %s %s %d %d\n", &b.id, b.title, b.author, &b.copies, &b.issued)==5)
    {
        fprintf(fp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    fclose(fp);
    fclose(temp);
    if(found)
    printf("Book updated successfully!\n");
    else
     printf("Book not found!\n");
}
//Deletes one copy of book
void deleteBook()
{
    int found=0,id;
    FILE *fp=fopen("library.txt", "r");
    FILE *temp=fopen("temp.txt", "w");
    struct book b;
    if(fp==NULL)
    {
        printf("Book not found!\n");
        return;
    }
    printf("Enter Book ID\n");
    scanf("%d", &id);
    while(fscanf(fp, "%d %s %s %d %d", &b.id, b.title, b.author,&b.copies, &b.issued)==5)
    {
    if(b.id==id)
    {
        if (b.copies>0)
            {
                b.copies--; 
                found=1;
                printf("One copy deleted. Remaining copies=%d\n", b.copies);
            }
            else
            {
                printf("No copies left to delete!\n");
            }
            found=1;
    }
     fprintf(temp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
}
    fclose(fp);
    fclose(temp);
    fp=fopen("library.txt", "w");
    temp=fopen("temp.txt", "r");
    if (!fp || !temp)
    {
        printf("Error while rewriting file!\n");
        if(fp) 
        {
            fclose(fp);
        }
        if(temp) 
        {
        fclose(temp);
        }
        return;
    }
     while(fscanf(temp, "%d %s %s %d %d\n", &b.id, b.title, b.author, &b.copies, &b.issued)==5)
    {
        fprintf(fp, "%d %s %s %d %d\n", b.id, b.title, b.author, b.copies, b.issued);
    }
    fclose(fp);
    fclose(temp);
    if(found)
    printf("Book deleted\n");
    else
    printf("Book not found\n");
}
//Function to back up book data
void backupBook()
{
    char ch;
    FILE *fp=fopen("library.txt", "r");
    FILE *backup=fopen("backup.txt", "w");
    if(fp==NULL)
    {
        printf("Book not found\n");
        return;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(ch, backup);
    }
    fclose(fp);
    fclose(backup);
    printf("Data backed up successfully!\n");
}
void printBook(struct book b) 
{
     printf("\n--------Receipt---------\n"); 
     printf("Book ID-%d\n", b.id); 
     printf("Title-%s\n", b.title); 
     printf("Author-%s\n", b.author); 
     printf("Total Copies-%d\n", b.copies); 
     printf("Issued Copies-%d\n", b.issued); 
     printf("Available-%d\n", b.copies-b.issued); 
     if ((b.copies-b.issued)>0) 
     printf("Status : Available\n"); 
     else printf("Status : Fully Issued\n"); 
     printf("-----------------------------\n"); 
}