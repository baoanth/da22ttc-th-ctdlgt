#include <stdio.h>
#include <conio.h>
#include <string.h>

struct BenhNhan
{
    char hoten[20];
    int tuoi;
    char diachi[50];
    char tinhtrang[20];
};

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

void AddTail(Queue &l, Node *new_ele)
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
void Init(Queue &l)
{
    l.pHead = l.pTail = NULL;
}

char RemoveHead(Queue &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}
char IsEmpty(Queue &l)
{
    if (l.pHead == NULL)

        return 1;

    else
        return 0;
}

void Push(Queue &l, BenhNhan x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

void Pop(Queue &l, BenhNhan &x)
{
    if (IsEmpty(l))
        return;
    x = l.pHead->Info;
    RemoveHead(l);
}

void Top(Queue &l, BenhNhan &p)
{
    if (IsEmpty(l))
        return;
    p = l.pHead->Info;
}

void print_queue(Queue l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("\nho ten benh nhan: %s", p->Info.hoten);
        printf("\ntuoi %d", p->Info.tuoi);
        printf("\ndia chi: %s", p->Info.diachi);
        printf("\ntinh trang suc khoe: %s", p->Info.tinhtrang);
        p = p->pNext;
    }
}

void DeQueue(Queue &l)
{
    if(IsEmpty(l)) return;
    RemoveHead(l);
}
void EnQueue(Queue &s)
{
    BenhNhan x;
    fflush(stdin);
    printf("\nnhap ten benh nhan: ");
    gets(x.hoten);

    fflush(stdin);
    printf("\nnhap tuoi: ");
    scanf("%d", &x.tuoi);

    fflush(stdin);
    printf("\nnhap dia chi: ");
    gets(x.diachi);

    fflush(stdin);
    printf("\nnhap tinh trang suc khoe: ");

    gets(x.tinhtrang);
    Node *p = GetNode(x);
    AddTail(s, p);
}

main()
{

    Queue my_queve;
    Init(my_queve);
    EnQueue(my_queve);
    EnQueue(my_queve);

    print_queue(my_queve);
    DeQueue(my_queve);
    print_queue(my_queve);
    return 0;
}