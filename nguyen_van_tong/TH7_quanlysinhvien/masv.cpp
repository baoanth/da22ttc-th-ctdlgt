#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char name[20];
    char code[20];
    struct Node* next;
} Node;

Node* creNode(const char* name, const char* code) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    strcpy(p->code, code);
    p->next = NULL;
    return p;
}

void addNode(Node* &head, Node* p) {
    if (head == NULL)
        head = p;
    else {
        Node* q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

Node* loadData(Node* &head,const char* filename) {
    FILE* infile = fopen(filename, "r");
    if (infile != NULL) {
        char line[30];
        while (fgets(line, sizeof(line), infile)) {
            char code[20];
            char name[20];
            sscanf(line, "%[^,], %[^\n]", code, name);
            Node* tmp = creNode(name, code);
            addNode(head, tmp);
        }
        fclose(infile);
        return head;
    }
    return NULL;
}

void findStudentInfo(Node* bacList, Node* heList, Node* nganhList, Node* khoaList, const char* studentID) {
    if (strlen(studentID) != 9) {
        printf("Ma so sinh vien khong hop le\n");
        return;
    }

    char bacCode[3];
    strncpy(bacCode, studentID, 1);
    bacCode[1] = '\0';

    char heCode[3];
    strncpy(heCode, studentID + 1, 1);
    heCode[1] = '\0';

    char nganhCode[4];
    strncpy(nganhCode, studentID + 2, 2);
    nganhCode[2] = '\0';

    char khoaCode[4];
    strncpy(khoaCode, studentID + 4, 2);
    khoaCode[2] = '\0';

    Node* bacNode = bacList;
    while (bacNode != NULL) {
        if (strcmp(bacNode->code, bacCode) == 0) {
            break;
        }
        bacNode = bacNode->next;
    }

    Node* heNode = heList;
    while (heNode != NULL) {
        if (strcmp(heNode->code, heCode) == 0) {
            break;
        }
        heNode = heNode->next;
    }

    Node* nganhNode = nganhList;
    while (nganhNode != NULL) {
        if (strcmp(nganhNode->code, nganhCode) == 0) {
            break;
        }
        nganhNode = nganhNode->next;
    }

    Node* khoaNode = khoaList;
    while (khoaNode != NULL) {
        if (strcmp(khoaNode->code, khoaCode) == 0) {
            break;
        }
        khoaNode = khoaNode->next;
    }

    if (bacNode == NULL || heNode == NULL || nganhNode == NULL || khoaNode == NULL) {
        printf("Khong tim thay thong tin sinh vien\n");
        return;
    }

    printf("%s %s %s Khoa %s\n", heNode->name, bacNode->name, nganhNode->name, khoaNode->name);
}

int main() {
    Node* bac = NULL;
    Node* khoa = NULL;
    Node* nganh = NULL;
    Node* he = NULL;

    bac = loadData(bac,"bac.txt");
    khoa = loadData(khoa,"khoa.txt");
    nganh = loadData(nganh,"nganh.txt");
    he = loadData(he,"he.txt");

    char ma[10];
    printf("Nhap ma sinh vien: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = '\0';

    findStudentInfo(bac, he, nganh, khoa, ma);

    return 0;
}
