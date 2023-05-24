#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct Node
{
	char Info;
	Node* pNext;
}Node;

typedef struct stack
{
	Node* pHead;
	Node* pTail;
}stack;

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

void AddFirst(stack &l, Node *new_ele)
{
	if (l.pHead == NULL)
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

void RemoveHead(stack &l)
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

void Init(stack &S)
{ 
    S.pHead = NULL;
    S.pTail = NULL;
}

char IsEmpty(stack &S)
{
    if(S.pHead == NULL)
    return 1;
    else
	 return 0;
}

void Push(stack &S, char x)
{
    Node* new_ele = GetNode(x);
    AddFirst(S, new_ele);
}

char Pop(stack &S)
{
    char x;
    if(IsEmpty(S)) 
    return NULL;
    x = S.pHead->Info;
    RemoveHead(S);
    return x;
}

char Top(stack &S)
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

    stack my_stack;
    Init (my_stack);

    printf("Chuoi goc: %s\n",str);
    printf("\n Ket qua in ra voi dong STACK: ");

    for(i=0; i< strlen(str); i++)
    {
        if (str[i]=='*')
        {
            x = Pop(my_stack);
            printf("%c",x);
        }
        else
        Push(my_stack, str[i]);
    }
    return 0;
}

