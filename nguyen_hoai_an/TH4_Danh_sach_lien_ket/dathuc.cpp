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
        printf("Khong du bo nho.");
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

    printf("Nhap bac da thuc: ");
    scanf("%d", &bacmax);

    DonThuc s;
    int i;

    for(i = bacmax; i >= 0; i--)
    {
        printf("Nhap he so x^%d:", i);
        s.bac = i;
        scanf("%d", &s.heso);
        Node *new_ele = GetNode(s);
        AddTail(l, new_ele);
    }
}

void InDaThuc(DaThuc &l)
{
    if(l.pHead == NULL)
    {
        printf("Trong rong");
    }
    else
    {
        Node *p = l.pHead;

        while(p != NULL)
        {
            if (p != l.pHead && p->Info.heso > 0)
                printf(" + ");
            if (p->Info.bac == 0)
                printf("%d", p->Info.heso);
            else if (p->Info.bac == 1)
                printf("%dx", p->Info.heso);
            else
                printf("%dx^%d", p->Info.heso, p->Info.bac);

            p = p->pNext;
        }
    }
}

DaThuc CongDaThuc(DaThuc &l1, DaThuc &l2)
{
    Node *p = l1.pHead;
    Node *q = l2.pHead;
    
    DaThuc KetQua;
    Init(KetQua);
    DonThuc DaThucTam;

    while(p!= NULL)
    {
        DaThucTam.bac = p->Info.bac;
        DaThucTam.heso = p->Info.heso;

        while(q!= NULL)
        {
            if (DaThucTam.bac == q->Info.bac)
                break;
            q = q->pNext;
        }
        if(q!= NULL)
            DaThucTam.heso += q->Info.heso;

        Node *new_ele = GetNode(DaThucTam);
        AddTail(KetQua, new_ele);
        p = p->pNext;
    }
    return KetQua;
}

int main()
{
    DaThuc DaThuc1, DaThuc2, KetQua;
    Init(DaThuc1);
    Init(DaThuc2);

    NhapDaThuc(DaThuc1);
    NhapDaThuc(DaThuc2);

    printf("Da thuc vua nhap:\n");
    InDaThuc(DaThuc1);
    printf(" \n");
    InDaThuc(DaThuc2);

    KetQua = CongDaThuc(DaThuc1, DaThuc2);
    printf("\nKet qua = ");
    InDaThuc(KetQua);
    
    return 0;
}
