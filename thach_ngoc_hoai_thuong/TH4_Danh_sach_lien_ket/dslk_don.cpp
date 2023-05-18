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
void PrintList(List l)
{
    Node* ptr = l.pHead;
    while (ptr != NULL)
    {
        printf("%d %s %s\n", ptr->Info.id, ptr->Info.fname, ptr->Info.lname);
        ptr = ptr->pNext;
    }
}
void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
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
Node *FindNodeById(List l, int idx)
{
    Node *p = l.pHead;
    while (p != NULL && p->Info.id != idx)
        p = p->pNext;
    return p;
}
void AddNodeAfter(List &l, int idx, Person new_info)
{
    Node *prev_node = FindNodeById(l, idx);
    if (prev_node == NULL) 
	{
        printf("Khong tim thay nut co ID = %d\n", idx);
        return;
    }

    Node *new_node = GetNode(new_info);
    new_node->pNext = prev_node->pNext;
    prev_node->pNext = new_node;

    if (l.pTail == prev_node) 
	{
        l.pTail = new_node;
    }
}          
int main()
{
    struct Person per1 = {1, "Gia", "Lac" };
	struct Person per2 = {2, "Hoai", "Thuong" };
	struct Person per3 = {3, "Pham", "Vinh" };
    
    Node *new_ele0 = GetNode(per1);
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddFist(my_list, new_ele3);
    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    Node *tim_kiem = FindNodeById(my_list, idx);
    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay nut co id %d", idx);
    return 0;
}