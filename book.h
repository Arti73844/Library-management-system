#ifndef BOOK_H
#define BOOK_H

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void issueBook(int studentId);   // ADD THIS
void returnBook(int studentId);  // (similar logic)

#endif
