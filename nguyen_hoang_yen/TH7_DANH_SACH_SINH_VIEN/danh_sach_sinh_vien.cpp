#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc sv
typedef struct Student
{
    int id;
    char name[100];
    int age;
    float score;
    struct Student *next;
} Student;

Student *createStudent() 
{
    Student *student = (Student *)malloc(sizeof(Student));
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &student->id);

    printf("Nhap ho va ten: ");
    scanf("%s", student->name);

    printf("Nhap tuoi: ");
    scanf("%d", &student->age);

    printf("Nhap diem trung binh: ");
    scanf("%f", &student->score);
    student->next = NULL;
    return student;
}

// Them sv
void addStudent(Student **head) 
{
    Student *student = createStudent();
    if (*head == NULL) 
    {
        *head = student;
    } else 
    {
        Student *current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = student;
    }
    printf("Add sv moi thanh cong\n");
}

//Xoa sv
void deleteStudent(Student **head, int id) 
{
    if (*head == NULL) 
    {
        printf("Danh sach sv rong .\n");
        return;
    }
    Student *current = *head;
    Student *prev = NULL;
    while (current != NULL) 
    {
        if (current->id == id) 
        {
            if (prev == NULL) 
            {
                *head = current->next;
            } else 
            {
                prev->next = current->next;
            }
            free(current);
            printf("Da xoa sv co ma so %d .\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Ko tim thay sv co ma so %d.\n", id);
}

// Sua thong tin sv
void updateStudent(Student *head, int id) 
{
    if (head == NULL) {
        printf("Danh sach sv rong\n");
        return;
    }
    Student *current = head;
    while (current != NULL) 
    {
        if (current->id == id) 
        {
            printf("\nNhap ho va ten: ");
            scanf("%s", current->name);
            printf("\nNhap tuoi: ");
            scanf("%d", &current->age);
            printf("\nNhap diem trung binh: ");
            scanf("%f", &current->score);
            printf("Da cap nhat thong tin sinh vien co ma so %d .\n", id);
            return ;
        }
        current = current->next;
    }
    printf("Ko tim thay sv co ma so %d .\n", id);
}

// Hien thi ds sv
void displayStudents(Student *head) 
{
    if (head == NULL) 
    {
        printf("Danh sach sv rong .\n");
        return;
    }
    printf("Danh sach sv:\n");
    printf("%10s %20s %5s %10s\n", "Ma so", "Ho va ten", "Tuoi", "Diem TB");
    Student *current = head;
    while (current != NULL) 
    {
        printf("%10d %20s %5d %10.2f\n", current->id, current->name, current->age, current->score);
        current = current->next;
    }
}

// Luu ds sv vao file
void saveStudentsToFile(Student *head, const char *filename) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Ko the mo file de ghi!\n");
        return;
    }
    Student *current = head;
    while (current != NULL) 
    {
        fprintf(file, "%d,%s,%d,%.2f\n", current->id, current->name, current->age, current->score);
        current = current->next;
    }
    fclose(file);
    printf("Da luu danh sach sv vao file %s .\n", filename);
}

//Sap xep sv theo thu tu tang dan
void freeStudents(Student *head) 
{
    Student *current = head;
    while (current != NULL) 
    {
        Student *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Student *head = NULL;
    int selection;
    int id;

    do {
        printf("\n---- DANH SACH QUAN LY SINH VIEN ----\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        
        printf("Nhap lua chon cua ban : ");
        scanf("%d", &selection);

        switch (selection) 
		{
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            case 1:
                addStudent(&head);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                scanf("%d", &id);
                updateStudent(head, id);
                break;
            case 4:
                displayStudents(head);
            case 5:
                printf("Nhap ten file de luu danh sach sinh vien: ");
                char filename[100];
                scanf("%s", filename);
                saveStudentsToFile(head, filename);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (selection);

    freeStudents(head);

    return 0;
}

