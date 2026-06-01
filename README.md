# Library Management System
A system that can be used by librarians and students alike. Includes functions to add, search, view, issue, return, edit, delete, backup, view issued books and print the data.

## 📝 Description

This project is a console-based application that manages a library database using file storage (`library.txt`). It supports two types of users:

* **Librarian**
* **Student**

Each role has different functionalities such as adding books, issuing books, returning books, etc.

***

## ⚙️ Features

### 🔐 User Roles

#### 👩‍🏫 Librarian Access

* Add new books
* View issued books
* Edit book details
* Delete book copies
* Backup data

#### 👨‍🎓 Student Access

* View all books
* Search for a book by title
* Issue a book
* Return a book

***

## 📂 File Structure

* `librarymanagement1.c` → Main source code
* `library.txt` → Stores book records
* `temp.txt` → Temporary file used during updates
* `backup.txt` → Backup of library data

***

## 📊 Data Structure

```c
struct book {
    int id;           // Book ID
    char title[50];   // Book title
    char author[50];  // Author name
    int issued;       // Number of issued copies
    int copies;       // Total copies available
};
```

***

## ▶️ How to Run

### 1. Compile the Code

```bash
gcc librarymanagement1.c -o library
```

### 2. Run the Program

```bash
./library
```

***

## 📋 Menu Options

### Librarian Menu

```
1. Add Book
2. View Issued Books
3. Edit Book
4. Delete Book
5. Backup Data
10. Exit
```

### Student Menu

```
6. View Books
7. Search Book
8. Issue Book
9. Return Book
10. Exit
```

***

## ✅ Functional Overview

* **Add Book**: Stores book details in `library.txt`
* **View Books**: Displays all books with availability
* **Search Book**: Finds a book using title
* **Issue Book**: Increases issued count if available
* **Return Book**: Decreases issued count
* **Edit Book**: Updates title, author, or copies
* **Delete Book**: Removes one copy of a book
* **Backup**: Copies all data to `backup.txt`

***

## ⚠️ Limitations

* Titles and authors with spaces may not be handled properly due to `fscanf` usage
* No authentication system (simple role input only)
* No GUI (console-based only)
* Data is not encrypted
* Limited error handling

***

## 🚀 Possible Improvements

* Add login/authentication system
* Use better file parsing for multi-word titles
* Create a graphical interface (GUI)
* Add fine tracking (who issued which book)
* Store data using a database (e.g., SQLite)

***

## 💡 Conclusion

This project demonstrates:

* File handling in C
* Struct usage
* Menu-driven programming
* Basic CRUD operations

