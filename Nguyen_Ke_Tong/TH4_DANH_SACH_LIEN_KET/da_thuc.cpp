#include <stdio.h>
#include <stdlib.h>
 
typedef struct DonThuc
{
    int heso;
    int bac;
}DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node* pNext;
}Node;

typedef struct DaThuc
{
    Node *pHead;
    Node *pTail;
}DaThuc;

Node *GetNode (DonThuc x)
{
    Node *p;
    p= new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat nut moi");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(DaThuc &l, Node *new_ele)
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

void NhapDathuc(DaThuc &l)
{
	int MaxN= 0;
	int i,j;
	DonThuc s;
	
	printf("PT co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac= i;
		scanf("%d", &s.heso);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

void Init(DaThuc &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintDaThuc(DaThuc &l)
{
    Node *p;
	p = l.pHead;
	
	printf("\nP(x)= ");
	
    while (p!= NULL)
    {
        
        if((p->Info.heso>0)&&(p!= l.pTail))
        printf("+");
        
        if(p->Info.bac == 0)
        printf("%d",p->Info.heso);
        
        else 
        printf("%dx^%d",p->Info.heso, p->Info.bac);

        p= p->pNext;
    }
}

DaThuc CongDaThuc(Dathuc l1, Dathuc l2)
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

int main()
{
    DaThuc dt1, dt2, dt3;
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
