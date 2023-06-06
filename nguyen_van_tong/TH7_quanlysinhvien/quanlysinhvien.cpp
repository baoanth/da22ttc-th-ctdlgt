#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct SinhVien
{
    char maso[10];
    char ten[50];
    int tuoi;
    float dtb;
} Sinhvien;

typedef struct Node
{
    Sinhvien Info;
    Node *next;
} Node;

Node *creNode(Sinhvien x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->Info = x;
    p->next = NULL;
    return p;
}

Node *addStudent(Node *head)
{
    Sinhvien tmp;
    printf("Nhap ma sinh vien :");
    fflush(stdin);
    gets(tmp.maso);
    printf("Nhap ho ten sinh vien :");
    fflush(stdin);
    gets(tmp.ten);
    printf("Nhap tuoi sinh vien :");
    scanf("%d", &tmp.tuoi);
    printf("Nhap diem trung binh :");
    scanf("%f", &tmp.dtb);

    Node *p = creNode(tmp);
    if (head == NULL)
        head = p;
    else
    {
        Node *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    printf("da them sinh vien vao danh sach ");
    return head;
}

Node *deleteStudent(Node *pHead, char id[50])
{
    Node *p = pHead;
    Node *prevNode = NULL;

    if (p != NULL && strcmp(p->Info.maso, id) == 0)
    {
        pHead = p->next;
        free(p);
        printf("Sinh vien da bi xoa khoi danh sach.\n");
        return pHead;
    }
    while (p != NULL && strcmp(p->Info.maso, id) != 0)
    {
        prevNode = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Khong tim thay sinh vien voi ma so %s.\n", id);
        return pHead;
    }

    prevNode->next = p->next;
    free(p);
    printf("Sinh vien da bi xoa khoi danh sach.\n");
    return pHead;
}

void updateStudent(Node *head, char *id)
{
    Node *p = head;
    while (p != NULL && strcmp(p->Info.maso, id) != 0)
    {
        p = p->next;
    }
    if (p == NULL)
        printf("Khong tim thay sinh vien co ma so %d ", id);
    else
    {
        printf("nhap ma so moi: ");
        fflush(stdin);
        gets(p->Info.maso);
        printf("nhap ten moi: ");
        gets(p->Info.ten);
        printf("nhap tuoi moi: ");
        scanf("%d", &p->Info.tuoi);
        printf("nhap diem trung binh moi: ");
        scanf("%f", &p->Info.dtb);
    }
}

void displayStudents(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("\nMa sinh vien: %s", p->Info.maso);
        printf("\nHo ten sinh vien: %s", p->Info.ten);
        printf("\nTuoi inh vien: %d", p->Info.tuoi);
        printf("\nDiem trung binh: %.2f", p->Info.dtb);
        printf("\n------------------------------------\n");
        p = p->next;
    }
}

void saveStudentsToFile(Node *head, char* filename)
{
    FILE *f = fopen(filename, "w");
    Node *p = head;
    if (f == NULL)
    {
        printf("khong the mo file ");
        return;
    }

    while (p != NULL)
    {
        fprintf(f,"\nMa sinh vien: %s", p->Info.maso);
        fprintf(f,"\nHo ten sinh vien: %s", p->Info.ten);
        fprintf(f,"\nTuoi sinh vien: %d", p->Info.tuoi);
        fprintf(f,"\nDiem trung binh: %.2f", p->Info.dtb);
        p = p->next;
    }
    fclose(f);
    printf("da luu danh sach vao file ");
}

int main()
{
    Node *head = NULL;

    int choice;
    char id[10];
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
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Cam on ban da su dung chuong trinh!\n");
            break;
        case 1:
            head = addStudent(head);
            break;
        case 2:
            printf("Nhap ma so sinh vien can xoa: ");
            fflush(stdin);
            gets(id);
            head = deleteStudent(head, id);
            break;
        case 3:
            printf("Nhap ma so sinh vien can sua: ");
            fflush(stdin);
            gets(id);
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

    return 0;
}
