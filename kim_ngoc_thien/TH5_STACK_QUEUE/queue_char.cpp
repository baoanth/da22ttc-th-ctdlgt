#include<stdio.h>
#include<stdio.h>
#include<string.h>


typedef struct Node
{
	char Info;
	Node* pNext;
}Node;

typedef struct queue
{
	Node* pHead;
	Node* pTail;
}queue;

Node* GetNode(char &x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho !"); 
		return 0; 
 	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void AddFirst(queue &l, Node *new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = i.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}


void RemoveHead(queue &l)
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

void Init(queue &S)
{ 
    S.pHead = NULL
    S.pTail = NULL;
}
char IsEmpty(queue &S)
{
    if(S.pHead == NULL)
    return 1;
    else
	 return 0;
}

void Push(queue &S, char x)
{
    Node* new_ele = GetNode(x);
    AddFirst(S, new_ele);
}

char Pop(queue &s)
{
    char x;
    if(IsEmpty(S)) 
    return NULL;
    x = S.pHead->Info;
    RemoveHead(S);
    return x;
}

char Top(queue &S)
{
    if(IsEmpty(S))
    return NULL;
    return S.pHead->Info;
}

int main()
{
    char str[]= "EAS*Y**QUE***ST***I*ON";

    char x;
    int i;

    queuee my_queue;
    Init (my_queue);

    printf("Chuoi goc: %s\n",str);
    printf("\n Ket qua in ra voi dong QUEUE: ");

    for(i=0; i< strlen(str); i++)
    {
        if (str[i]=='*')
        {
            x = Pop(my_queue);
            printf("%c",x);
        }
        else
        Push(my_queue, str[i]);
    }
    return 0;
}
