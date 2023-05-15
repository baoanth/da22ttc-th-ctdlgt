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
Node* pNext; 
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
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void AddFirst(List &l, Node * new_ele)
{
if (l.pHead==NULL) 
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
void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}
int main()
{
    struct Person per1 = {1, "Dang", "Phuoc"};
    struct Person per2 = {2, "Tran", "Tho"};
    struct Person per3 = {3, "Chau", "Qui"};
    Node *new_ele0 = GetNode(per1);
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    
    PrintList(my_list);

  

    return 0;
}
