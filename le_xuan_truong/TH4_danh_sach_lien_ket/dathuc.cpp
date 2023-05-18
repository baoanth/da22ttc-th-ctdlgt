#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int hs;
    int bac;
}Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node* pNext;
}Node;

typedef struct Dathuc
{
	Node* pHead;
	Node* pTail;
}Dathuc;

Node* GetNode(Donthuc x)
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

void NhapDathuc(Dathuc &l)
{
	int MaxN= 0;
	int i;
	Donthuc s;
	
	printf("\nPT co bac: ");
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

void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintDathuc(Dathuc &l)
{
	Node *p;
	p = l.pHead;
	
	printf("\nP(x)= ");
	
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

Dathuc CongDathuc(Dathuc &l1, Dathuc &l2)
{
	Node *p, *q;
	
	Dathuc l_kq;
	Init(l_kq);
	
	Donthuc t;
	p= l1.pHead;
	q= l2.pHead;
	
	while(q!= NULL)
	{
		t.hs= p->Info.hs;
		t.bac= p->Info.bac;
		
		while(q!= NULL)
		{
			if(p->Info.bac == q->Info.bac)
			break;
			q= q-> pNext;
		}
		if(q!= NULL)
			t.hs += q->Info.hs;
			
		Node* new_ele= GetNode(t);
		AddTail(l_kq, new_ele);
		p->pNext;
	}
	return l_kq;
}

int main()
{
	Dathuc my_dathuc1;
	Init(my_dathuc1);
	Dathuc my_dathuc2;
	Init(my_dathuc2);
	Dathuc my_dathuc3;
	
	printf("\nNhap da thuc 1: ");		
	NhapDathuc(my_dathuc1);		   
	PrintDathuc(my_dathuc1);
	
	printf("\n");
	
	printf("\nNhap da thuc 2: ");	
	NhapDathuc(my_dathuc2);		   
	PrintDathuc(my_dathuc2);
	
	my_dathuc3= CongDathuc(my_dathuc1, my_dathuc2);
	PrintDathuc(my_dathuc3);
	
    return 0;
}
