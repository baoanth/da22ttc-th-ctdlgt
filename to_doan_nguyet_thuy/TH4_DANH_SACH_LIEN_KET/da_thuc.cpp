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

void CopyDaThuc( dathuc l, dathuc &l_kq)
{
    Node* p;
    p = l.pHead;
    while( p!=NULL)
    {
        Node* new_ele = GetNode(p ->info);
        AddTail(l_kq, new_ele);
        p = p->pNext;

    }
    printf("Da copy da thuc:\n");
}
Node* TimBacN(dathuc l, int n)
{
    Node* p;
    p = l.pHead;
    while(p != NULL)
    {
        if(p->info.bac==n) 
            break;
        p= p-> pNext;

    }
    return p;

}

void CongDaThuc(dathuc l1, dathuc l2, dathuc&l_kq)
{
    CopyDaThuc(l1, l_kq);

    Node* p;
    p = l2.pHead;

    while(p != NULL)
    {
        Node* foundNode = TimBacN(l_kq, p->info.bac);
        if(foundNode = NULL)
        {
            foundNode->info.heso += p->info.heso;
            printf("found bac %d \n", p->info.bac);

        }
        else
        {
            Node* node_tam = GetNode(p ->info);
            AddTail(l_kq, node_tam);

        }
        p= p->pNext;

    }
}

int main()
{
    dathuc my_Px1;
    dathuc my_Px2;
	dathuc my_Px3;
	
    Init(my_Px1);
    Init(my_Px2);
	Init(my_Px3);
	
    printf("Nhap da thuc 1:\n");
    Nhapdathuc(my_Px1);
    Xuatdathuc(my_Px1);
    printf("\n");

    printf("Nhap da thuc 2:\n");
    Nhapdathuc(my_Px2);
    Xuatdathuc(my_Px2);

    printf("\n Cong hai da thuc :\n");
    CongDaThuc(my_Px1, my_Px2, my_Px3);
    Xuatdathuc(my_Px3);

    return 0;
}
