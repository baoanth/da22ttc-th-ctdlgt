#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Donthuc
{
	int heso;
	int bac;
}Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node *pNext;
}Node;

typedef struct Dathuc
{
	Node *pHead;
	Node *pTail;
}Dathuc;

Node *GetNode(Donthuc x)
{
	Node *p;
	p = new Node;
	if(p == NULL)
	{
		printf("Khong du bo nho de cap phat");
		return 0;
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
	if(l.pHead == NULL)
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

void ThemNutCuoi(Dathuc &l)
{
	Donthuc s;
	
	printf("Bac: ");
	scanf("%d", &s.bac);
	printf("He so: ");
	scanf("%d", &s.heso);
	
	Node* new_ele = GetNode(s);
	AddTail(l, new_ele);
	
}

void NhapDaThuc(Dathuc &l)
{
    Donthuc s;
    int i,maxN;
	printf("Bac cua da thuc: ");
	scanf("%d", &maxN);
	for (i =maxN; i>=0; i--)
	{
		printf("x^%d =", i);
		s.bac =i;
		scanf("%d", &s.heso);
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);
	}
}

void CopyDathuc(Dathuc l, Dathuc &l_kq)
{
	Node* p;
	p = l.pHead;
	
	while (p!=NULL)
	{
		Node* new_ele = GetNode(p->Info);
		AddTail(l_kq, new_ele);
		p=p->pNext;
	}
	printf("\nDa copy da thuc\n");
}

Node* TimNodeBacN(Dathuc l, int n)
{
	Node* p;
	p = l.pHead;
	
	while (p!=NULL)
	{
		if(p->Info.bac==n)
		   break;
		p=p->pNext;
	}
	return p;
}

void CongDathuc(Dathuc l1, Dathuc l2, Dathuc &l_kq)
{
	CopyDathuc(l1, l_kq);
	
	Node* p;
	p= l2.pHead;
	
	while(p!=NULL)
	{
		Node* foundNode = TimNodeBacN(l_kq, p->Info.bac);
		if (foundNode!=NULL)
		{
			foundNode->Info.heso += p->Info.heso;
			printf("Found bac %d\n" ,p->Info.bac);
		}
		else
		{
			Node* node_tam = GetNode(p->Info);
			AddTail(l_kq, node_tam);
		}
		p=p->pNext;
	}

}

void PrintDathuc(Dathuc &l)
{
	if (l.pHead == NULL)
	{
		printf("Da thuc rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			if((p!=l.pHead) &&  (p->Info.heso>=0))
			printf("+");
			printf("%dx^%d", p->Info.heso, p->Info.bac);
			p = p->pNext;
		}
	}
}

int main()
{
	/*Dathuc mydathuc;
	Init(mydathuc);
	
	NhapDaThuc(mydathuc);
	PrintDathuc(mydathuc);*/
	Dathuc dt1, dt2, dt3;
	Init(dt1);
	Init(dt2);
	
	printf("Nhap da thuc 1: \n");
	NhapDaThuc(dt1);
	PrintDathuc(dt1);
	
	printf("\n");
	 
	printf("Nhap da thuc 2: \n");
	NhapDaThuc(dt2);
	PrintDathuc(dt2);
	
	dt3 = CongDathuc(dt1, dt2);
	printf("\nTong hai da thuc la:  ");
	PrintDathuc(dt3);
	
	return 0;
}

