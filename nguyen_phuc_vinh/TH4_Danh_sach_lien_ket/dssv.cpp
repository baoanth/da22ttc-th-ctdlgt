#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Khai báo c?u trúc d? li?u cho Sinh viên */
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

/* Khai báo c?u trúc d? li?u cho m?t nút trong danh sách liên k?t */
typedef struct ListNode {
    Student student;
    struct ListNode *next;
} ListNode;

/* C?p phát b? nh? cho m?t nút sinh viên m?i và kh?i t?o giá tr? */
ListNode *createNode(int id, char name[], int age, float gpa) {
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->student.id = id;
    strcpy(newNode->student.name, name);
    newNode->student.age = age;
    newNode->student.gpa = gpa;
    newNode->next = NULL;
    return newNode;
}

/* Thêm m?t sinh viên m?i vào cu?i danh sách liên k?t */
void addStudent(ListNode **head, int id, char name[], int age, float gpa) {
    ListNode *newNode = createNode(id, name, age, gpa);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

/* Xóa m?t sinh viên kh?i danh sách liên k?t */
void deleteStudent(ListNode **head, int id) {
    if (*head == NULL) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    ListNode *currentNode = *head;
    ListNode *previousNode = NULL;
    while (currentNode != NULL) {
        if (currentNode->student.id == id) {
            if (previousNode == NULL) {
                *head = currentNode->next;
            } else {
                previousNode->next = currentNode->next;
            }
            free(currentNode);
            printf("Da xoa sinh vien co ma so %d.\n", id);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Khong tim thay sinh vien co ma so %d.\n", id);
}

/* S?a thông tin c?a m?t sinh viên */
void editStudent(ListNode *head, int id) {
    ListNode *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->student.id == id) {
            printf("Nhap thong tin sinh vien:\n");
            printf("Ho va ten: ");
            fgets(currentNode->student.name, 50, stdin);
            currentNode->student.name[strcspn(currentNode->student.name, "\n")] = '\0';
            printf("Tuoi: ");
            scanf("%d", &currentNode->student.age);
            printf("Diem trung binh: ");
            scanf("%f", &currentNode->student.gpa);
            getchar();  /* Loai bo ky tu \n trong bo dem nhap chuoi */
            printf("Da sua thong tin sinh vien co ma so %d.\n", id);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Khong tim thay sinh vien co ma so %d.\n", id);
}

/* Hi?n th? danh sách sinh viên */
void printList(ListNode *head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    printf("%-10s %-30s %-5s %-5s\n", "MSV", "Ho va ten", "Tuoi", "DTB");
    ListNode *currentNode = head;
    while (currentNode != NULL) {
        printf("%-10d %-30s %-5d %-5.2f\n", currentNode->student.id, currentNode->student.name, 
            currentNode->student.age, currentNode->student.gpa);
        currentNode = currentNode->next;
    }
}

/* Luu danh sách sinh viên vào file */
void saveListToFile(ListNode *head, char fileName[]) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    ListNode *currentNode = head;
    fprintf(file, "%-10s %-30s %-5s %-5s\n", "MSV", "Ho va ten", "Tuoi", "DTB");
    while (currentNode != NULL) {
        fprintf(file, "%-10d %-30s %-5d %-5.2f\n", currentNode->student.id, currentNode->student.name, 
            currentNode->student.age, currentNode->student.gpa);
        currentNode = currentNode->next;
    }
    fclose(file);
    printf("Da luu danh sach sinh vien vao file %s.\n", fileName);
}

/* S?p x?p danh sách sinh viên theo th? t? tang d?n c?a mã s? sinh viên (Insertion sort) */
void sortList(ListNode **head) {
    if (*head == NULL) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    ListNode *currentNode = (*head)->next;
    while (currentNode != NULL) {
        ListNode *p = *head;
        while (p != currentNode) {
            if (p->student.id > currentNode->student.id) {
                /* Swap nodes */
                int tempId = p->student.id;
                char tempName[50];
                strcpy(tempName, p->student.name);
                int tempAge = p->student.age;
                float tempGpa = p->student.gpa;
                p->student.id = currentNode->student.id;
                strcpy(p->student.name, currentNode->student.name);
                p->student.age = currentNode->student.age;
                p->student.gpa = currentNode->student.gpa;
                currentNode->student.id = tempId;
                strcpy(currentNode->student.name, tempName);
                currentNode->student.age = tempAge;
                currentNode->student.gpa = tempGpa;
            }
            p = p->next;
        }
        currentNode = currentNode->next;
    }
    printf("Da sap xep danh sach sinh vien theo ma so tang dan.\n");
}

int main() {
    ListNode *head = NULL;
    int choice, id, age;
    float gpa;
    char name[50], fileName[50];
    do {
        printf("\nMenu chuc nang:\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  /* Loai bo ky tu \n trong bo dem nhap lua chon */
        switch (choice) {
            case 0:
                printf("Chuong trinh ket thuc.\n");
                break;
            case 1:
                printf("Nhap thong tin sinh vien:\n");
                printf("Ma so sinh vien: ");
                scanf("%d", &id);
                getchar();  /* Loai bo ky tu \n trong bo dem nhap chuoi */
                printf("Ho va ten: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Tuoi: ");
                scanf("%d", &age);
                printf("Diem trung binh: ");
                scanf("%f", &gpa);
                addStudent(&head, id, name, age, gpa);
                printf("Da them sinh vien moi.\n");
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua thong tin: ");
                scanf("%d", &id);
                editStudent(head, id);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Nhap ten file de luu danh sach sinh vien: ");
                fgets(fileName, 50, stdin);
                fileName[strcspn(fileName, "\n")] = '\0';
                saveListToFile(head, fileName);
                break;
            case 6:
                sortList(&head);
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);
    return 0;
}

