#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;

typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;

    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;

    return p;
}

void AddFist(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
}

void AddTail(List &l, Node *new_ele)
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

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintList(List &l)
{
    if (l.pHead == NULL)
    {
        printf("Danh sach rong");
    }
    else
    {
        Node *p;
        p = l.pHead;
        while (p != NULL)
        {
            printf("%2d%10s%15s\n", p->Info.id, p->Info.fname, p->Info.lname);
            p = p->pNext;
        }
    }
}

void PrintNode(Node *p)
{
    printf("%2d%10s%15s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

Node *FindNodeByID(List l, int idx)
{
    Node *p;
    p = l.pHead;
    while ((p != NULL) && (p->Info.id != idx))
        p = p->pNext;
    return p;
}

/*
Person RemoveHead(List &l)
{
    Node *p;
    Person x;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        x = p->person;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return x;
}

void RemoveAfter(List &l, Node *q)
{
    NODE *p;
    if (q != NULL)
    {
        p = q->pNext;
        if (p != NULL)
        {
            if (p == l.pTail)
                l.pTail = q;
            q->pNext = p->pNext;
            delete p;
        }
    }
    else
        RemoveHead(l);
}

int RemoveNode(List &l, int idx)
{
    Node *p = l.pHead;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->Info == k)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == l.pTail)
            l.pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;
}
*/

int main()
{
    struct Person per1 = {1, "Vinh", "Pham"};
    struct Person per2 = {2, "An", "Nguyen"};
    struct Person per3 = {3, "Tong", "Nguyen"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);

    List my_list;
    Init(my_list);

//  AddFist(my_list, new_ele1);
//  AddFist(my_list, new_ele2);
//  AddFist(my_list, new_ele3);

    AddTail(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);

    PrintList(my_list);

    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);

    Node *Node_kq = FindNodeByID(my_list, idx);

    if (Node_kq != NULL)
        PrintNode(Node_kq);
    else
        printf("Khong tim thay ID %d", idx);

//  RemoveHead(my_list);
//  RemoveAfter(my_list, q);
//  RemoveNode(my_list, idx);

    return 0;
}
