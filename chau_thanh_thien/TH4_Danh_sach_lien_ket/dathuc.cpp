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
	printf("Da thuc bac: ");
	scanf("%d",&maxN);
	int i;
	Donthuc s;
	for(i=maxN; i>=0; i--)
	{
		printf("x^%d=",i);
		s.bac=i;
		scanf("%d",&s.hs);
		Node*new_ele=GetNode(s);
		AddTail(l, new_ele);
	}
}
Dathuc CongDaThuc(Dathuc l1, Dathuc l2)
{
	Node *p, *q;
	Dathuc l_kq;
	Init (l_kq);
	Donthuc dathuc_tam;
	p= l1.pHead;
	q= l2.pHead;
	while(p!=NULL)
	{
		dathuc_tam.hs=p->Info.hs;
		dathuc_tam.bac=p->Info.bac;
		while(q!=NULL)
		{
			if(p->Info.bac == q->Info.bac)
			break;
			q=q->pNext;
		}
		if(q!=NULL)
			dathuc_tam.hs += q->Info.hs;
			
		Node* new_ele = GetNode(dathuc_tam);
		AddTail(l_kq, new_ele);
		
		p=p->pNext;
	}
	
	return l_kq;
}

void PrintDathuc(Dathuc &l)
{ 
	printf("P(x)=");
	if(l.pHead ==NULL)
	{
		printf("Da thuc rong \n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while (p!= NULL)
		{
			if((p!=l.pHead) && (p->Info.hs>0))
			printf("+");
			if(p->Info.bac==0)
				printf("%d",p->Info.hs);
			else
				printf("%dx^%d",p->Info.hs, p->Info.bac);
			p = p->pNext;
		}
	}
}

int main()
{
	Dathuc dt1, dt2, dt3;
	Init(dt1);
	Init(dt2);
	
	printf("Nhap da thuc 1: \n");
	NhapDaThuc(dt1);
	PrintDathuc(dt1);
	
	printf("\n\n");
	 
	printf("Nhap da thuc 2: \n");
	NhapDaThuc(dt2);
	PrintDathuc(dt2);
	
	dt3 = CongDaThuc(dt1, dt2);
	printf("\n\nTong hai da thuc la:  ");
	PrintDathuc(dt3);
	
	


	return 0;
}

