#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char Info;
    Node* pNext;
} Node;

typedef struct Stack
{
    Node* pHead;
    Node* pTail;
} Stack;


void Init ( Stack &s )
{
    s.pHead = s.pTail = NULL;
}

char IsEmpty(Stack &s)
{
	if (s.pHead == NULL) 
	return 1;
	else 
	return 0;
}

void RemoveHead ( Stack &s )
{
	Node *p;
	char x;
	if ( s.pHead != NULL)
	{
		p = s.pHead; 
		s.pHead = s.pHead->pNext;
		delete p;
		if(s.pHead == NULL) s.pTail = NULL;
	}
	
}

Node* GetNode ( char x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf ("khong du bo nho");
        return 0;
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

 void InsertFirst ( Stack &s, Node *new_ele )
{
    if ( s. pHead == NULL )
    {
        s.pHead = new_ele;
        s.pTail = s.pHead;
    }
    else 
    {
        new_ele -> pNext = s.pHead;
        s.pHead = new_ele;
    }
}


void Push ( Stack &s, char x )
{
	Node* new_ele = GetNode (x);
    InsertFirst (s, new_ele);
}

char Top ( Stack &s )
{ 
    if(IsEmpty(s)) 
    return NULL;
    return s.pHead -> Info;
}

char Pop ( Stack &s )
{ 
    char x;
    if(IsEmpty (s) )
    return NULL ;
    x = s.pHead -> Info;
	RemoveHead (s) ;
    return x ;
}

int main()
{
    char str[] = " EAS*Y**QUE***ST***I*ON ";
    int i;
    char x;
    
    Stack my_stack;
    Init (my_stack);
    
    printf ("\n Chuoi ban dau la: %s \n", str);
    printf ("\n ket qua in ra man hinh la: ");
    
    for (i=0; i < strlen(str); i++)
    {
    	if (str[i] == '*')
    	{
    		x = Pop (my_stack);
    		printf ("%c", x);
    	}
    	else
    		Push ( my_stack, str[i] );
    }
    	
	return 0;
}
