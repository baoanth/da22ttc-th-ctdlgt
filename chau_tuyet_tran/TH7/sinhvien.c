#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Student
{
    int id;
    char firstname[10];
    char middlename [10];
    char surname[10];
    int age;
    float point;
    struct Student *next;
} Student;

Student *createVariable() 
{
    Student *student = (Student *)malloc(sizeof(Student));
    
    printf("- MSSV: ");
    scanf("%d", &student->id);

    printf("- Surname: ");
    scanf("%s", student->surname);
    
    printf("- Middle name: ");
    scanf("%s", student->middlename);
    
    printf("- First name: ");
    scanf("%s", student->firstname);

    printf("- Age: ");
    scanf("%d", &student->age);

    printf("- Point: ");
    scanf("%f", &student->point);
    
    
    student->next = NULL;
    return student;
}

void addStudent(Student **head) 
{
    Student *student = createVariable();
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
    printf("Tao sinh vien moi_hoan thanh!\n");
    printf ("  MSSV   | Surname |Middle name|Firstname|  Age  |  Point  \n");
    printf ("%d|  %s   |   %s   |   %s  |   %d  |  %.2f  \n", student->id, student->surname, student->middlename, student->firstname, student->age, student->point);
}

void deleteStudent(Student **head, int id) 
{
    if (*head == NULL) 
    {
        printf("Danh sach sinh vien rong.\n");
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
            printf("Da xoa sinh vien co ma so %d .\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Khong tim thay sinh vien co ma so %d.\n", id);
}

void updateStudent(Student *head, int id) 
{
    if (head == NULL) {
        printf("Danh sach sinh vien rong\n");
        return;
    }
    Student *current = head;
    while (current != NULL) 
    {
        if (current->id == id) 
        {
            printf("\nSurname: ");
            scanf("%s", current->surname);
            
            printf("\nMiddle name: ");
            scanf("%s", current->middlename);
            
            printf("\nFirstname: ");
            scanf("%s", current->firstname);
            
            printf("\nNhap tuoi: ");
            scanf("%d", &current->age);
            
            printf("\nPoint: ");
            scanf("%f", &current->point);
            printf("Sinh vien co ma so la %d da cap nhat thong tin.\n", id);
            
            return ;
        }
        current = current->next;
    }
    printf("Khong tim thay sinh vien.\n", id);
}

void displayStudents(Student *head) 
{
    if (head == NULL) 
    {
        printf("Danh sach sinh vien rong .\n");
        return;
    }
    printf("Danh sach sinh vien:\n");
    printf("%15s - %5s - %5s - %5s - %5s, %5s\n", "MSSV", "Surname", "Middle Name", "First name", "Age", "Point");
    Student *current = head;
    while (current != NULL) 
    {
        printf("%15d %20s %10d %10.2f\n", current->id, current->surname, current->middlename, current->firstname, current->age, current->point);
        current = current->next;
    }
}

void saveStudentsToFile(Student *head, const char *filename) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    Student *current = head;
    while (current != NULL) 
    {
        fprintf(file, "%d - %s - %s - %s - %d - %.2f\n", current->id, current->surname, current->middlename, current->firstname, current->age, current->point);
        current = current->next;
    }
    fclose(file);
    printf("Da luu danh sach sinh vien.\n", filename);
}

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
        printf("----- DANH SACH QUAN LY SINH VIEN -----");
        printf ("\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        
        printf("Nhap lua chon cua ban: ");
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

