#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Node
{
    char Info;
    Node *pNext;
}Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
}Queue;

void Init(Queue &s)
{
    s.pHead = s.pTail = NULL;
}

Node* GetNode(char x)
{
	Node* p;
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->Info=x;
	p->pNext=NULL;
	return p;	
}

void AddTail(Queue &s, Node* new_ele)
{
    if(s.pHead==NULL)
    {
	    s.pHead=new_ele;
	    s.pTail=s.pHead;
	}
	else
	{
	    s.pTail->pNext = new_ele;
        s.pTail = new_ele;
	}
}

void RemoveHead(Queue &s)
{
    Node *p;
    char x;
    if(s.pHead != NULL)
    {
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        delete p;
        if(s.pHead == NULL)
            s.pTail = NULL;
    }
}
char IsEmpty(Queue &s)
{
    if(s.pHead == NULL)
        return 1;
    else return 0;
}

void EnQueue(Queue &s, char x)
{
    Node * new_ele = GetNode(x);
    AddTail(s, new_ele);
}

char DeQueue(Queue &s)
{
    char x;
    if(IsEmpty(s)) 
        return NULL;
        x = s.pHead->Info;
    RemoveHead(s);
    return x;
}

char Front(Queue &s)
{
    if(IsEmpty(s)) return NULL;
    return s.pHead->Info;
}

int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";
    int i;
    char x;
    Queue my_queue;
    Init(my_queue);

    printf("Chuoi nguon: %s\n",str);
    printf("\n Ket qua in ra voi Queue: ");

    for(i=0; i<strlen(str); i++)
    {
        if(str[i]=='*')
        {
            x = DeQueue(my_queue);
            printf("%c", x);
        }
        else 
            EnQueue(my_queue,str[i]);
    }
    return 0;
}

