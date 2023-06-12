#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_LINE_LENGTH 100

typedef struct MssvEle
{
    char ma[3];
    char ten[MAX_LINE_LENGTH];
} MssvEle;

typedef struct Node
{
    MssvEle Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(MssvEle x)
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

void AddFirst(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;      
    }
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
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

char *Find(List l, char *ma)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (strcmp(p->Info.ma, ma) == 0)
        {
            return p->Info.ten;
        }
        p = p->pNext;
    }
    return NULL;
}

int load_data(const char* filename, List &l )
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    MssvEle ele_tam;
    Node* node_tam;

    // M? t?p van b?n d? d?c
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không th? m? t?p van b?n.\n");
        return 1;
    }

    // Ð?c t?ng dòng trong t?p van b?n
    while (fgets(line, sizeof(line), file)) {
        // Lo?i b? ký t? newline
        line[strcspn(line, "\n")] = '\0';       

        // Phân tách dòng thành hai chu?i b?ng d?u ph?y
        token = strtok(line, ",");
        
        if (token != NULL) {
            strcpy(ele_tam.ma, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(ele_tam.ten, token);

                // In ra các bi?n "ma" và "ten"
                //printf("Ma: %s\n", ele_tam.ma);
                //printf("Ten: %s\n", ele_tam.ten);
            }            
        }
        node_tam  = GetNode(ele_tam);
        AddTail(l, node_tam);
    }

    // Ðóng t?p van b?n
    fclose(file);    
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
