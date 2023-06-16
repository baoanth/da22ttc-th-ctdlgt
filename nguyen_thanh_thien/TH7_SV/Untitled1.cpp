#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai b�o c?u tr�c d? li?u cho m?t m?c trong danh s�ch li�n k?t
typedef struct Node {
    int code;
    char name[100];
    struct Node *next;
} Node;

// Khai b�o c?u tr�c d? li?u cho sinh vi�n
typedef struct SV {
    int id;
    int bac;
    int he;
    int nganh;
    int khoa;
} SV;

// Khai b�o c�c danh s�ch li�n k?t
Node *bacList = NULL;
Node *heList = NULL;
Node *nganhList = NULL;
Node *khoaList = NULL;

// �?c d? li?u t? m?t t?p tin v� t?o ra m?t danh s�ch li�n k?t tuong ?ng
Node *loadData(const char *filename) {
    // M? t?p tin d? d?c
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file %s.\n", filename);
        return NULL;
    }

    // T?o danh s�ch li�n k?t
    Node *head = NULL;

    // �?c d? li?u t? t?p tin v� th�m v�o danh s�ch li�n k?t
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // T�ch m� v� t�n t? chu?i d?c du?c
        char *token = strtok(line, ",");
        int code = atoi(token);

        token = strtok(NULL, ",");
        char name[100];
        strcpy(name, token);

        // T?o m?t n�t m?i cho danh s�ch li�n k?t
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->code = code;
        strcpy(newNode->name, name);
        newNode->next = NULL;

        // Th�m n�t m?i v�o danh s�ch li�n k?t
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

    // ��ng t?p tin
    fclose(file);

    return head;
}

// Ph�n t�ch m� sinh vi�n th�nh b?c, h?, ng�nh v� kh�a h?c
void analyzeCode(int code, SV *sv) {
    sv->bac = code / 10000;
    code %= 10000;

    sv->he = code / 1000;
    code %= 1000;

    sv->nganh = code / 100;
    code %= 100;

    sv->khoa = code;
}

// T�m t�n c?a m?t m?c trong danh s�ch li�n k?t
char *getName(Node *head, int code) {
    while (head != NULL) {
        if (head->code == code) {
            return head->name;
        }
        head = head->next;
    }
    return "Khong tim thay";
}

// In th�ng tin sinh vi�n d?a tr�n m� s? sinh vi�n
void printSV(SV sv) {
    printf("%s %s %s %s\n", getName(bacList, sv.bac), getName(heList, sv.he), getName(nganhList, sv.nganh), getName(khoaList, sv.khoa));
}

int main() {
    // Load d? li?u v�o danh s�ch li�n k?t tuong ?ng
    bacList = loadData("bac.txt");
    heList = loadData("he.txt");
    nganhList = loadData("nganh.txt");
    khoaList = loadData("khoa.txt");

    // Nh?p m� s? sinh vi�n
    printf("Nhap ma so sinh vien: ");
    int code;
    scanf("%d", &code);
    
    // Ph�n t�ch m� sinh vi�n v� in ra th�ng tin sinh vi�n
    SV sv;
    analyzeCode(code, &sv);
    printSV(sv);

    // Gi?i ph�ng b? nh? d� c?p ph�t cho c�c danh s�ch li�n k?t
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

