#include "student.h"

struct Book {
    int id;
    char title[40];
    char author[40];
    int isIssued;
    int issuedTo;   // studentId
};





void issueBook(int studentId) {
    struct Book b;
    FILE *fp = fopen(BOOK_FILE, "rb+");

    int bookId;
    printf("Enter Book ID: ");
    scanf("%d", &bookId);

    if (!isStudentValid(studentId)) {
        printf("Invalid student record.\n");
        fclose(fp);
        return;
    }

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == bookId && !b.isIssued) {
            b.isIssued = 1;
            b.issuedTo = studentId;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("Book issued successfully.\n");
            fclose(fp);
            return;
        }
    }

    printf("Book not available.\n");
    fclose(fp);
}


void returnBook(int studentId) {
    struct Book b;
    FILE *fp = fopen(BOOK_FILE, "rb+");
    int bookId;

    printf("Enter Book ID: ");
    scanf("%d", &bookId);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == bookId && b.isIssued && b.issuedTo == studentId) {
            b.isIssued = 0;
            b.issuedTo = -1;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("Book returned successfully.\n");
            fclose(fp);
            return;
        }
    }

    printf("Return failed. Check book/student.\n");
    fclose(fp);
}
