📚 Library Management System (C)

A file-based, role-driven Library Management System written in C, implementing Admin and Student login, persistent storage, and modular program design without using any database.

✨ Features
🔐 Authentication

Role-based login: Admin / Student

File-backed credential storage

Default admin account created automatically

📖 Book Management (Admin)

Add new books

View all books

Delete books

Track availability status

🧑‍🎓 Student Management

Persistent student records

Student validation before book issue

Book–student relationship tracking

🔄 Book Issue & Return (Student)

Issue available books

Return issued books

Prevent invalid operations



🗂️ Project Structure

library_system/
│
├── main.c        # Program entry point
├── auth.c/.h     # Authentication logic
├── book.c/.h     # Book operations
├── student.c/.h  # Student operations
├── files.h       # Shared constants
│
├── users.dat     # Login credentials
├── students.dat  # Student records
├── books.dat     # Book records


🧱 Data Storage (Binary Files)

users.dat → username | password | role | studentId

students.dat → studentId | name | department

books.dat → bookId | title | author | isIssued | issuedTo

Designed to simulate relational data modeling using pure C.

🔑 Default Credentials
Admin Login
Username: admin
Password: admin123


(Student accounts are created by the Admin.)

🛠️ Build & Run
Compile
gcc main.c auth.c book.c student.c -o library

Run
./library
