#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

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
		printf("Not enough memory to update!");
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
	printf("Enter degree of polynomial: ");
	scanf("%d", &maxN);
	for (i =maxN; i>=0; i--)
	{
		printf("x ^ %d = ", i);
		s.bac =i;
		scanf("%d", &s.heso);
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);
	}
	printf ("\n");S
}

void PrintDathuc(Dathuc &l)
{
	if (l.pHead == NULL)
	{
		printf("EMPTY!\n");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			if((p!=l.pHead) &&  (p->Info.heso>=0))
			printf(" + ");
			printf("%3dx ^ %d", p->Info.heso, p->Info.bac);
			p = p->pNext;
		}
	}
}


int main()
{	
	printf ("Please enter polynomial!\n");
	printf ("--------------------------------------------\n");
	Dathuc mydathuc;
	Init(mydathuc);
	
	NhapDaThuc(mydathuc);
	PrintDathuc(mydathuc);
	
	return 0;
}

