#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Node
{
    char Info;
    Node *pNext;
}Node;

typedef struct Stack
{
    Node *pHead;
    Node *pTail;
}Stack;

void Init(Stack &s)
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
void AddFirst(Stack &s, Node* new_ele)
{
    if(s.pHead==NULL)
    {
	    s.pHead=new_ele;
	    s.pTail=s.pHead;
	}
	else
	{
	   new_ele->pNext=s.pHead;
	   s.pHead=new_ele;
	}
}

void RemoveHead(Stack &s)
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
char IsEmpty(Stack &s)
{
    if(s.pHead == NULL)
        return 1;
    else return 0;
}

void Push(Stack &s, char x)
{
    Node * new_ele = GetNode(x);
    AddFirst(s, new_ele);
}

char Pop(Stack &s)
{
    char x;
    if(IsEmpty(s)) 
        return NULL;
        x = s.pHead->Info;
    RemoveHead(s);
    return x;
}

char Top (Stack &s)
{
    if(IsEmpty(s)) return NULL;
    return s.pHead->Info;
}

int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";
    int i;
    char x;
    Stack my_stack;
    Init(my_stack);

    printf("Chuoi nguon: %s\n",str);
    printf("\n Ket qua in ra voi Stack:");

    for(i=0; i<strlen(str); i++)
    {
        if(str[i]=='*')
        {
            x = Pop(my_stack);
            printf("%c", x);
        }
        else 
            Push(my_stack,str[i]);
    }
    return 0;
}

