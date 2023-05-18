#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int heso, bac;
} donthuc;

typedef struct Node
{
    donthuc Info;
    Node *pNext;
} Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;
} dathuc;

Node *GetNode(donthuc x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho !");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void Init(dathuc &l)
{
    l.pHead = l.pTail = NULL;
}

void AddTail(dathuc &l, Node *new_ele)
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

void nhapdathuc(dathuc &l)
{
    int tmp;
    printf("nhap vao bac da thuc ");
    scanf("%d", &tmp);
    donthuc x;
    for (int i = tmp; i >= 0; i--)
    {
        printf("He so cua x^%d = ", i);
        scanf("%d", &x.heso);
        x.bac = i;

        Node *p = GetNode(x);

        AddTail(l, p);
    }
}

void print(dathuc l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p != l.pHead && p->Info.heso > 0)
            printf("+");
        if (p->Info.bac == 0)
            printf("%dx", p->Info.heso);
        printf("%dx^%d", p->Info.heso, p->Info.bac);
        p = p->pNext;
    }
}

int main()
{

    dathuc my_dathuc;
    Init(my_dathuc);

    nhapdathuc(my_dathuc);
    print(my_dathuc);
    return 0;
}
