#include <stdio.h>
#include <string.h>
#include "student.h"
#include "files.h"
#include "book.h"

/* Add Student (Admin only) */
void addStudent() {
    struct Student s;
    FILE *fp = fopen(STUDENT_FILE, "ab");

    printf("Student ID: ");
    scanf("%d", &s.studentId);
    getchar();

    printf("Name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Department: ");
    fgets(s.department, 30, stdin);
    s.department[strcspn(s.department, "\n")] = 0;

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully.\n");
}

/* Validate Student ID */
int isStudentValid(int studentId) {
    struct Student s;
    FILE *fp = fopen(STUDENT_FILE, "rb");

    if (!fp) return 0;

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.studentId == studentId) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

/* Student Menu */
void studentMenu(int studentId) {
    int ch;
    do {
        printf("\n1.Search Book\n2.Issue Book\n3.Return Book\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: searchBook(); break;
            case 2: issueBook(studentId); break;
            case 3: returnBook(studentId); break;
        }
    } while (ch != 4);
}
