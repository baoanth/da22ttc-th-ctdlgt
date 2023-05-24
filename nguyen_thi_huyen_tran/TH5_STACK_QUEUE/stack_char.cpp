#include <stdio.h>
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
} stack;

Node* GetNode( char x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho");
        return NULL;
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

void Init( stack &s)
{
	s.pHead = s.pTail = NULL;
}

char IsEmpty(stack &S)
{
    if (S.pHead == NULL) // stack rỗng
        return 1;
    else 
	    return 0;
}



void AddFirst ( stack &l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead= new_ele;
		l.pTail= l.pHead;

	}
  else
	{
		new_ele -> pNext = l.pHead;
		l.pHead =  new_ele ;
	}
}		

void Push(stack &S, char x )
{
	Node* new_ele = GetNode(x);
    AddFirst(S, new_ele);
}

void RemoveHead(stack &l)
{
	Node *p;
	char X;
	
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
    }
}


char Pop(stack &S)
{ 
    char x;
    if(IsEmpty(S)) 
    return NULL;

    x= S.pHead->Info;
     RemoveHead(S);
return x;
}

char Top(stack &S)
{ 
    if(IsEmpty(S)) 
    return NULL;
    return  S.pHead->Info;
	  
}

int main()
{
    char str[]= "EAS*Y**QUE***ST***I*ON";

    int x;
    int i;

    stack my_stack;
    Init (my_stack);

    printf("Chuoi goc: %s\n", str);
    printf("Ket qua in ra voi stack: ");

    for (i=0; i<strlen(str); i++)
    {
        if (str[i]=='*')
        {
            x=Pop(my_stack);
            printf("%c",x);
        }
        else
        Push(my_stack, str[i]);
    }
    return 0;

}
