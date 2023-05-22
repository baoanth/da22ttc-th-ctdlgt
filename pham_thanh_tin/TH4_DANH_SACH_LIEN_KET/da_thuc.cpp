#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Donthuc
{
    int bac;
    int hs;

}Donthuc;

typedef struct Node
{
    Donthuc Info;
    Node *pNext;
}Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;
}Dathuc;

void Init(Dathuc &l)
{
    l.pHead = l.pTail = NULL;
}

Node *GetNode(Donthuc x)
{
    Node *p = new Node;
    if(p==NULL)
    {
        printf("Khong du bo nho de cap phat nut moi");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(Dathuc &l, Node* new_ele)
{
    if(l.pHead==NULL)
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

void NhapDaThuc(Dathuc &l)
{
    int n=0;
    int i;
    Donthuc Px;
    printf("Nhap bac cua da thuc:");
    scanf("%d", &n);

    for(i=n; i>=0; i--)
    {
        printf("x^%d *", i);
        Px.bac = i;
        scanf(" %d", &Px.hs);

        Node *new_ele = GetNode(Px);
        AddTail(l, new_ele);
    }
}

void XuatDaThuc(Dathuc &l)
{
    Node *p = l.pHead;
     printf("da thuc vua nhap :\n");
    printf("\n  P(x) = ");

    while (p != NULL)
    {
        if ((p->Info.hs > 0) && (p != l.pHead))
            printf(" + ");

        if (p->Info.bac == 0)
            printf("%d", p->Info.hs);
        else
            printf("%dx^%d", p->Info.hs, p->Info.bac);

        p = p->pNext;
    }
}

int main()
{
    Dathuc my_Px1;
    Init(my_Px1);

    NhapDaThuc(my_Px1);

    XuatDaThuc(my_Px1);

    return 0;
}
