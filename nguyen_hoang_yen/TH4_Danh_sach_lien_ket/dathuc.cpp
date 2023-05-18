#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int hs;
    int bac;
} Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node* pNext;
} Node;

typedef struct Dathuc
{
	Node* pHead;
	Node* pTail;
} Dathuc;

Node* GetNode(Donthuc x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Ko du bo nho !"); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void AddTail(Dathuc &l, Node *new_ele)
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

void Nhapdathuc(Dathuc &l)
{
	int MaxN= 0;
	int i;
	Donthuc s;
	
	printf("Pt co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac= i;
		scanf("%d", &s.hs);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

Dathuc congdathuc(my_dathuc, dathuc &la, dathuc &lb )
{
	Node *p, *q;
	Donthuc dt-tam
	p = la -> pHead;
	q = lb -> pHead;
	while(p != NULL)
	{
		dt_tam.hs = p -> Info.hs;
		dt_tam.bac = q -> Info.bac;
		while(q != NULL)
		{
			if (p -> tam.hs = p->Info.bac) break;
			q = q -> pNext;
		}
	}
	if(q != NULL)
    	dt_tam.hs += q -> Info.hs;
    Node new_ele = GetNode(dt_tam);
}







void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

void Printdathuc(Dathuc &l)
{
	Node *p;
	p = l.pHead;
	
	printf("\nDa thuc vua nhap =  ");
	
	while (p!= NULL)
	{
		if((p->Info.hs>0)&&(p!=l.pHead))
			printf("+");
		if(p->Info.bac==0)
			printf("%d",p->Info.hs);
		else
			printf("%dx^%d",p->Info.hs, p->Info.bac);
		p = p->pNext;
	}
}

int main()
{
	Dathuc my_dathuc;
	Init(my_dathuc);
		
	Nhapdathuc(my_dathuc);
		   
	Printdathuc(my_dathuc);
	    
    return 0;
}

