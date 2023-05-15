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


int main()
{
    struct Person per1 = {1, "Nguyen", "Le" };
	struct Person per2 = {2, "Duy", "Quang" };
	struct Person per3 = {3, "Pham", "Vinh" };
    
    List my_list;
    Init(my_list);

    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);


    PrintList(my_list);
    return 0;
}



