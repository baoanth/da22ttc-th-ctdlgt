#include <stdio.h>
#include <conio.h>
#include <string.h>

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
        printf("Khong du bo nho de cap phat");
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

void PrintList(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%2d%10s%15s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}		
	}
}



int main()
{
    struct Person per1 = {1, "Vinh", "Pham"};
	struct Person per2 = {2, "An", "Nguyen"};
	struct Person per3 = {3, "Tong", "Nguyen"};
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);

    PrintList(my_list);

    return 0;
}
