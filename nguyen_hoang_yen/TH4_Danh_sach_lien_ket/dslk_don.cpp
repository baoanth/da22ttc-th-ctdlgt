
#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
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
	p= new Node;
	if (p==NULL)
	{
		printf(" ko du bo nho co the cap phat cho nat moi");
		return NULL;
	}
	p->Info = x;
	p->pNext = NULL;
	return p; 
}

void AddFist(List &l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{ 
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}
void AddTail(List &l, Node* new_ele)
{
	if(l.pHead==NULL)
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

void RemoveHead(List &l, int idx)
{
	Node *p;
	if (l.pHead  != NULL)
	{
		p = l.pHead; 
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL) l.pTail = NULL;
	}
} 

void RemovoAfter ( List &l, Node *q)
{
	Node *p;
	if ( q != NULL)
	{
		p = q ->pNext;
		if (p ! = NULL)
		{
			if (p== l.pTail)
		 		l.pTail = q;
			q->pNext = p->pNext;
			delete p;	
		} 
	else
	
		RemoveHead(l);
	}
}
int RemoveNode (List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while( p! = NULL)
	{
		if (p->Info == k) break;
		q = p; p = p->pNext;
	}
	if(p == NULL) return 0;
	if(q != NULL)
	{
		if(p == l.pTail)
			l.pTail = q;
			p->pNext = p->pNext;
			delete p;
	}
	else
	{
		l.Head = p->pNext;
		if(l.pHead == NULL)
			l.pTail = NULL;
	}
	return 1;
}


Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p =l.pHead;
	while((p!=NULL) && ( p->Info.id !=idx ))
	p = p-> pNext;
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
	struct Person per1 = {1, "yen", "nguyen" };
	struct Person per2 = {2, "hong", "tran" };
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	List my_list;
	Init(my_list);
	
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
	
	PrintList(my_list);
	
	int idx;
	scanf("%d", &idx);
   	printf("\n nhap id can tim  ");
	printf("\n");
    Node* kq = FindNodeByID( my_list, idx);
	if ( kq != NULL)
    	PrintNode(kq);
	else 
		printf("Tim khong thay node co id \n  %d",idx);   
	
    return 0;
}





 
/*void AddFirst (DList &l, DNode* new_ele)
{
	if (l.Head==NULL)
	{
		l.pHead = new_ele;
		l.pHead = l.Head;
	}
	else
	{
		new_ele->pNext = l.Head;
		l.Head ->pPev = new_ele;
		l.Head = new_ele; 
	}
}
NODE* InsertHead(DList &l, Data x)
{
	NODE* new_ele = GetNode (x);
	if (new_ele==NULL) return NULL;
	if ( l.pHead==NULL)
	{
		L. pHead = new_ele;
		l.pTail = l. pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.Head ->pPrev = new_ele ;
		l.Head = new_ele;
	}
	return new_ele;
}*/



	






