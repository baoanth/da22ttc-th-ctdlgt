#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Node
{
	char Info;
	Node* pNext;
}Node;

typedef struct Stack
{
	Node* pHead;
	Node* pTail;
}Stack;

Node* Get_Node(char x)
{
	Node *p;
	p = new Node;
	
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	
	p->Info=x;
	p->pNext=NULL;
	return p;
}

void Add_First(Stack &l, Node *new_ele)
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

void Remove_Head(Stack &l)
{
    Node *p;
    char x;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}

char Is_Empty(Stack &s)
{
    if (s.pHead == NULL)
        return 1;
    else 
		return 0;
}

void Init(Stack &s)
{
	s.pHead = NULL;
	s.pTail = NULL;
}

void Push(Stack &s, char x)
{
    Node* new_ele = Get_Node(x);
	Add_First(s, new_ele);
}

char Pop(Stack &s)
{   
    char x;
    if(Is_Empty(s) )
        return NULL;
    
	x = s.pHead->Info;  
    Remove_Head(s);
    
    return x;
}

char Top(Stack &s)
{ 
    if(Is_Empty(s)) 
        return NULL;
    return s.pHead->Info;
}

int main()
{
	 char  str[] = "EAS*Y**QUE***ST***I*ON";
    
    int i; 
    char x;
    Stack my_stack;
    Init(my_stack);
    
	printf("Chuoi goc: %s\n", str);
	printf("\n Ket qua in ra voi STACK:  ");
	
    for (i=0; i<strlen(str); i++)
    {
        if (str[i]=='*')
        {
           x = Pop(my_stack) ;
           printf("%2c", x);
        }
        else
            Push(my_stack, str[i]);
    }
    return 0;

}
