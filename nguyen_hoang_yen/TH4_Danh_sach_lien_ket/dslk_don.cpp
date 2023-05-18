#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int id;
    char fname[20];
    char lname[20];
}person;

typedef struct Node
{
	person Info;
	Node* pNext;
}Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
}List;

Node* GetNode(person x)
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

void AddFirst(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail  = l.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}

void AddTail(List &l, Node *new_ele)
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

void AddNodeAfter(List &l, Node *q, Node *new_ele)
{
	if( q!=NULL)
	{
		new_ele->pNext =q->pNext;
		q->pNext = new_ele;
		if(q==l.pTail)
			l.pTail= new_ele;
	}
	else
	 AddFirst(l, new_ele);
}


void RemoveHead(List &l)
{
	Node *p;

	if (l.pHead !=NULL)
	 {
	 	p= l.pHead ;
	 	l.pHead= l.pHead->pNext;
		delete p;
		if (l.pHead==NULL)
		    l.pTail= NULL;
	 }
}	 

void RemoveAfter(List &l, Node *q)
{
	Node *p;
	if(q!= NULL)
	{
		p=q ->pNext;
		if(p !=NULL)
		{
			if (p==l.pTail)
				l.pTail= q;
			q->pNext =p->pNext;
			delete p;
		}
	}
	else 
	RemoveHead(l);
}

int RemoveNode (List &l, int idx)
{
	
   	Node *p=l.pHead;
   	Node *q=NULL;
   	while(p!=NULL)
   	{
   		if(p ->Info.id == idx) break;
   		q = p; p=p->pNext;
   	}
		if(p==NULL) return 0; 
		printf("Ko thay Node co id can tim = %d",idx);
   		if(q != NULL)
   	{
   		if (p==l.pTail)
   			l.pTail = q;
   		q->pNext = p->pNext;
   		delete p;
   	}
   	else 
   	{
   		l.pHead= p->pNext;
   		if(l.pHead == NULL)
   			l.pTail== NULL;
   	}
   	return 1;
   	
}

Node* FindNodeByID (List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;	
	
}

void Init(List &l)
{
	l. pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%5d  %20s  %20s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	if (l. pHead ==NULL)
	{
		printf(" Danh sach trong\n");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext; 
		}
	}
}
int main()
{

	struct person per1 = {1, "Yen", "Vo" };
	struct person per2 = {2, "Hong", "Nguyen" };
	struct person per3 = {3 , "Dung", "Tran" };

	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	List my_list;
	Init(my_list);
	
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
	AddTail(my_list, new_ele3);
	
	PrintList(my_list);
	
	int idx;
	printf("\nNhap id can tim: ");
	scanf("%d",&idx);
	Node* KQ=FindNodeByID (my_list, idx);
		if(KQ != NULL) PrintNode(KQ);
		else
		 printf("\nTim ko thay Node co id %d", idx);
		 
	printf("\nNhap id muon xoa :");
	scanf("%d", &idx);
	int kq=RemoveNode(my_list, idx);
	if (kq !=0)
		printf("\nDa xoa Node co id = %d",idx);
		printf("Danh sach sau thao tac \n");
	PrintList(my_list);	

return 0;
