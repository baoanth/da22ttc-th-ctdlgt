#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Node
{
	DonThuc Info;
	Node* pNext;
}Node;

typedef struct Stack
{
	Node* pHead;
	Node* pTail;
}Stack;

Node* Get_Node(Stack x)
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

void Add_First(Stack &s, Node* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
    
	}
}

void Init(DaThuc &l)
{
	l.pHead = l.pTail = NULL;
}



char IsEmpty(LIST &S)
{
	if(Q.pHead==NULL)
		return 1;
	else return 0;
}

void Push(LIST &S, char x)
{
	
}



int main()
{
	
}
