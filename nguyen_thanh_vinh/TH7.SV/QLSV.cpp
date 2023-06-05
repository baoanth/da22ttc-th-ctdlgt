#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int studentID;
    float gpa;
    char old[30];
} Student;

void addStudent(Student *students, int *count) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", students[*count].name);
    
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &students[*count].studentID);
    
    printf("Nhap diem trung binh: ");
    scanf("%f", &students[*count].gpa);
    
    printf("Nhap tuoi: ");
    scanf("%s", &students[*count].old);
    
    (*count)++;
    
    printf("Sinh vien da duoc them.\n");
}

void displayStudents(Student *students, int count) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("Ten: %s\n", students[i].name);
        printf("Ma so sinh vien: %d\n", students[i].studentID);
        printf("Diem trung binh: %.2f\n", students[i].gpa);
        printf("Nhap tuoi: %s\n", students[i].old);
        printf("--------------------\n");
    }
}

void searchStudent(Student *students, int count, char *searchName) {
    int found = 0;
    
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Ten: %s\n", students[i].name);
            printf("Ma so sinh vien: %d\n", students[i].studentID);
            printf("Diem trung binh: %.2f\n", students[i].gpa);
            printf("Nhap tuoi: %s\n", students[i].old);
            printf("--------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien co ten '%s'.\n", searchName);
    }
}

int main() {
    Student students[100];
    int count = 0;
    int choice;
    
    do {
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Tim kiem sinh vien theo ten\n");
        printf("4. Ban muon xoa sinh vien nao\n");
        printf("0. Thoat chuong trinh\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3: {
                char searchName[50];
                printf("Nhap ten sinh vien can tim: ");
                scanf("%s", searchName);
                searchStudent(students, count, searchName);
                break;
            case 4:
                addStudent(students, &count);
                break;
            }
            default:
                break;
        }
    } while (choice != 0);
    
    return 0;
}
