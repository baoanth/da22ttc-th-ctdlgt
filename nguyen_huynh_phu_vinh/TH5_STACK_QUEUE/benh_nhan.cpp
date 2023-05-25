#include <stdio.h>
#include <string.h>

typedef struct Person
{
    char ho_ten[50];
    int tuoi;
    char dia_chi[100];
    char tinh_trang_benh[100];
} Person;

typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;

void Init(Queue &l)
{
    l.pHead = l.pTail = NULL;
}

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
        return NULL;
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

void RemoveHead(Queue &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail == NULL;
        delete p;
    }
}

Person RemoveFirst(Queue &l, Person x)
{
    Node*p = l.pHead;
    x = p->Info;
    RemoveHead(l);
    return x;
}

void EnQueue(Queue &l, Person x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

void in_dslk(Queue l)
{
    Node* p = l.pHead;
    while(p!=NULL)
    {
        printf("\n%10s%10d%10s%10s", p->Info.ho_ten, p->Info.tuoi, p->Info.dia_chi, p->Info.tinh_trang_benh);
        p = p->pNext;
    }
}
int main()
{
    Queue my_queue;
    Init(my_queue);
    Person per1 = {"Vinh", 19, "Cau Ke", "Khoe"};
    Person per2 = {"Tri", 19, "Tra Vinh", "Tot"};
    
    EnQueue(my_queue, per1);
    EnQueue(my_queue, per2);
    in_dslk(my_queue);

    return 0;
}