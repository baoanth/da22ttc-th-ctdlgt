#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Khai bao cau truc du lieu sinh vien
typedef struct Student
{
    int id;
    char name[100];
    int age;
    float score;
} Student;

typedef struct Node
{
    Student Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

//**********************
//Viet ham GetNode 
Node *GetNode(Student x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

//Viet ham Init cho List
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham AddTail
void AddTail(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

// Khai báo các hàm
//Viet ham them sinh vien
void AddStudent(Student head, List &l)
{
    printf("Vui long nhap thong tin: \n");
    printf("MSSV: ");
    scanf("%d", &head.id);
    fflush(stdin);
    printf("Ho Ten: ");
    gets(head.name);
    printf("Tuoi: ");
    scanf("%d", &head.age);
    printf("Diem TB: ");
    scanf("%f", &head.score);
    Node *new_ele = GetNode(head);
    AddTail(l, new_ele);
}


void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail == NULL;
        delete p;
    }
}

//Ham RemoveLast
void RemoveLast(List &l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if(p->pNext == l.pTail)
        {
            l.pTail = p;
            delete p->pNext;
        }
        p = p->pNext;
    }
}

//Viet ham xoa sinh vien
int DeleteStudent(List &l, int id)
{
    Node *p = l.pHead;
    Node *q;
    while (p != NULL)
    {
        if (p->Info.id == id)
            break;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    else
    {
        if (p = l.pHead)
            RemoveHead(l);
        if (p = l.pTail)
            RemoveLast(l);
    }
    return 1;
}

void UpdateStudent(List &l, int id)
{
    Node *p = l.pHead;
    while (p != NULL && p->Info.id != id)
        p = p->pNext;
    if (p == NULL)
        printf("Khong tim thay MSSV can sua!");
    else
    {
        printf("Vui long cap nhat lai thong tin: ");
        fflush(stdin);
        printf("\nHo Ten: ");
        gets(p->Info.name);
        printf("Tuoi: ");
        scanf("%d", &p->Info.age);
        printf("Diem TB: ");
        scanf("%f", &p->Info.score);
    }
}
void DisplayStudents(List l)
{
    printf("%15s%25s%10s%10s\n", "MSSV", "Ho Ten", "Tuoi", "Diem TB");
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%15d%25s%10d%10.2f\n", p->Info.id, p->Info.name, p->Info.age, p->Info.score);
        p = p->pNext;
    }
}

//Ham luu sinh vien vao File
void SaveStudentsToFile(List &l, const char *filename)
{
    FILE *f = fopen(filename, "w");
    Node *p = l.pHead;
    fprintf(f, "%15s%25s%10s%10s\n", "MSSV", "Ho Ten", "Tuoi", "Diem TB");
    while (p != NULL)
    {
        fprintf(f, "%15d%25s%10d%10.2f\n", p->Info.id, p->Info.name, p->Info.age, p->Info.score);
        p = p->pNext;
    }
    fclose(f);
}
// void freeStudents(Student *h);
//Viet ham main
int main()
{
    List kgt;
    Init(kgt);
    Student head;
    int lc;
    int id, kt;

    do
    {
        printf("\n---- CHUONG TRINH QUAN LY SINH VIEN ----\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lc);

        switch (lc)
        {
        case 0:
            printf("Cam on ban da su dung chuong trinh!\n");
            break;
        case 1:
            AddStudent(head,kgt);
            break;
        case 2:
            printf("Nhap ma so sinh vien can xoa: ");
            scanf("%d", &id);
            kt = DeleteStudent(kgt, id);
            if (kt == 0)
                printf("Khong tim thay MSSV can xoa");
            else
                printf("Da xoa sinh vien thanh cong!");
            break;
        case 3:
            printf("Nhap ma so sinh vien can sua: ");
            scanf("%d", &id);
            UpdateStudent(kgt, id);
            break;
        case 4:
            DisplayStudents(kgt);
            break;
        case 5:
            printf("Nhap ten file de luu danh sach sinh vien: ");
            char filename[100];
            scanf("%s", filename);
            SaveStudentsToFile(kgt, filename);
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai!\n");
            break;
        }
    } while (lc != 0);

    return 0;
}
