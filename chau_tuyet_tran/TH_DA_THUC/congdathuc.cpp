#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int heso;
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
		printf("Not enough memory to update! "); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

void AddTail(Dathuc &l, Node *new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail= l.pHead;
	}
	else
	{
		l.pTail->pNext =new_ele;
		l.pTail=new_ele;
	}
} 

void NhapDaThuc(Dathuc &l)
{
	int maxN=0;
	printf("Enter degree of polynomial: ");
	scanf("%d",&maxN);
	int i;
	Donthuc s;
	for(i=maxN; i>=0; i--)
	{
		printf("x ^ %d = ",i);
		s.bac = i;
		scanf("%d",&s.heso);
		Node*new_ele=GetNode(s);
		AddTail(l, new_ele);
	}
}

void CopyDaThuc ( Dathuc l, Dathuc &l_kq)
{
	Node* p;
	p=l.pHead;
	
	while(p!=NULL)
	{
		Node* new_ele =GetNode(p->Info);
		AddTail(l_kq, new_ele);
		p=p->pNext;
	}
	printf("\n----------Copy successful!----------\n");
}

Node* TimNodeBacN(Dathuc l, int n)
{
	Node* p;
	p =l.pHead;
	
	while(p!=NULL)
	{
		if(p->Info.bac==n)
		break;
		p=p->pNext;
	}
	return p;
}

void CongDathuc(Dathuc l1, Dathuc l2, Dathuc &l_kq)
{
	CopyDaThuc(l1, l_kq);
	
	Node*p;
	p=l2.pHead;
	
	while(p!=NULL)
	{
		Node*FoundNode = TimNodeBacN(l_kq, p->Info.bac);
		if(FoundNode!=NULL)
		{
			FoundNode->Info.heso +=p->Info.heso;
			printf("Search degree: %d \n", p->Info.bac);
		}
		else
		{
			Node* node_tam= GetNode(p->Info);
			AddTail(l_kq,node_tam);
		}
		p=p->pNext;
	}

}

void PrintDathuc(Dathuc &l)
{ 
	printf("P(x)= ");
	if(l.pHead ==NULL)
	{
		printf("Empty Polynomial! \n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while (p!= NULL)
		{
			if((p!=l.pHead) && (p->Info.heso>0))
			printf(" + ");
			if(p->Info.bac==0)
				printf("%d",p->Info.heso);
			else if(p->Info.heso!=0)
				printf("%dx ^ %d",p->Info.heso, p->Info.bac);
			p = p->pNext;
		}
	}
}

int main()
{
	Dathuc dt1, dt2, dt3;
	Init(dt1);
	Init(dt2);
	Init(dt3);
	
	printf ("Please enter polynomial!\n");
	printf ("--------------------------------------------\n");
	
	printf("Enter polynomial 1: \n");
	NhapDaThuc(dt1);
	PrintDathuc(dt1);
	
	printf("\n--------------------------------------------\n");
	 
	printf("Enter polynomial 2: \n");
	NhapDaThuc(dt2);
	PrintDathuc(dt2);
	
	CongDathuc(dt1,dt2,dt3);
	PrintDathuc(dt3);
	
	return 0;
}

