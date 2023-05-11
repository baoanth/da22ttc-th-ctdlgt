#include <stdio.h>

typedef struct Person
{
	int id;
	char fname;
	char lname;
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

Node* Get_Node(Person x)
{
	Node *p;
	p = new Node;
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	p->Info=x;
	p->pNext=NULL;
	return p;
}

//new_ele = Get_Node(x);

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void Add_First(List &l, Node* new_ele)
{
	if(l.pHead=NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		new_ele->pNext=l.pHead;
		l.pHead=new_ele;
	}
}

void Print_List(List l)
{
	
}
/*
void Add_Tail(List &l, Node* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail=new_ele;
	}
}

void Add_After(List &l, Node *q, Node *new_ele)
{
	if(q!=NULL && new_ele!=NULL)
	{
		new_ele->pNext=q->pNext;
		q->pNext=new_ele;
		if(q==l.pTail)
			l.pTail=new_ele;
	}
	else
	{
		Add_First(l, new_ele);
	}
}

void Input_Tail(List &l)
{
	int n;
	Person x;
	
}
*/
int main()
{
/*	Person per1 = {1, "Nguyen", "Vinh"};
	Person per2 = {2, "Le", "Huy"};
	Person per3 = {3, "Tran", "Ngoc"};*/
	
}

