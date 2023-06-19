#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct TTSV
{
    char ma[2];
    char ten[100];
} TTSV;

typedef struct Node
{
    TTSV Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(TTSV x)
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

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

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

void PrintList(List l)
{
    printf("\n");
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%5s %20s\n", p->Info.ma, p->Info.ten);
        p = p->pNext;
    }
}

char *Find(List l, char *data)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (strcmp(p->Info.ma, data) == 0)
        {
            return p->Info.ten;
        }
        p = p->pNext;
    }
    return NULL;
}

void load_data(char *filename, List &l)
{
    FILE *f = fopen(filename, "r");
    TTSV sv_tam;
    char chuoi_tam[100];
    char *tach_chuoi1;
    char *tach_chuoi2;
    if (f == NULL)
    {
        printf("Khong tim thay file");
        return;
    }
    else
    {
        while (fgets(chuoi_tam, sizeof(chuoi_tam), f) != NULL)
        {
            
            tach_chuoi1 = strtok(chuoi_tam, ",");
            if (tach_chuoi1 != NULL)
                strcpy(sv_tam.ma, tach_chuoi1);
            printf("%5s %20s", sv_tam.ma, sv_tam.ten);
            getch();
            tach_chuoi2 = strtok(NULL, ",");
            if (tach_chuoi2 != NULL)
                strcpy(sv_tam.ten, tach_chuoi2);
            printf("%5s %20s", sv_tam.ma, sv_tam.ten);
            getch();
            
            //chuoi_tam[strcspn(chuoi_tam, "\n")] = '\0';
            //sscanf(chuoi_tam, "%[^,], %[^\n]", sv_tam.ma, sv_tam.ten);
            printf("%5s %20s", sv_tam.ma, sv_tam.ten);
            getch();
            Node *new_node = GetNode(sv_tam);
            AddTail(l, new_node);
        }
    }
    fclose(f);
}

void print_student_info(List list_bac, List list_he, List list_nganh, List list_khoa, const char *mssv)
{
    char bac[2], he[2], nganh[3], khoa[3], id[4];
    strncpy(bac, mssv, 1);
    bac[1] = '\0';
    strncpy(he, mssv + 1, 1);
    he[1] = '\0';
    strncpy(nganh, mssv + 2, 2);
    nganh[2] = '\0';
    strncpy(khoa, mssv + 4, 2);
    khoa[2] = '\0';
    strncpy(id, mssv + 6, 3);
    id[3] = '\0';

    char *ten_bac = Find(list_bac, bac);
    char *ten_he = Find(list_he, he);
    char *ten_nganh = Find(list_nganh, nganh);
    char *ten_khoa = Find(list_khoa, khoa);

    // if (ten_bac && ten_he && ten_nganh && ten_khoa)
    //{
    printf("Sinh vien %s:\n", mssv);
    printf("- Bac dao tao: %s\n", ten_bac);
    printf("- He dao tao: %s\n", ten_he);
    printf("- Nganh: %s\n", ten_nganh);
    printf("- Khoa: %s\n", ten_khoa);
    printf("- Nam nhap hoc: %s\n", id);
    //}
    // else
    //{
    //    printf("Khong tim thay thong tin sinh vien %s\n", mssv);
    //}
}

int main()
{
    List list_bac, list_he, list_khoa, list_nganh;
    Init(list_bac);
    Init(list_he);
    Init(list_khoa);
    Init(list_nganh);
    load_data("bac.txt", list_bac);
    load_data("he.txt", list_he);
    load_data("khoa.txt", list_khoa);
    load_data("nganh.txt", list_nganh);

    printf("Danh sach bac dao tao:\n");
    PrintList(list_bac);
    printf("\nDanh sach he dao tao:\n");
    PrintList(list_he);
    printf("\nDanh sach khoa:\n");
    PrintList(list_khoa);
    printf("\nDanh sach nganh:\n");
    PrintList(list_nganh);

    char mssv[10];
    printf("Nhap MSSV: ");
    scanf("%s", mssv);
    print_student_info(list_bac, list_he, list_nganh, list_khoa, mssv);

    return 0;
}
