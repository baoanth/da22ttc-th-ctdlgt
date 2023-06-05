#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo c?u trúc d? liêu Sinh viên
typedef struct Student
{
    int id;
    char name[100];
    int age;
    float score;
    struct Student *next;
} Student;

// Khai báo các hàm
void addStudent(Student **head);
void deleteStudent(Student **head, int id);
void updateStudent(Student *head, int id);
void displayStudents(Student *head);
void saveStudentsToFile(Student *head, const char *filename);
void freeStudents(Student *head);

int main()
 {
    Student *head = NULL;
    int choice;
    int id;

    do {
        printf("\n---- CHUONG TRINH QUAN LY SINH VIEN ----\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
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
                break;
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
    } while (choice != 0);

    freeStudents(head);

    return 0;
}

void addStudent(Student **head) {
    Student *newStudent = (Student *)malloc(sizeof(Student));

    printf("Nhap thong tin sinh vien:\n");
    printf("Ma so sinh vien: ");
    scanf("%d", &newStudent->id);
    printf("Ho ten: ");
    scanf("%s\n", newStudent->name);
    printf("Tuoi: ");
    scanf("%d\n", &newStudent->age);
    printf("Diem trung binh: ");
    scanf("%f", &newStudent->score);

    newStudent->next = *head;
    *head = newStudent;

    printf("Them sinh vien thanh cong.\n");
}

void deleteStudent(Student **head, int id) 
{
    Student *current = *head;
    Student *previous = NULL;

    while (current != NULL)
     {
        if (current->id == id)
         {
            if (previous == NULL)
             {
                // Xóa nút d?u danh sách
                *head = current->next;
            } else 
            {
                // Xóa nút n?m sau nút previous
                previous->next = current->next;
            }

            free(current);
            printf("Xoa sinh vien thanh cong.\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Khong tim thay sinh vien.\n");
}

void updateStudent(Student *head, int id)
 {
    Student *current = head;

    while (current != NULL)
     {
        if (current->id == id) 
        {
            printf("Nhap thong tin moi cho sinh vien:\n");
            printf("Ho ten: ");
            scanf("%s", current->name);
            printf("Tuoi: ");
            scanf("%d", &current->age);
            printf("Diem trung binh: ");
            scanf("%f", &current->score);

            printf("Sua thong tin sinh vien thanh cong.\n");
            return;
        }

        current = current->next;
    }

    printf("Khong tim thay sinh vien.\n");
}

void displayStudents(Student *head)
 {
    if (head == NULL)
     {
        printf("Danh sach sinh vien trong.\n");
     } else
    {
        Student *current = head;

        printf("Danh sach sinh vien:\n");
        while (current != NULL) {
            printf("Ma so sinh vien: %d\n", current->id);
            printf("Ho ten: %s\n", current->name);
            printf("Tuoi: %d\n", current->age);
            printf("Diem trung binh: %.2f\n", current->score);
            printf("-----------------------\n");

            current = current->next;
        }
    }
}

void saveStudentsToFile(Student *head, const char *filename) 
{
    FILE *file = fopen(filename, "w");

    if (file == NULL) 
    {
        printf("Khong the mo file.\n");
        return;
    }

    Student *current = head;

    while (current != NULL)
    {
        fprintf(file, "%d,%s,%d,%.2f\n", current->id, current->name, current->age, current->score);
        current = current->next;
    }

    fclose(file);
    printf("Luu danh sach sinh vien vao file thanh cong.\n");
}

void freeStudents(Student *head)
 {
    Student *current = head;
    Student *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
