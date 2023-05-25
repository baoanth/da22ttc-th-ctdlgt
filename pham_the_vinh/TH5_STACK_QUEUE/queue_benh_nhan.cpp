#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct BenhNhan
{
    int stt;
    int tuoi;
    char hoten[10];
    char diachi[20];
    char tinhtrang[20];

} BenhNhan;

typedef struct Node
{
    BenhNhan Info;
    Node *pNext;
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;

Node *GetNode(BenhNhan x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("---Khong du bo nho de cap phat---");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(Queue &Q, Node *new_ele)
{
    if (Q.pHead == NULL)
    {
        Q.pHead = new_ele;
        Q.pTail = Q.pHead;
    }
    else
    {
        Q.pTail->pNext = new_ele;
        Q.pTail = new_ele;
    }
}

void RemoveHead(Queue &Q)
{
    Node *p;
    if (Q.pHead != NULL)
    {
        p = Q.pHead;
        Q.pHead = Q.pHead->pNext;
        delete p;
        if (Q.pHead == NULL)
            Q.pTail = NULL;
    }
}

void Init(Queue &Q)
{
    Q.pHead = Q.pTail = NULL;
}

char IsEmpty(Queue &Q)
{
    if (Q.pHead == NULL)
        return 1;
    else
        return 0;
}

void EnQueue(Queue &Q)
{
    BenhNhan x;
    printf("\nNhap so thu tu: ");
    scanf("%d", &x.stt);
    fflush(stdin);
    printf("\nNhap ten: ");
    gets(x.hoten);
    fflush(stdin);
    printf("\nNhap tuoi: ");
    scanf("%d", &x.tuoi);
    fflush(stdin);
    printf("\nNhap dia chi: ");
    gets(x.diachi);
    fflush(stdin);
    printf("\nnhap tinh trang benh: ");
    gets(x.tinhtrang);
    Node *p = GetNode(x);
    AddTail(s, p);
}

void Print(Queue Q)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %d %s %s",p->Info.stt p->Info.hoten, p->Info.tuoi, p->Info.diachi, p->Info.tinhtrang);
       
        p = p->pNext;
    }
}

char DeQueue(Queue &Q)
{
    char x;
    if (IsEmpty(Q))
        return NULL;
    x = Q.pHead->Info;
    RemoveHead(Q);
    return x;
}

char Front(Queue &Q)
{
    if (IsEmpty(Q))
        return NULL;
    return Q.pHead->Info;
}

int main()
{
    Queue myQueue;
    Init(myQueue);
    EnQueue(myQueue);
    Print(myQueue)
    return 0;
}