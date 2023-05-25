#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int hs;
    int bac;
    
}DonThuc;

typedef struct Node
{
	DonThuc Info;
	Node* pNext;
}Node;

typedef struct DaThuc
{
	Node* pHead;
	Node* pTail;
}DaThuc;

Node* Get_Node(DonThuc x)
{
	Node *p;
	p = new Node;
	
	if(p==NULL)
	{
		printf("Khong du bo nho de cap nhat!");
		return NULL;
	}
	
	p->Info=x;
	p->pNext=NULL;
	return p;
}

void Add_Tail(DaThuc &l, Node* new_ele)
{
	if(l.pHead == NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext=new_ele;
		l.pTail=new_ele;
	}
}

void Init(DaThuc &l)
{
	l.pHead=l.pTail=NULL;
}

void Nhap_DaThuc(DaThuc &l)
{
	int maxMU;
	DonThuc s;
	printf("Moi ban nhap so mu lon nhat:");
	scanf("%d",&maxMU);
	
	for(int i=maxMU; i>=0; i--)
	{
		printf("Nhap he so cua mu %d:",i);
		scanf("%d",&s.hs);
		s.bac = i;
		Node* new_ele = Get_Node(s);
		Add_Tail(l, new_ele);
	}
}

void Print_DaThuc(DaThuc &l)
{
	if (l.pHead==NULL)
	{
		printf("Da thuc rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			if((p!=l.pHead) && (p->Info.hs))
			printf("+");
			if(p->Info.bac==0)
				printf("%d", p->Info.hs);
			else if(p->Info.bac==1)
				printf("%dx", p->Info.hs);
			else
			{
				printf("%dx^%d", p->Info.hs, p->Info.bac);
			}
		
			p = p->pNext;
		}		
	}
}

int main()
{
	DaThuc my_dathuc;
	Init(my_dathuc);
	
	Nhap_DaThuc(my_dathuc);
	
	printf("\nDa thuc da nhap: ");
	Print_DaThuc(my_dathuc);
	
}

