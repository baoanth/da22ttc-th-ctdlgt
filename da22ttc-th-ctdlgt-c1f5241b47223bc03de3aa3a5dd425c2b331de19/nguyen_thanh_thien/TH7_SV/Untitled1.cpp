#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo c?u trúc d? li?u cho m?t m?c trong danh sách liên k?t
typedef struct Node {
    int code;
    char name[100];
    struct Node *next;
} Node;

// Khai báo c?u trúc d? li?u cho sinh viên
typedef struct SV {
    int id;
    int bac;
    int he;
    int nganh;
    int khoa;
} SV;

// Khai báo các danh sách liên k?t
Node *bacList = NULL;
Node *heList = NULL;
Node *nganhList = NULL;
Node *khoaList = NULL;

// Ð?c d? li?u t? m?t t?p tin và t?o ra m?t danh sách liên k?t tuong ?ng
Node *loadData(const char *filename) {
    // M? t?p tin d? d?c
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file %s.\n", filename);
        return NULL;
    }

    // T?o danh sách liên k?t
    Node *head = NULL;

    // Ð?c d? li?u t? t?p tin và thêm vào danh sách liên k?t
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // Tách mã và tên t? chu?i d?c du?c
        char *token = strtok(line, ",");
        int code = atoi(token);

        token = strtok(NULL, ",");
        char name[100];
        strcpy(name, token);

        // T?o m?t nút m?i cho danh sách liên k?t
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->code = code;
        strcpy(newNode->name, name);
        newNode->next = NULL;

        // Thêm nút m?i vào danh sách liên k?t
        if (head == NULL) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Ðóng t?p tin
    fclose(file);

    return head;
}

// Phân tích mã sinh viên thành b?c, h?, ngành và khóa h?c
void analyzeCode(int code, SV *sv) {
    sv->bac = code / 10000;
    code %= 10000;

    sv->he = code / 1000;
    code %= 1000;

    sv->nganh = code / 100;
    code %= 100;

    sv->khoa = code;
}

// Tìm tên c?a m?t m?c trong danh sách liên k?t
char *getName(Node *head, int code) {
    while (head != NULL) {
        if (head->code == code) {
            return head->name;
        }
        head = head->next;
    }
    return "Khong tim thay";
}

// In thông tin sinh viên d?a trên mã s? sinh viên
void printSV(SV sv) {
    printf("%s %s %s %s\n", getName(bacList, sv.bac), getName(heList, sv.he), getName(nganhList, sv.nganh), getName(khoaList, sv.khoa));
}

int main() {
    // Load d? li?u vào danh sách liên k?t tuong ?ng
    bacList = loadData("bac.txt");
    heList = loadData("he.txt");
    nganhList = loadData("nganh.txt");
    khoaList = loadData("khoa.txt");

    // Nh?p mã s? sinh viên
    printf("Nhap ma so sinh vien: ");
    int code;
    scanf("%d", &code);
    
    // Phân tích mã sinh viên và in ra thông tin sinh viên
    SV sv;
    analyzeCode(code, &sv);
    printSV(sv);

    // Gi?i phóng b? nh? dã c?p phát cho các danh sách liên k?t
    while (bacList != NULL) {
        Node *temp = bacList;
        bacList = bacList->next;
        free(temp);
    }
    while (heList != NULL) {
        Node *temp = heList;
        heList = heList->next;
        free(temp);
    }
    while (nganhList != NULL) {
        Node *temp = nganhList;
        nganhList = nganhList->next;
        free(temp);
    }
    while (khoaList != NULL) {
        Node *temp = khoaList;
        khoaList = khoaList->next;
        free(temp);
    }

    return 0;
}

