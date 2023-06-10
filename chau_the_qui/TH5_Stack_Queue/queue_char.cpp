#include <stdio.h>
#include <conio.h>
#include <string.h>



typedef struct Node
{
	char Info; 
	Node* pNext; 
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;


Node *GetNode(char &x)
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
    char x;
   		if (l.pHead != NULL)
    	{
    		p= l.pHead;
    		l.pHead = l.pHead->pNext;
    		delete p;
    		if(l.pHead == NULL)
    		l.pTail = NULL;
    	}
}

void EnQueue(Queue &q, char x)
{
	Node* new_ele = GetNode(x);
	AddFirst(q, new_ele);
}
char DeQueue(Queue &q)
{
	char x;
	if(IsEmpty(q)) 
		return NULL;
	x = q.pHead->Info;
	RemoveHead(q);
	return x;
}
char Front(Queue &q)
{
	if(IsEmpty(q))
		return NULL;
	return q.pHead->Info;
}
int main()
{
	char str[] = "EAS*Y**QUE***ST**TION";
	int i;
	char x;
	Queue my_queue;
	Init(my_queue);
	
	printf("Chuoi ban dau: %s\n", str);
	printf("Ket qua in ra voi STACK:  ");
	
	for (i=0; i<strlen(str);i++)
	{
		if(str[i] =='*')
		{
			x = DeQueue(my_queue);
			printf("%c",x);
		}
		else
			EnQueue(my_queue, str[i]);
	}
	return 0;
}
