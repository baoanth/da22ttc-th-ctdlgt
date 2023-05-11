#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFist(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}


void AddTail(List &l, Node *new_ele)
{
    if(l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else{
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}




void PrintList(List l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

Node* SearchList(List l, int id)
{
    Node* node = l.pHead;
    while (node != NULL)
    {
        if (node->Info.id == id)
        {
            return node;
        }
        node = node->pNext;
    }
    return NULL;
}


int main()
{
    struct Person per1 = {1, "Kim" , "Tri" };
    struct Person per2 = {2, "Thach" , "Minh" };
    struct Person per3 = {3, "Kim" , "Minh" };

    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);


    PrintList(my_list);

    Node* found_node = SearchList(my_list, 2);
    if (found_node != NULL)
    {
        printf("%d %s %s\n", found_node->Info.id, found_node->Info.fname, found_node->Info.lname);
    }
    else
    {
        printf("Node not found!\n");
    }


    return 0;
}
