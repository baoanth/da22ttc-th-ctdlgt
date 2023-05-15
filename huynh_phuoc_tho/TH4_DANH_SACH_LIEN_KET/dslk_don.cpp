#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
int id;
char fname[20];
char lname[20];
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

Node* GetNode(Person x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("khong du dung luong bo nho "); 
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

void AddNodeAfter(List &l, int idx,  Node* new_ele)
{
	Node* p=FindNodeByID(l,idx);
	if(p==NULL)
	{
		printf("Node with ID %d not found\n", idx);
		return;
	}
/*	if(p==l.Tail)
	{
		AddLast(l.new_ele);
	}*/
}

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%5d %20s %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

void RemoveHead(List &l)
{
/*	if(l.Head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head==l.Tail)
	{
		free(l.Head);
		l.Head=NULL;
		l.Tail=NULl;
	}
	else
	{
		Node* p=l.Head;
		l.Head=l.Head->next;
		free(p);
	}*/
}

void RemoveLast(List &l)
{
/*	if(l.Head=NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head==l.Tail)
	{
		free(l.Head);
		l.Head=NULL;
		l.Tail=NULl;
	}
	else
	{
		Node* p=l.Head;
		while(p->next!=l.Tail)
		{
			p=p->next;
		}
		free(l.Tail);
		l.Tail = p;
		l.Tail -> next = NULL;
	}*/
}

void RemoveNode(List &l, int idx)
{
/*	if(l.Head=NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head->info.id  == idx)
	{
		RemoveHead(l);
		return;
	}
		Node* p=l.Head;
		while(p->next!=NULL && p->next->info.id !=idx)
		{
			p=p
		}*/
}

int main()
{
    struct Person per1 = {1, "Phuoc", "Tho"};
	struct Person per2 = {2, "Tho", "Huynh"};
	struct Person per3 = {3, "Huynh", "Phuoc"};
	
	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
	
	List my_list;
		 
	AddFirst(my_list, new_ele1);
	AddFirst(my_list, new_ele2);
	AddFirst(my_list, new_ele3);
	
	PrintList(my_list);
	return 0;
    
}





