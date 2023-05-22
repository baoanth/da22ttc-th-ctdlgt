#include<stdio.h>
#include<conio.h>
#include<string.h>


typedef struct DonThuc
{
    int hs;
    int bac;
} DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node *pNext;

} Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;

} Dathuc;

Node *GetNode(DonThuc x)
{
	Node *p;
	p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap nhat cho nut moi");
		
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
	DonThuc my_donthuc;
	Node *p;
	
	int n,i;
	printf("Nhap so bac cua da thuc:");
	scanf("%d", &n);
	for(i=n; i>=0; i--)
	{
		printf("x^%d :",i);
		scanf("%d",&my_donthuc.hs);
		
		my_donthuc.bac=i;
		
		Node *new_ele = GetNode(my_donthuc);
		
		AddTail(l, new_ele);
		
	}
	
}


void PrintList(Dathuc &l)
{
	if(l.pHead == NULL)
	{
		printf("Da thuc rong\n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			if ((p!=l.pHead) && (p->Info.hs>0))
				printf("+");
			printf("%dx^%d", p->Info.hs, p->Info.bac);
			p = p->pNext;
		}
	}
}

int main()
{
	Dathuc my_dathuc;
	Init(my_dathuc);
	
	int cont = 0;
	while(1)
	{
		ThemNutCuoi(my_dathuc);
		
		printf("Tiep tuc? 1.Tiep_ _0. Dung");
		scanf("%d", &cont);
		if(cont == 0)
			break;
	}
	PrintList(my_dathuc);

	return 0;	
} 





















