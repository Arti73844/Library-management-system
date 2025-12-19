📚 Library Management System (C)

A menu-driven, file-based Library Management System developed in C, implementing role-based authentication (Admin / Student) with persistent storage.
The project demonstrates modular C programming, file I/O, and real-world data modeling without using any database.

🚀 Features
🔐 Authentication

Role-based login system:

Admin

Student

Secure credential validation using file-based storage

Default admin account auto-created on first run

📖 Book Management (Admin)

Add new books

View all books

Delete book records

Track issued and available books

🧑‍🎓 Student Management

Store student profiles persistently

Validate student records before issuing books

Link issued books to student IDs

🔄 Book Issue / Return (Student)

Issue available books

Return previously issued books

Prevent invalid or duplicate operations

🗂️ Project Structure
library_system/
│
├── main.c          # Application entry point
├── auth.c          # Login & authentication logic
├── auth.h
├── book.c          # Book-related operations
├── book.h
├── student.c       # Student records & student menu
├── student.h
├── files.h         # Shared constants and file paths
│
├── users.dat       # Login credentials storage
├── students.dat    # Student records
├── books.dat       # Book records

🧱 Data Storage Design

The system uses binary files for persistent storage:

users.dat

Stores authentication credentials:

username | password | role | studentId

students.dat

Stores student information:

studentId | name | department

books.dat

Stores book records:

bookId | title | author | isIssued | issuedTo


This design mimics relational data modeling using pure C and files.

🔑 Default Login Credentials
Admin Login
Username: admin
Password: admin123


(Student accounts must be added by the Admin.)

🛠️ Compilation & Execution
Compile
gcc main.c auth.c book.c student.c -o library

Run
./library
