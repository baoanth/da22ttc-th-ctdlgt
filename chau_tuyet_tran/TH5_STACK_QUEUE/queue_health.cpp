#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct BenhNhan
{
	int number;
    char name[20];
    int age;
    char address[50];
    char condition[20];
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
        printf("KHONG DU BO NHO!!!");
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
        printf("\nPatient's Name: %s", p->Info.name);
        printf("\nAge: %d", p->Info.age);
        printf("\nAddress: %s", p->Info.address);
        printf("\nHealth Conditon: %s", p->Info.condition);
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
    printf("Number : ");
    scanf("%d", &x.number);
    
    fflush(stdin);
    printf("- Enter patient name: ");
    gets(x.name);

    fflush(stdin);
    printf("- Enter age: ");
    scanf("%d", &x.age);

    fflush(stdin);
    printf("- Enter Address: ");
    gets(x.address);

    fflush(stdin);
    printf("- Enter health condition: ");
    gets(x.condition);
    
    printf ("-------------------------\n"); 
    
    Node *p = GetNode(x);
    AddTail(s, p);
}

main()
{
    int n; 
    printf("Nhap so luong benh nhan: ");
    scanf("%d",&n);

    Queue my_queve;
    Init(my_queve);
    EnQueue(my_queve);
    EnQueue(my_queve);

    print_queue(my_queve);
    DeQueue(my_queve);
    print_queue(my_queve);
    
    return 0;
}
