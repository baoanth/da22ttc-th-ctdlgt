#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
		scanf("\n%d",&s.hs);
		Node*new_ele=GetNode(s);
		AddTail(l, new_ele);
	}
}

Dathuc CongDaThuc(Dathuc l1, Dathuc l2)
{
	Node *p, *q;
	Dathuc l_kq;
	Init(l_kq);
	Donthuc dt_tam;
	p= l1.pHead;
	q= l2.pHead;
	while(p!=NULL)
	{
		dt_tam.hs= p->Info.hs;
		dt_tam.bac= q->Info.bac;
		while(q!=NULL)
		{
			if (p->Info.bac == q->Info.bac)
				break;
			q=q->pNext;	
		}
		if(q!=NULL)
			dt_tam.hs += q->Info.hs;
			
		Node* new_ele = GetNode(dt_tam);
		AddTail(l_kq, new_ele);
		
		p->pNext;	
	}
	return l_kq;
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
	printf("\nDa copy da thuc thanh cong!\n");
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
			FoundNode->Info.hs +=p->Info.hs;
			printf("Tim bac %d\n", p->Info.bac);
		}
		else
		{
			Node* node_tam= GetNode(p->Info);
			AddTail(l_kq,node_tam);
		}
		p=p->pNext;
	}

}

float UocluongDathuc(Dathuc l, int x)
{
	float kq=0;
	
	Node* p= l.pHead;
	
	while(p!=NULL)
	{
		kq += p->Info.hs *pow(x,p->Info.bac);
		
		p=p->pNext;
	}
	return kq;

	
}
/*Dathuc CongDaThuc(Dathuc l1, Dathuc l2)
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
} */


void PrintDathuc(Dathuc &l)
{ 
	printf("P(x)=");
	if(l.pHead==NULL)
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
			else if(p->Info.hs!=0)
				printf("%dx^%d",p->Info.hs, p->Info.bac);
			p = p->pNext;
		}
	}
}

int main()
{

	Dathuc my_dathuc1;
	Init(my_dathuc1);
	Dathuc my_dathuc2;
	Init(my_dathuc2);
	Dathuc my_dathuc3;

	Dathuc dt1, dt2, dt3;
	float x;
	Init(dt1);
	Init(dt2);
	Init(dt3);

	
	printf("---[NHAP DA THUC 1]--- \n");
	NhapDaThuc(dt1);
	PrintDathuc(dt1);
	
	printf("\n\n");
	 
	printf("---[NHAP DA THUC 2]--- \n");
	NhapDaThuc(dt2);
	PrintDathuc(dt2);
 
	printf("\n");
/*	dt3= CongDathuc(dt1, dt2);
	printf("\n\nTong hai da thuc la:  ");
	PrintDathuc(dt3);
*/
	CongDathuc(dt1,dt2,dt3);
	PrintDathuc(dt3); 
	
	printf("\n");
	
	printf("\nNhap gia tri cua x de uoc luong gia tri da thuc: x=");
	scanf("%f",&x);
	printf("Gia tri cua da thuc khi x=%.0f la: %.0f",x, UocluongDathuc(dt3, x));
	

	return 0;
}









