#include <stdio.h>
#include <stdlib.h>

typedef struct donthuc
{
    int heso;
    int bac;
    
}donthuc;

typedef struct Node
{
	donthuc Info;
	Node* pNext;
}Node;

typedef struct dathuc
{
	Node* pHead;
	Node* pTail;
}dathuc;

Node* GetNode(donthuc x)
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


void AddTail(dathuc &l, Node *new_ele)
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
void Init(dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

void themnutcuoi(dathuc &l)
{
	donthuc s ;
	
	printf("bac: ");
	scanf("%d", &s.bac);
	printf("he so: ");
	scanf("%d", &s.heso);
	
	Node* new_ele = GetNode(s);
	AddTail(l, new_ele);
}
void nhapdathuc(dathuc &l)
{
	int maxN=0;
	printf("bajn muon nhap da thuc bac may?");
	scanf("%d", &maxN);
	int i;
	donthuc s;
	for (i=maxN; i>=0; i--)
	{
		printf("x^%d *", i);
		s.bac = i;
		scanf("%d", &s.heso);
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);
		
	}
	
}
void congdathuc (dathuc &l1, dathuc &l2)
{
	
}
void Printdathuc(dathuc &l)
{
	if(l.pHead == NULL)
	{
		printf("da thuc rong");
	}
	else 
	{
	
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
    	{
		 if((p!=l.pHead) && (p->Info.heso>0))
		    printf("+");
		 if(p->Info.bac==0)
	    	printf("%d", p->Info.heso);
	   	else 
        	printf("%dx^%d",p->Info.heso, p->Info.bac);
		 p = p->pNext;
	    }
    }
}

int main()
{
	dathuc my_dathuc;
	Init(my_dathuc);
	
	int cont = 0;
	while (1)
	{
		themnutcuoi(my_dathuc);
		
		printf("tiep tuc? 1.tiep__0. dung ");
		scanf("%d", &cont);
		if( cont==0)
		break;
	}
	Printdathuc(my_dathuc);
	
	return 0;
}
	
	













