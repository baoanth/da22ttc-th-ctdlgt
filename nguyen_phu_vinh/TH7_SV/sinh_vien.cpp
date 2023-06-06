#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SinhVien
{
    char id [50];
    char name [100];
    int age;
    float score;
}SinhVien;

typedef struct Node
{
    SinhVien sv;
    struct Node* next;
}Node;

//h�m t?o m?t Node m?i vs th�ng tin sv
Node* createNode(SinhVien sv) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sv = sv;
    newNode->next = NULL;
    return newNode;
}

//
Node* addStudent(Node* pHead, SinhVien sv) 
{
    Node* newNode = createNode(sv);
    if (pHead == NULL) 
    {
        pHead = newNode;
    } 
    else 
    {
        Node* Root = pHead;
        while (Root->next != NULL) 
        {
            Root = Root->next;
        }
        Root->next = newNode;
    }
    printf("Sinh vien da duoc them vao danh sach.\n");
    return pHead;
}

//ham xoa va tim kiem sv
Node* deleteStudent(Node* pHead, char id[50]) 
{
    Node* Root = pHead;
    Node* prevNode = NULL;

    if (Root != NULL && strcmp(Root->sv.id, id) == 0) 
    {
        pHead = Root->next;
        free(Root);
        printf("Sinh vien da bi xoa khoi danh sach.\n");
        return pHead;
    }
    while (Root != NULL && strcmp(Root->sv.id, id) != 0) 
    {
        prevNode = Root;
        Root = Root->next;
    }

    if (Root == NULL) 
    {
        printf("Khong tim thay sinh vien voi ma so %s.\n", id);
        return pHead;
    }

    prevNode->next = Root->next;
    free(Root);
    printf("Sinh vien da bi xoa khoi danh sach.\n");
    return pHead;
}


void updateStudent(Node* pHead, char id [50]) 
{
    Node* Root = pHead;
    while (Root != NULL) 
    {
        if (strcmp(Root->sv.id, id) == 0) 
        {
            printf("Nhap ho ten moi: ");
            fgets(Root->sv.name, sizeof(Root->sv.name), stdin);
            printf("Nhap tuoi moi: ");
            scanf("%d", &(Root->sv.age));
            printf("Nhap diem trung binh moi: ");
            scanf("%f", &(Root->sv.score));
            printf("Thong tin sinh vien da duoc cap nhat.\n");
            return;
        }
        Root = Root->next;
    }
    printf("Khong tim thay sinh vien voi ma so %s.\n",id);
}


void displayStudents(Node* pHead) 
{
    if (pHead == NULL)
    {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    printf("Danh sach sinh vien:\n");
    Node* Root = pHead;
    while (Root != NULL) 
    {
        printf("Ma so sinh vien : %s", Root->sv.id);
        printf("Ho ten: %s", Root->sv.name);
        printf("Tuoi: %d\n", Root->sv.age);
        printf("Diem trung binh: %.2f\n", Root->sv.score);
        printf("----------------------\n");
        Root = Root->next;
    }
}

//h�m ch�o m?t Node v�o sortStudents 
Node* insertNode(Node* sortedList, Node* newNode) 
{
    if (sortedList == NULL || strcmp(newNode->sv.id, sortedList->sv.id) < 0) 
    {
        newNode->next = sortedList;
        sortedList = newNode;
    } 
	else
	{
        Node* Root = sortedList;
        while (Root->next != NULL && strcmp(newNode->sv.id, Root->next->sv.id) >= 0) 
        {
            Root = Root->next;
        }
        newNode->next = Root->next;
        Root->next = newNode;
    }
    return sortedList;
}   


Node* sortStudents(Node* pHead) 
{
    if (pHead == NULL || pHead->next == NULL) 
    {
        return pHead;
    }
    Node* Root = pHead;
    Node* sortedList = NULL;
    while (Root != NULL) 
    {
        Node* nextNode = Root->next;
        sortedList = insertNode(sortedList, Root);
        Root = nextNode;
    }

    return sortedList;
} 
    

void saveStudentsToFile(Node* pHead, char fileName[100]) 
{
    FILE* file = fopen(fileName, "w");

    if (file == NULL) 
    {
        printf("Khong the mo file %s.\n", fileName);
        return;
    }

    Node* Root = pHead;
    while (Root != NULL) 
    {
        fprintf(file, "%s\n", Root->sv.id);
        fprintf(file, "%s", Root->sv.name);
        fprintf(file, "%d\n", Root->sv.age);
        fprintf(file, "%.2f\n", Root->sv.score);
        Root = Root->next;
    }

    fclose(file);
    printf("Danh sach sinh vien da duoc luu vao file %s.\n", fileName);
}


void freeStudents(Node* pHead) 
{
    Node* Root = pHead;
    while (Root != NULL) 
    {
        Node* temp = Root;
        Root = Root->next;
        free(temp);
    }
}


int main() {
    Node* pHead = NULL;
    int choice;
    char name[100];
    char id[10];
    SinhVien sv;
	char filename;
    do {
        printf("=========== QUAN LY SINH VIEN ===========\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep sinh vien theo ma so sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("=========================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) 
		{
            case 1:
                printf("Nhap ma so sinh vien: ");
                fgets(sv.id, sizeof(sv.id), stdin);
                printf("Nhap ho ten: ");
                fgets(sv.name, sizeof(sv.name), stdin);
                printf("Nhap tuoi: ");
                scanf("%d", &sv.age);
                printf("Nhap diem trung binh: ");
                scanf("%f", &sv.score);
                pHead = addStudent(pHead, sv);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                fgets(id, sizeof(id), stdin);
                pHead = deleteStudent(pHead, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                fgets(id, sizeof(id), stdin);
                updateStudent(pHead, id);
                break;
            case 4:
                displayStudents(pHead);
                break;
            case 5:
                printf("Nhap ten file: ");
                scanf("%s",name);
                saveStudentsToFile(pHead,name );
                break;
            case 6:
                pHead = sortStudents(pHead);
                printf("Danh sach sinh vien da duoc sap xep.\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");
    } while (choice != 0);

    
    Node* Root = pHead;
    while (Root != NULL) 
    {
        Node* temp = Root;
        Root = Root->next;
        free(temp);
    }

    return 0;
}

