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
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
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

void ThemNotCuoi(DaThuc &l)
{
    DonThuc my_donthuc;
    Node *p;
    int n, i;

    printf("Nhap so bac cua da thuc:");
    scanf("%d", &n);
    for (i = n; i >= 0; i--)
    {
        printf("X^%d : ", i);
        scanf("%d", &my_donthuc.heso);

        my_donthuc.bac = i;

        Node *new_ele = GetNode(my_donthuc);

        AddTail(l, new_ele);
    }
}

void PrintDaThuc(DaThuc l)
{
    printf("\n");
    Node *p = l.pHead;
    while (p != NULL)
	{
        if ((p != l.pHead) && (p->Info.heso > 0))
            printf("+");
        if ((p != l.pTail) && (p->pNext != l.pTail))
        {
            if (p->Info.heso != 1 && p->Info.heso != -1)
                printf("%dx^%d", p->Info.heso, p->Info.bac);
            else if (p->Info.heso == 1)
                printf("x^%d", p->Info.bac);
            else if (p->Info.heso == -1)
                printf("-x^%d", p->Info.bac);
        }
        //  printf(" %d^%d ", p->Info.heso, p->Info.bac);
        else if (p->pNext == l.pTail)
        {
            if (p->Info.heso != 1 && p->Info.heso != -1)
                printf("%dx^%d", p->Info.heso, p->Info.bac);
            else if (p->Info.heso == 1)
                printf("x^%d", p->Info.bac);
            else if (p->Info.heso == -1)
                printf("-x^%d", p->Info.bac);
        }
        // printf(" %dx ", p->Info.heso);
        else if (p == l.pTail)
            printf(" %d ", p->Info.heso);

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
    PrintDaThuc(my_dathuc);
    printf("\nDa thuc 2:");
    PrintDaThuc(my_dathuc1);

    printf("\nDa thuc kq:");
    CongDaThuc(my_dathuc, my_dathuc1, kq);

    PrintDaThuc(kq);

    return 0;
}
