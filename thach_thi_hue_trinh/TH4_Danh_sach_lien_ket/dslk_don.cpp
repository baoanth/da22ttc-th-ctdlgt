#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int id;
    char fname[20];
    char lname[20];
}person;

typedef struct Node
{
	person Info;
	Node* pNext;
}Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
}List;

Node* GetNode(person x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho !"); 
		return NULL; 
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
		l.pTail  = l.pHead;
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

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%3d | %10s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

int main()
{
	struct person per1 = { 3, "Naruto" , "Uzumaki" };
	struct person per2 = { 2, "Hinata" , "Uzumaki" };
	struct person per3 = { 1, "Boruto" , "Uzumaki" };

	Node*new_ele1= GetNode(per1);
	Node*new_ele2= GetNode(per2);
	Node*new_ele3= GetNode(per3);
	
	List my_list;
	Init (my_list);

	AddFirst(my_list,new_ele1);
	AddFirst(my_list,new_ele2);
	AddFirst(my_list,new_ele3);
	
	PrintList(my_list) ;

return 0;
}