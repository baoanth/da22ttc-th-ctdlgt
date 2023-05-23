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

void AddNodeAfter(List &l, int idx, Node *new_ele)
{
	Node *q;
	q= FindNodeByID(l,idx);
	if ( q!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if(q == l.pTail)
			l.pTail = new_ele;
	}
	else 
		AddFirst(l, new_ele);
}
    
void RemoveHead(List &l)
{
	Node *p;
		
	if ( l.pHead != NULL)
	{
		p = l.pHead; 
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead == NULL) l.pTail = NULL;
	}
}
    
void RemoveLast(List &l, Node *q)
{
	Node *p;
	
	if ( q != NULL)
	{
		p = q ->pNext ;
		if ( p != NULL)
	{
	if(p == l.pTail)
		l.pTail = q;
	q->pNext = p->pNext;
	delete p;
	}
}
	else
		RemoveHead(l);
}
	
void RemoveNode(List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	
	while( p != NULL)
	{
		if(p->Info.id == idx) break;
		q = p; 
		p = p->pNext;
	}
	 
	if(q != NULL)
	{
		if(p == l.pTail)
		l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	else 
	{
		l.pHead = p->pNext;
		if(l.pHead == NULL)
			l.pTail = NULL;
		
	}

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

int main()
{
	struct person per1 = {1, "Le Xuan", "Truong"};
	struct person per2 = {2, "Thach Thi Hue", "Trinh"};
	struct person per3 = {3, "Le Thach Xuan", "Meo"};
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    PrintList(my_list);
    
	int idx;
	printf("\nNhap vi tri ID can chen vao sau no : ");
	scanf("%d",&idx);
    AddNodeAfter(my_list, idx, new_ele3);
    
	PrintList(my_list);
	
	printf("\nNhap ID can tim : ");
	scanf("%d",&idx);
	printf("\n");
	Node* KQ = FindNodeByID(my_list, idx);
	if(KQ != NULL)
		PrintNode(KQ);
	else
		printf("\nKhong tim thay Node co ID : %d",idx);	
	
	printf("\nNhap ID can xoa : ");
	scanf("%d",&idx);
	
	printf("\nSau khi xoa ID %d : \n", idx);
//	RemoveHead(my_list);
//	RemoveLast(my_list, KQ);
	RemoveNode(my_list, idx);
	PrintList(my_list);

	
	return 0;
}

