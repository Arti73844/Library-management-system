#include"auth.h"
#include"book.h"
#include"student.h"

int main() {
    int role, studentId = -1;
    createDefaultAdmin();

    role = login(&studentId);

    if (role == ADMIN) {
        adminMenu();
    } else if (role == STUDENT) {
        studentMenu(studentId);
    } else {
        printf("Invalid login\n");
    }
    return 0;
}
