#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char Info;
    Node* pNext;
} Node;

typedef struct Queue
{
    Node* pHead;
    Node* pTail;
} Queue;


void Init ( Queue &s )
{
    s.pHead = s.pTail = NULL;
}

char IsEmpty(Queue &s)
{
	if (s.pHead == NULL) 
	return 1;
	else 
	return 0;
}


void RemoveHead ( Queue &s )
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

 void InsertTail ( Queue &s, Node *new_ele )
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

void EnQueue ( Queue &s, char x )
{
	Node* new_ele = GetNode (x);
    InsertTail (s, new_ele);
}

char Front ( Queue &s )
{ 
    if(IsEmpty(s)) 
    return NULL;
    return s.pHead -> Info;
}

char DeQueue ( Queue &s )
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
    
    Queue my_queue;
    Init (my_queue);
    
    printf ("\n noi dung cua hang doi la: %s \n", str);
    printf ("\n ket qua in ra man hinh dang QUEUE la: ");
    
    for (i=0; i < strlen(str); i++)
    {
    	if (str[i] == '*')
    	{
    		x = DeQueue (my_queue);
    		printf ("%c", x);
    	}
    	else
    		EnQueue ( my_queue, str[i] );
    }
    	
	return 0;
}
