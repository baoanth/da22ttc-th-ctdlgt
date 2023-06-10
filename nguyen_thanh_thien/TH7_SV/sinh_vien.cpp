#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo c?u trúc d? li?u Sinh viên
typedef struct Student {
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

int main() {
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
                printf("Nhap ten file de luu du lieu: ");
                char filename[100];
                scanf("%s", filename);
                saveStudentsToFile(head, filename);
                printf("Luu file thanh cong!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (choice != 0);

    freeStudents(head);
    return 0;
}

// Hàm d? thêm sinh viên m?i vào danh sách
void addStudent(Student **head) {
    // T?o sinh viên m?i
    Student *newStudent = (Student*) malloc(sizeof(Student));
    
    // Nh?p thông tin t? ngu?i dùng
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &newStudent->id);
    
    printf("Nhap ho va ten: ");
    scanf("%s", newStudent->name);
    
    printf("\nNhap tuoi: ");
    scanf("%d", &newStudent->age);
    
    printf("\nNhap diem trung binh: ");
    scanf("%f", &newStudent->score);
    
    // Thêm sinh viên vào d?u danh sách
    newStudent->next = (*head);
    (*head) = newStudent;
}

// Hàm d? xóa m?t sinh viên kh?i danh sách
void deleteStudent(Student **head, int id) {
    // Khai báo các bi?n c?n thi?t
    Student *current = (*head);
    Student *prev = NULL;

    // Duy?t danh sách liên k?t d? tìm sinh viên có mã s? tuong ?ng
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // N?u tìm th?y sinh viên có mã s? tuong ?ng, xóa nút dó kh?i danh sách liên k?t
    if (current != NULL) {
        if (prev == NULL) { // N?u nút c?n xóa là nút d?u tiên c?a danh sách liên k?t
            (*head) = current->next; // C?p nh?t head
        } else {
            prev->next = current->next;
        }
        free(current); // Gi?i phóng b? nh? dã c?p phát cho nút c?n xóa
        printf("Xoa sinh vien co ma so %d thanh cong!\n", id);
    } else {
        printf("Khong tim thay sinh vien co ma so %d.\n", id);
    }
}

// Hàm d? s?a thông tin c?a m?t sinh viên trong danh sách
void updateStudent(Student *head, int id) {
    // Khai báo con tr? current d? duy?t danh sách và tìm sinh viên c?n s?a thông tin
    Student *current = head;

    // Duy?t danh sách liên k?t d? tìm sinh viên có mã s? tuong ?ng
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    // N?u tìm th?y sinh viên có mã s? tuong ?ng, cho phép ngu?i dùng s?a thông tin
    if (current != NULL) {
        printf("Thong tin moi cua sinh vien co ma so %d:\n", id);

        printf("Nhap ho va ten: ");
        scanf("%s", current->name);
        
        printf("Nhap tuoi: ");
        scanf("%d", &current->age);
        
        printf("Nhap diem trung binh: ");
        scanf("%f", &current->score);

        printf("Sua thong tin sinh vien thanh cong!\n");
    } else {
        printf("Khong tim thay sinh vien co ma so %d.\n", id);
    }
}

// Hàm d? hi?n th? danh sách sinh viên
void displayStudents(Student *head) {
    // N?u danh sách liên k?t r?ng, thông báo cho ngu?i dùng
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        // Duy?t danh sách liên k?t và in ra thông tin các sinh viên
        printf("%-10s %-30s %-10s %-10s\n", "Ma so", "Ho va ten", "Tuoi", "Diem TB");
        while (head != NULL) {
            printf("%-10d %-30s %-10d %-10.2f\n", head->id, head->name, head->age, head->score);
            head = head->next;
        }
    }
}

// Hàm d? luu thông tin các sinh viên vào file
void saveStudentsToFile(Student *head, const char *filename) {
    FILE *file = fopen(filename, "w");

    // N?u m? file thành công, duy?t danh sách liên k?t và ghi thông tin các sinh viên vào file
    if (file != NULL) {
        while (head != NULL) {
            fprintf(file, "%d %s %d %.2f\n", head->id, head->name, head->age, head->score);
            head = head->next;
        }
        fclose(file);
    } else {
        printf("Khong mo duoc file %s.\n", filename);
    }
}

// Hàm d? gi?i phóng b? nh? dã c?p phát cho các nút sinh viên trong danh sách
void freeStudents(Student *head) {
    while (head != NULL) {
        Student *temp = head;
        head = head->next;
        free(temp);
    }
}

