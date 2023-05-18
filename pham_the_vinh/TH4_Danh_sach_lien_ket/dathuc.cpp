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
        printf("Khong du bo nho de cap phat");
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
    int bacmax = 0;

    printf("\nNhap bac cua da thuc: ");
    scanf("%d", &bacmax);
    printf("\n");

    DonThuc s;
    int i;

    for (i = bacmax; i >= 0; i--)
    {
        printf(" x^%d. Nhap he so:", i);
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
        printf(" Rong");
    }
    else
    {
        Node *p = l.pHead;

        while (p != NULL)
        {
            if (p != l.pHead && p->Info.heso > 0)
                printf(" + ");

            if (p->Info.bac == 0)
                printf("%d", p->Info.heso);
            else if (p->Info.bac == 1)
                printf("%dx", p->Info.heso);
            else
                printf(" %dx^%d", p->Info.heso, p->Info.bac);

            p = p->pNext;
        }
    }
}

DaThuc CongDaThuc(DaThuc &l1, DaThuc &l2)
{
    Node *p, *q;
    DaThuc kq;
    DonThuc dathuc_tam;
    p = l1.pHead;
    q = l2.pHead;

    while (p != NULL)
    {
        dathuc_tam.heso = p->Info.heso;
        dathuc_tam.bac = p->Info.bac;

        while (q != NULL)
        {
            if (p->Info.bac == q->Info.bac)
                break;
            q = q->pNext;
        }
        if (q != NULL)
            dathuc_tam.heso += q->Info.heso;

        Node *new_ele = GetNode(dathuc_tam);
        AddTail(kq, new_ele);
        p->pNext;
    }
    return kq;
}

int main()
{
    DaThuc dathuc1, dathuc2, sum_dathuc;
    Init(dathuc1);
    Init(dathuc2);

    NhapDaThuc(dathuc1);
    NhapDaThuc(dathuc2);

    printf("\n Da thuc vua nhap:\n");
    InDaThuc(dathuc1);
    printf("\n");
    InDaThuc(dathuc2);

    sum_dathuc = CongDaThuc(dathuc1, dathuc2);
	//    InDaThuc(sum_dathuc);
    return 0;
}
