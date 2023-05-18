#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int heso;
    int bac;
} DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node *pNext;
} Node;

typedef struct DaThuc
{
    Node *pHead;
    Node *pTail;
} DaThuc;

Node *GetNode(DonThuc x)
{
    Node *p = new Node;

    if (p == NULL)
    {
        printf("404 ");
        return 0;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

void Init(DaThuc &l)
{
    l.pHead = l.pTail = NULL;
}

void AddTail(DaThuc &l, Node *new_ele)
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

void NhapDaThuc(DaThuc &l)
{
    int n = 0;
    printf("Da thuc bac: ");
    scanf("%d", &n);

    int i;
    DonThuc s;

    for (i = n; i >= 0; i--)
    {
        printf("x^%d. Nhap so:", i);
        s.bac = i;
        scanf("%d", &s.heso);

        Node *new_ele = GetNode(s);
        AddTail(l, new_ele);
    }
}

void InDaThuc(DaThuc &l)
{
    if (l.pHead == NULL)
    {
        printf("Trong rong");
    }
    else
    {
        Node *p = l.pHead;

        while (p != NULL)
        {
            if ((p != l.pHead) && (p->Info.heso > 0))
            printf("+");
            printf("%dx^%d", p->Info.heso, p->Info.bac);
            p = p->pNext;
        }
    }
}

int main()
{
    DaThuc my_dathuc;
    Init(my_dathuc);

    NhapDaThuc(my_dathuc);

    printf("Da thuc vua nhap: ");
    InDaThuc(my_dathuc);

    return 0;
}
