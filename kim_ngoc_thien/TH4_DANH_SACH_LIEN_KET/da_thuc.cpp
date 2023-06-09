#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
            printf("%d", p->Info.heso);
        else if (p->Info.bac == 1)
            printf("%dx", p->Info.heso);
        else
        {
            printf("%dx^%d", p->Info.heso, p->Info.bac);
        }
        p = p->pNext;
    }
}

void CopyDaThuc(dathuc l, dathuc &l_kq)
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

Node *TimNodeBacN(dathuc l, int n)
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

void congdathuc(dathuc l1, dathuc l2, dathuc &l_kq)
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
            Node *tmp = GetNode(p->Info);
            AddTail(l_kq, tmp);
        }
        p = p->pNext;
    }
}

float tinh(dathuc l, int x)
{
    float kq = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        kq += p->Info.heso * pow(x, p->Info.bac);
        p = p->pNext;
    }
    return kq;
}

void gopcungbac(dathuc l)
{
    Node *p = l.pHead;
    Node *q = l.pHead->pNext;
    while (p->pNext != NULL)
    {
        while (q != NULL)
        {
            if (p->Info.bac = q->Info.bac)
                p->Info.heso += q->Info.heso;
            q = q->pNext;
        }
        p = p->pNext;
    }
}

void nhandathuc(dathuc l1, dathuc l2, dathuc &kq)
{
    Init(kq);
    donthuc tmp;
    Node *p = l1.pHead;
    Node *q = l2.pHead;
   
    while (p != NULL)
    {
    	tmp.bac =  p->Info.bac;
    	tmp.heso =  p->Info.heso;
        while (q != NULL)
        {
        	donthuc i;
            i.bac = tmp.bac + q->Info.bac;
            i.heso = tmp.heso * q->Info.heso;
            Node *x = GetNode(i);
            AddTail(kq, x);
            q = q->pNext;
        }
        p = p->pNext;
    }
    // gopcungbac(kq);
}

int main()
{

    dathuc dathuc1, kq;
    dathuc dathuc2;
    Init(dathuc1);
    Init(dathuc2);
    nhapdathuc(dathuc1);
    nhapdathuc(dathuc2);
    // congdathuc(dathuc1, dathuc2, kq);
    // print(dathuc2);
    // int x;
    // printf("\nnhap vao gia tri ");
    // scanf("%f", &x);

    // float kq = tinh(dathuc2, x);
    nhandathuc(dathuc1, dathuc2, kq);
    // printf("%.2f", kq);
    print(kq);
    return 0;
}
