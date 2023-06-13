#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//********************
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

//********************

//Viet ham GetNode
Node* GetNode(Donthuc x)
{
	Node *p;
	p = new Node;
	if (p == NULL)   
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
		if((p->Info.hs>=0) && (p!=l.pHead))
			printf("+");
		if(p->Info.bac == 0)
			printf("%d", p->Info.hs);
		else
			printf("%dx^%d", p->Info.hs, p->Info.bac);
		p = p->pNext;
	}
}

//Viet ham Copy Da thuc
void Copydathuc(Dathuc l, Dathuc &l_kq)
{
	Node *p;
	p = l.pHead;
	
	while(p != NULL)
	{
		Node* new_ele = GetNode(p->Info);
		AddTail(l_kq, new_ele);
		p = p->pNext;
	}
	printf("\nDa copy da thuc xong\n");
}

//Viet ham tim Node bac N
Node* TimNodeBacN(Dathuc l, int n)
{
	Node *p;
	p = l.pHead;
	
	while(p!=NULL)
	{
		if(p->Info.bac == n)
			break;
		p = p->pNext;
	}
	return p;
}

//Viet ham cong da thuc 
void Congdathuc(Dathuc l1, Dathuc l2, Dathuc &l_kq)
{
	Copydathuc(l1, l_kq);
	
	Node* p;
	p = l2.pHead;
	
	while(p!=NULL)
	{
		Node* foundNode = TimNodeBacN(l_kq, p->Info.bac);
		if(foundNode != NULL)
		{
			foundNode->Info.hs += p->Info.hs;
		}
		else
		{
			Node* Node_tam = GetNode(p->Info);
			AddTail(l_kq, Node_tam);
		}
		p = p->pNext;
	}
}

//Viet ham tinh gia tri da thuc khi nhap x tu ban phim
float GTdathuc(Dathuc l, int x)
{
	float kq=0;
	
	Node* p= l.pHead;
	
	while(p!=NULL)
	{
		kq += p->Info.hs *pow(x, p->Info.bac);
		
		p = p->pNext;
	}
	return kq;
}
//Viet ham main
int main()
{
	//Dinh nghia them 1 da thuc 
	Dathuc dathuc1, dathuc2, dathuc3, kq;
	
	Init(dathuc1);
	Init(dathuc2);
	Init(dathuc3);
	Init(kq);
		
	//Nhap 2 da thuc
	Nhapdathuc(dathuc1);
	Nhapdathuc(dathuc2);
	
	
	//In 2 da thuc vua nhap		   
	Printdathuc(dathuc1);
	Printdathuc(dathuc2);
	
	//Cong da thuc 2 da thuc
	Congdathuc(dathuc1, dathuc2, dathuc3);
	printf("\nTong 2 da thuc la: \n");
	Printdathuc(dathuc3);
	

	
	float x;
	printf("\nNhap vao gia tri cua bien X: ");
	scanf("%f", &x);
	
	printf("\nKhi x = %.2f thi gia tri cua da thuc la: %.2f", x, GTdathuc(dathuc3, x));
	
    return 0;
}

