#include <stdio.h>
#include <stdlib.h>

//******************
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
//*******************

//Viet ham GetNode
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

//Viet ham AddTail
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

//Viet ham Nhap da thuc
void Nhapdathuc(Dathuc &l)
{
	int MaxN= 0;
	int i, j;
	Donthuc s;
	
	printf("Phuong trinh co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac = i;
		scanf("%d", &s.hs);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

//Viet ham Init
void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

//viet ham Printdathuc
void Printdathuc(Dathuc &l)
{
	Node *p;
	p = l.pHead;
	
	printf("\nDa thuc vua nhap la:  ");
	
	while (p!= NULL)
	{
		if((p->Info.hs>0) && (p!=l.pHead))
			printf("+");
		if(p->Info.bac == 0)
			printf("%d", p->Info.hs);
		else
			printf("%dx^%d", p->Info.hs, p->Info.bac);
		p = p->pNext;
	}
}

//Viet ham Congdathuc
//Dathuc Congdathuc(dathuc1, dathuc2)
//{
	
//}


//viet ham main
int main()
{
	//Dinh nghia them 1 da thuc 
	Dathuc dathuc1;
	Dathuc dathuc2;
	
	Init(dathuc1);
	
	//Nhap 2 da thuc
	Nhapdathuc(dathuc1);
	Nhapdathuc(dathuc2);
	
	//In 2 da thuc vua nhap		   
	Printdathuc(dathuc1);
	Printdathuc(dathuc2);
	
    return 0;
}

