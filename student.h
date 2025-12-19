#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int studentId;
    char name[50];
    char department[30];
};

void addStudent();
int isStudentValid(int studentId);
void studentMenu(int studentId);

#endif
