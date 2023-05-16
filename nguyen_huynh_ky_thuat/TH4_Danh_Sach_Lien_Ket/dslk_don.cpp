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
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

void RemoveHead(List &l)
{
	Node *p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
		    l.pTail = NULL;
	}
}
void RemoveAfter(List &l, Node *q)
{
	Node *p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
			    l.pTail = q;
			q->pNext = p->pNext;
			delete p;    
		}
	}
	
	else
	   RemoveHead(l);
	   
}

int RemoveNode(List &l, Data k)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while(p !=NULL)
	{
		if(p->Info == k) break;
		q= p; p = p->pNext;
	}
	if(p == NULL) return 0;
	if(q !== NULL)
	{
		if(p == l.pTail)
		     l.pTail = q;
		     q->pNext= p->pNext;
		     delete p;
	}
	else
	{
		l.pHead = p->pNext;
		if(l.pHead == NULL)
		     l.pTail = NULL;
	}
	return 1;
   }

int main()
{
	struct person per1 = {1, "Do", "Thien Vu"};
	struct person per2 = {2, "Nguyen", " Huynh Ky Thuat"};
	struct person per3 = {3, "Duong", "Tieu Tuyet"};
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
   
	PrintList(my_list);
	
	int idx;
	printf("\nNhap ID can tim : ");
	scanf("%d",&idx);
	printf("\n");
	Node* KQ = FindNodeByID(my_list, idx);
	if(KQ != NULL)
		PrintNode(KQ);
	else
		printf("\nKhong tim thay Node co ID : %d",idx);	
	
	return 0;
}
