#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    
    char hoten[20];
    int tuoi;
    char dchi[20];
    char tinhtrang[50];
} Person;

typedef struct Node
{
	Person Info; 
	Node* pNext; 
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;


Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void AddFirst(Queue &l, Node* new_ele)
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
void AddTail(Queue &l, Node *new_ele)
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
void PrintNode(Node *p)
{
    printf("%d %s %s %s\n", p->Info.tuoi, p->Info.hoten, p->Info.dchi,p->Info.tinhtrang);
}
void PrintList(Queue &l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s %s\n", p->Info.tuoi, p->Info.hoten, p->Info.dchi, p->Info.tinhtrang);
        p = p->pNext;
    }
}
void Init(Queue &q)
{
    q.pHead = q.pTail = NULL;
}
char IsEmpty(Queue &q)
{
    if(q.pHead == NULL)
    return 1;
    else
	 return 0;
}

void RemoveHead(Queue &l)
{
    Node *p;
    Person x;
   		if (l.pHead != NULL)
    	{
    		p= l.pHead;
    		l.pHead = l.pHead->pNext;
    		delete p;
    		if(l.pHead == NULL)
    		l.pTail = NULL;
    	}
}

void EnQueue(Queue &q, Person x)
{
	Node* new_ele = GetNode(Person x);
	AddTail(q, new_ele);
}
char DeQueue(Queue &q)
{
	Person x;
	if(IsEmpty(q)) 
		return NULL;
	x = q.pHead->Info;
	RemoveHead(q);
	
}
char Front(Queue &q)
{
	if(IsEmpty(q))
		return NULL;
	return q.pHead->Info;
}
int main()
{
	
	struct Person per1 = {19, "Dang Hoang Phuoc", "Duyen Hai", "on dinh"};
    struct Person per2 = {21, "Tran Chi Truong Tho", "Nguyet Hoa", "benh tim"};
    struct Person per3 = {32, "Chau The Qui", "Tra Vinh","khoe manh"};
   
    
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);

    Queue my_queue;
    Init(my_queue);

    AddFist(my_queue, new_ele1);
    AddTail(my_queue, new_ele2);
    AddFist(my_queue, new_ele3);

    PrintList(my_queue);
	return 0;
}
