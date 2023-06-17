#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int hs;
    int bac;
} Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node* pNext;
} Node;

typedef struct Dathuc
{
	Node* pHead;
	Node* pTail;
} Dathuc;

Node* GetNode(Donthuc x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Ko du bo nho !"); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

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

void Nhapdathuc(Dathuc &l)
{
	int MaxN= 0;
	int i;
	Donthuc s;
	
	printf("Pt co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac= i;
		scanf("%d", &s.hs);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

Dathuc congdathuc(my_dathuc, dathuc &l1, dathuc &l2 )
{
	Node *p, *q;
	Donthuc dt-tam;
	p = l1 -> pHead;
	q = l2 -> pHead;
	while(p != NULL)
	{
		dt_tam.hs = p -> Info.hs;
		dt_tam.bac = q -> Info.bac;
		while(q != NULL)
		{
			if (p -> tam.hs = p->Info.bac) break;
			q = q -> pNext;
		}
	}
	if(q != NULL)
    	dt_tam.hs += q -> Info.hs;
    Node new_ele = GetNode(dt_tam);
}



void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

void Printdathuc(Dathuc &l)
{
	Node *p;
	p = l.pHead;
	
	printf("\nDa thuc vua nhap =  ");
	
	while (p!= NULL)
	{
		if((p->Info.hs>0)&&(p!=l.pHead))
			printf("+");
		if(p->Info.bac==0)
			printf("%d",p->Info.hs);
		else
			printf("%dx^%d",p->Info.hs, p->Info.bac);
		p = p->pNext;
	}
}

<<<<<<< HEAD:le_xuan_truong/TH4_danh_sach_lien_ket/dathuc.cpp
//Dathuc CongDathuc(Dathuc l1, Dathuc l2)
//{
//	Node *p, *q;
//	
//	Dathuc l_kq;
//	Init(l_kq);
//	
//	Donthuc t;
//	p= l1.pHead;
//	q= l2.pHead;
//	
//	while(p!= NULL)
//	{
//		t.hs= p->Info.hs;
//		t.bac= p->Info.bac;
//		
//		while(q!= NULL)
//		{
//			if(p->Info.bac == q->Info.bac)
//			break;
//			q= q-> pNext;
//		}
//		if(q!= NULL)
//			t.hs += q->Info.hs;
//			
//		Node* new_ele= GetNode(t);
//		AddTail(l_kq, new_ele);
//		p=p->pNext;
//	}
//	return l_kq;
//}

void CopyDathuc(Dathuc l, Dathuc &l_kq)
{
	Node *p;
	p=l.pHead;
	
	while(p!=NULL)
	{
		Node* new_ele = GetNode(p->Info);
		AddTail(l_kq, new_ele);
		p=p->pNext;
	
	}
	printf("\nDa copy Da thuc thanh cong!\n");
}

Node *TimNodeBacN(Dathuc l, int n)
{
	Node *p;
	p=l.pHead;
	
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
	CopyDathuc(l1,l_kq);
	
	Node *p;
	p=l2.pHead;
	
	while(p!=NULL)
	{
		Node*FoundNode =TimNodeBacN(l_kq, p->Info.bac);
		if(FoundNode!=NULL)
		{
			FoundNode->Info.hs += p->Info.hs;
			printf("Tim bac %d\n",p->Info.bac);
		}
		else
		{
			Node *node_tam= GetNode(p->Info);
			AddTail(l_kq,node_tam);
		}
		p=p->pNext;
	}
}

int main()
{
	Dathuc my_dathuc1;
	Init(my_dathuc1);
	Dathuc my_dathuc2;
	Init(my_dathuc2);
	Dathuc my_dathuc3;	

	printf("Nhap da thuc 1: ");		
	NhapDathuc(my_dathuc1);		   
	PrintDathuc(my_dathuc1);
	
	printf("\n");
	
	printf("\nNhap da thuc 2: ");	
	NhapDathuc(my_dathuc2);		   
	PrintDathuc(my_dathuc2);
	
//	printf("\n\nTong 2 da thuc:  ");	
//	my_dathuc3= CongDathuc(my_dathuc1, my_dathuc2);
//	PrintDathuc(my_dathuc3);
	CongDathuc(my_dathuc1, my_dathuc2, my_dathuc3);
	PrintDathuc(my_dathuc3);
	
=======
int main()
{
	Dathuc my_dathuc;
	Init(my_dathuc);
		
	Nhapdathuc(my_dathuc);
		   
	Printdathuc(my_dathuc);
	    
>>>>>>> 44187dd0f04ee5e8f0fcb4278aedf502e940f023:nguyen_hoang_yen/TH4_Danh_sach_lien_ket/Untitled1.cpp
    return 0;
}


