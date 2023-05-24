#include <stdio.h>
#include <conio.h>
#include <string.h>



typedef struct Node
{
	char Info; 
	Node* pNext; 
} Node;

typedef struct Stack
{
    Node *pHead;
    Node *pTail;
} Stack;


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
void AddFirst(Stack &l, Node* new_ele)
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
void Init(Stack &s)
{
    s.pHead = s.pTail = NULL;
}
char IsEmpty(Stack &s)
{
    if(s.pHead == NULL)
    return 1;
    else
	 return 0;
}

void RemoveHead(Stack &l)
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

void Push(Stack &s, char x)
{
	Node* new_ele = GetNode(x);
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
char Top(Stack &s)
{
	if(IsEmpty(s))
		return NULL;
	return s.pHead->Info;
}
int main()
{
	char str[] = "EAS*Y**QUE***ST**TION";
	int i;
	char x;
	Stack my_stack;
	Init(my_stack);
	
	printf("Chuoi ban dau: %s\n", str);
	printf("Ket qua in ra voi STACK:  ");
	
	for (i=0; i<strlen(str);i++)
	{
		if(str[i] =='*')
		{
			x = Pop(my_stack);
			printf("%c",x);
		}
		else
			Push(my_stack, str[i]);
	}
	return 0;
}
