typedef struct Student {
    int id; // Mã số sinh viên
    char name[30]; // Tên sinh viên
    float gpa; // Điểm trung bình
    struct Student *next;
} Student;

typedef struct Linkedlist {
    Student *head;
} Linkedlist;

Linkedlist bachelors;
Linkedlist degrees;
Linkedlist years;
Linkedlist majors;

void loadData() {
    FILE *fp;

    // Đọc tập tin bậc đào tạo
    fp = fopen("bac.txt", "r");
    if (fp == NULL) {
        perror("Khong the doc file bac.txt");
        exit(1);
    }

    char line[50];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int id;
        char name[30];
        sscanf(line, "%d %[^\n]", &id, name);
        bachelors.head = addStudent(bachelors.head, id, name, 0);
    }
    fclose(fp);

    // Đọc tập tin hệ đào tạo
    fp = fopen("he.txt", "r");
    if (fp == NULL) {
        perror("Khong the doc file degrees.txt");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        int id;
        char name[30];
        sscanf(line, "%d %[^\n]", &id, name);
        degrees.head = addStudent(degrees.head, id, name, 0);
    }
    fclose(fp);

    // Đọc tập tin khóa đào tạo
    fp = fopen("khoa.txt", "r");
    if (fp == NULL) {
        perror("Khong the doc file years.txt");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        int id;
        char name[30];
        sscanf(line, "%d %[^\n]", &id, name);
        years.head = addStudent(years.head, id, name, 0);
    }
    fclose(fp);

    // Đọc tập tin ngành đào tạo
    fp = fopen("nganh.txt", "r");
    if (fp == NULL) {
        perror("Khong the doc file majors.txt");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        int id;
        char name[30];
        sscanf(line, "%d %[^\n]", &id, name);
        majors.head = addStudent(majors.head, id, name, 0);
    }
    fclose(fp);
}

void printStudentInfo(int id) {
    int bachId = (id / 10000) % 10;
    int degId = (id / 1000) % 10;
    int yearId = (id / 100) % 100;
    int majId = id % 1000;

    Student *bach = findStudentById(bachelors.head, bachId);
    Student *deg = findStudentById(degrees.head, degId);
    Student *year = findStudentById(years.head, yearId);
    Student *maj = findStudentById(majors.head, majId);

    if (bach == NULL || deg == NULL || year == NULL || maj == NULL) {
        printf("Khong tim thay sinh vien co MSSV la: %d\n", id);
    } else {
        printf("Thong tin sinh vien co MSSV la: %d\n", id);
        printf("Ten: %s\n", maj->name);
        printf("Bac: %s\n", bach->name);
        printf("He: %s\n", deg->name);
        printf("Khoa: %s\n", year->name);
    }
}
