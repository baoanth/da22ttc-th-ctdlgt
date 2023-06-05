#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Donthuc
{
    int heso, bac;
} donthuc;

typedef struct Node
{
    donthuc info;
    Node* pNext;
} Node;

typedef struct Dathuc
{
    Node* pHead;
    Node* pTail;
} dathuc;

void Init(dathuc& l)
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode(donthuc x)
{
    Node* p = new Node;
    if (p == NULL)
    {
        printf("khong du bo nho ");
        return NULL;
    }

    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(dathuc& l, Node* new_ele)
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
        new_ele->pNext = NULL;
    }
}

void Nhapdathuc(dathuc& l)
{
    int n = 0;
    int i;
    donthuc Px;

    printf("da thuc co bac : ");
    scanf("%d", &n);

    for (i = n; i >= 0; i--)
    {
        printf("x^%d  ", i);
        Px.bac = i;
        scanf("%d", &Px.heso);

        Node* new_ele = GetNode(Px);
        AddTail(l, new_ele);
    }
}

void Xuatdathuc(dathuc& l)
{
    Node* p = l.pHead;

    printf("da thuc vua nhap :\n");
    printf("\n  P(x) = ");

    while (p != NULL)
    {
        if ((p->info.heso > 0) && (p != l.pHead))
            printf(" + ");

        if (p->info.bac == 0)
            printf(" %d", p->info.heso);
        else
            printf("%dx^%d", p->info.heso, p->info.bac);

        p = p->pNext;
    }
}

int main()
{
    dathuc my_Px1;
    dathuc my_Px2;

    Init(my_Px1);

    Nhapdathuc(my_Px1);

    Xuatdathuc(my_Px1);

    return 0;
}

