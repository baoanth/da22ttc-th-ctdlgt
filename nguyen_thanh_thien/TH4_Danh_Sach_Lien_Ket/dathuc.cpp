#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int he_so;
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
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
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

void them_nut_cuoi(DaThuc &l)
{
    struct DonThuc new_don_thuc;
    int bac_da_thuc, i;
    printf("Ban muon nhap da thuc bac may?: ");
    scanf("%d", &bac_da_thuc);

    for (i = bac_da_thuc; i >= 0; i--)
    {
        printf("X^%d : ", i);
        scanf("%d", &new_don_thuc.he_so);
        new_don_thuc.bac = i;
        Node *new_ele = GetNode(new_don_thuc);
        AddTail(l, new_ele);
    }
}

void in_da_thuc(DaThuc l)
{
    printf("\n");
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p != l.pHead && p->Info.he_so > 0)
            printf("+");
        if (p != l.pTail && p->pNext != l.pTail)
            printf("%dx^%d", p->Info.he_so, p->Info.bac);
        else if (p->pNext == l.pTail)
            printf("%dx", p->Info.he_so);
        else if (p == l.pTail)
            printf("%d", p->Info.he_so);

        p = p->pNext;
    }
}

void CopyDaThuc(DaThuc l, DaThuc &l_kq)
{
    // Init(l_kq);
    Node *p = l.pHead;
    while (p != NULL)
    {
        Node *q = GetNode(p->Info);
        AddTail(l_kq, q);
        p = p->pNext;
    }
}

Node *TimNodeBacN(DaThuc l, int n)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->Info.bac == n)
        {
            break;
        }
        p = p->pNext;
    }
    return p;
}

DaThuc CongDaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)

{

    Init(l_kq);
    CopyDaThuc(l1, l_kq);
    Node *p = l2.pHead;

    while (p != NULL)
    {
        Node *fNode = TimNodeBacN(l_kq, p->Info.bac);
        if (fNode != NULL)
        {
            fNode->Info.heso += p->Info.heso;
        }
        else
        {
            Node *tam = GetNode(p->Info);
            AddTail(l_kq, tam);
        }
        p = p->pNext;
    }
}

void RutGonDaThuc(DaThuc &l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        int bac_p = p->Info.bac;
        Node *q = p->pNext;
        while (q != NULL && q->Info.bac == bac_p)
        {
            p->Info.heso += q->Info.heso;
            Node *r = q;
            q = q->pNext;
            Remove(l, r);
        }
    }
}

int main()
{
    DaThuc my_dathuc;
    DaThuc my_dathuc1, kq;
    Init(my_dathuc);
    Init(my_dathuc1);
    Init(kq);

    ThemNotCuoi(my_dathuc);
    ThemNotCuoi(my_dathuc1);

    printf("\nDa thuc 1:");
    RutGonDaThuc(my_dathuc);
    PrintDaThuc(my_dathuc);
    printf("\nDa thuc 2:");
    PrintDaThuc(my_dathuc1);

    printf("\nDa thuc kq:");
    CongDaThuc(my_dathuc, my_dathuc1, kq);

    PrintDaThuc(kq);

    return 0;
}
