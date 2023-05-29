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
	printf("Bac cua da thuc la bac : ");
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
	printf("Moi ban nhap ");
	Dathuc mydathuc;
	Init(mydathuc);
	
	NhapDaThuc(mydathuc);
	PrintDathuc(mydathuc);
	
	return 0;
}


