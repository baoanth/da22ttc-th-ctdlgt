#include <stdio.h> 
#include <stdlib.h> 
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
		exit(1);
	}
	p->Info = x;
	p->pNext = NULL;
	return p;
}

void AddFirst(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
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

int main()
{
	struct Person per1 = {1, "Vy" , "Hua" };
	struct Person per2 = {2, "Truong" , "Nguyen" };
	struct Person per3 = {3, "Hoi" , "Nguyen" };
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	
	List mylist;
	Init(mylist);
	
	AddFirst(mylist, new_ele1);
	AddFirst(mylist, new_ele2);
	AddFirst(mylist, new_ele3);
	
}
