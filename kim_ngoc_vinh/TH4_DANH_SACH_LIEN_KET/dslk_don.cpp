#include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
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
        printf("Khong du bo nho de cap phat nut");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFirst(List &l, Node* new_ele)
{
    if(l.pHead == NULL)
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

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}


int main()
{
    struct Person per1 = {1, "Nguyen", "Vinh"};
    struct Person per2 = {2, "Tran", "Hung"};
    struct Person per3 = {3, "Pho", "Ngoc"};
    
    
    List* my_list;
    Init(&my_list);
    return 0;
}
