#include <stdio.h>
#include <string.h>

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

void load_data(char *filename, List &l)
{
    FILE *f = fopen(filename, "r");
    TTSV sv_tam;
    char chuoi_tam[100];
    char *tach_chuoi;
    if (filename == NULL)
    {
        printf("Khong tim thay file");
        return;
    }
    else
    {
        while (!feof(f))
        {
            fgets(chuoi_tam, sizeof(chuoi_tam), f);
            if (chuoi_tam != NULL)
            {
                tach_chuoi = strtok(chuoi_tam, ",");
                strcpy(sv_tam.ma, tach_chuoi);
                if (chuoi_tam != NULL)
                {
                    tach_chuoi = strtok(NULL, ",");
                    strcpy(sv_tam.ten, tach_chuoi);
                }
            }
            Node *new_node = GetNode(sv_tam);
            AddTail(l, new_node);
        }
    }
}

int main()
{
    List list_bac;
    Init(list_bac);
    load_data("bac.txt", list_bac);
    PrintList(list_bac);
    return 0;
}