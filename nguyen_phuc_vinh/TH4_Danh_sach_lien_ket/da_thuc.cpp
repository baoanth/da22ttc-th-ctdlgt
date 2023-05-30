#include <stdio.h>
#include <conio.h>
#include <string.h>

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
	Node* pHead;
	Node* pTail;
}DaThuc;

Node* Get_Node(DonThuc x)
{
	Node *p;
	p = new Node;
	
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	
	p->Info=x;
	p->pNext=NULL;
	return p;
}

void Add_Tail(DaThuc &l, Node* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail=new_ele;
	}
}

void Init(DaThuc &l)
{
	l.pHead = l.pTail = NULL;
}

void Nhap_DaThuc(DaThuc &l)
{
	int maxMU;
	DonThuc s;
	printf("\nMoi ban nhap so bac lon nhat cua DaThuc: ");
	scanf("%d", &maxMU);
	
	for(int i=maxMU; i>=0; i--)
	{
		printf("Nhap he so cua mu %d: ", i);
		scanf("%d", &s.heso);
		s.bac = i;
		Node* new_ele = Get_Node(s);
		Add_Tail(l, new_ele);
	}
}

void Print_DaThuc(DaThuc &l)
{
	if (l.pHead ==NULL)
	{
		printf("Da thuc rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			if((p!=l.pHead) && (p->Info.heso))
			printf("+");
			if(p->Info.bac==0)
				printf("%d", p->Info.heso);
			else if(p->Info.bac==1)
				printf("%dx", p->Info.heso);
			else
			{
				printf("%dx^%d", p->Info.heso, p->Info.bac);
			}
		
			p = p->pNext;
		}		
	}
}

void Copy_DaThuc(DaThuc l, DaThuc &l_kq)
{
	Node* p;
    p = l.pHead;
    
    while (p!=NULL)
    {
    	Node* new_ele = Get_Node(p->Info);
    	Add_Tail(l_kq, new_ele);
    	p=p->pNext;
    }
   // printf("\nCopy xong\n");
}

Node* Tim_Node_BacN(DaThuc l, int n)
{
	Node* p;
    p =l.pHead;
    
    while (p!=NULL)
    {
    	if(p->Info.bac==n)
    		break;
    	p=p->pNext;
    }
    return p;
}

void Cong_DaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)
{
	    
    Copy_DaThuc(l1, l_kq);
    printf("\n");
    
	Node* p;
    p =l2.pHead;
    
	while (p!=NULL)
    {
    	Node* foundNode = Tim_Node_BacN(l_kq, p->Info.bac);
    	if (foundNode!=NULL)
		{
		 	
    		foundNode->Info.heso += p->Info.heso;	 
    		printf("Found bac %d\n" ,p->Info.bac);
    	}
    	else
    	{
    		Node* node_tam = Get_Node(p->Info);
    		Add_Tail(l_kq, node_tam);
    	}
    	p=p->pNext;
    }  
printf("\n");
}

<<<<<<< HEAD
=======
float Uoc_Luong(Dathuc &l1, int x)
{
	Node* p=l.pHead;
	
	while(p!=NULL)
	{
		
	}
}

>>>>>>> 7c824c252a81952b5aa42d5d5323e8013f81784a
int main()
{
	DaThuc my_dathuc1, my_dathuc2, my_dathuc_kq;
	Init(my_dathuc1);
	Init(my_dathuc2);
	Init(my_dathuc_kq);
	
	Nhap_DaThuc(my_dathuc1);
	printf("\nDa thuc thu nhat vua nhap: ");
	Print_DaThuc(my_dathuc1);
	printf("\n");
	
	Nhap_DaThuc(my_dathuc2);
	printf("\nDa thuc thu hai vua nhap: ");
	Print_DaThuc(my_dathuc2);
	printf("\n");
	
	Cong_DaThuc(my_dathuc1, my_dathuc2, my_dathuc_kq);
	printf("Ket qua cong 2 da thuc: ");
	Print_DaThuc(my_dathuc_kq);
	
	
<<<<<<< HEAD
=======
	
	
>>>>>>> 7c824c252a81952b5aa42d5d5323e8013f81784a
}
