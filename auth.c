int login(int *studentId) {
    struct User u;
    char uname[20], pass[20];
    FILE *fp = fopen(USER_FILE, "rb");

    printf("Username: ");
    scanf("%s", uname);
    printf("Password: ");
    scanf("%s", pass);

    while (fread(&u, sizeof(u), 1, fp)) {
        if (!strcmp(u.username, uname) &&
            !strcmp(u.password, pass)) {

            if (u.role == STUDENT)
                *studentId = u.studentId;

            fclose(fp);
            return u.role;
        }
    }
    fclose(fp);
    return 0;
}
