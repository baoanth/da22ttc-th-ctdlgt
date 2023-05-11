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
	p= new Node;
	if (p==NULL)
	{
		printf(" ko du bo nho co the cap phat cho nat moi");
		return NULL;
	}
	p->Info = x;
	p->pNext = NULL;
	return p; 
}

void AddFist(List &l, Node* new_ele)
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
	l. pHead = l.pTail = NULL;
}
int main()
{
	struct Person per1 = {1, "yen", "nguyen" };
	struct Person per2 = {2, "hong", "tran" };
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	List my_list;
	Init(my_list);
	
	AddFist(my_list, new_ele1);
	AddFist(my_list, new_ele2);
}

