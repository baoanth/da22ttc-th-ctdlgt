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
        printf("Khong du bo nho de cap phat. ");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFirst(List &l, Node* new_ele)
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

Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p = l.pHead;
	while((p!=NULL) && (p->Info != idx))
	p = p->pNext;
	
	return p;
} 



void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintList(List l)
{
	if (l.pHead == NULL)
	{
		printf("Trong rong.");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while(p!=NULL)
		{
			printf("%5d %20s %10s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}
	}
}

int main()
{
    struct Person per1 = {1, "An", "Nguyen" };
	struct Person per2 = {2, "Vinh", "Pham" };
	struct Person per3 = {3, "Vinh", "Nguyen" };
	struct Person per4 = {4, "Tong", "Nguyen" };

    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    Node* new_ele4  = GetNode(per4);
    
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
    AddFirst(my_list, new_ele4);
    
    PrintList(my_list);
    
    printf("Nhap id can tim: ");
    scanf("%d", &idx);
    
    Node *Node_kq = Node* FindNodeByID(my_list, idx);
    
    return 0;
}