#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct Person
{
    int tuoi;
    char hoten[20];
    char diachi[20];
    char benh[20];
   
} Person;

typedef struct Node
{
    Person Info;
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

Node* GetNode ( Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf ("khong du bo nho");
        return 0;
    }
    p -> Info = x ;
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

void EnQueue ( Queue &s, Person x )
{
	Node* new_ele = GetNode (x);
    InsertTail (s, new_ele);
}

void RemoveHead(Queue &s)
{
	Node *p;
	Person x;
	if ( s.pHead != NULL)
	{
		p = s.pHead; 
		s.pHead = s.pHead->pNext;
		delete p;
		if(s.pHead == NULL) s.pTail = NULL;
	}

}

void InputNode(Queue &s)
{
	Person per_tam;
	printf ("\n nhap thong tin banh nhan: ");
	printf ("\n so thu tu: ");
	scanf ("%d", &per_tam.id);
	
	fflush(stdin);
	printf ("\n First name: \n");
	gets(per_tam.fname);
	
	fflush(stdin);
	printf ("\n Last name: \n");
	gets(per_tam.lname);
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

void PrintQueue ( Queue s )
{
   Node *p = s.pHead;
   while ( p!=NULL )
   {
   		printf ("%d %s %s %s\n", p -> Info.hoten, p -> Info.tuoi, p-> Info.diachi, p->Info.benh);
   		p = p -> pNext;
   }
}


int main()
{  
    /*int n,i;
    printf ("\n So benh nhan la: ");
    scanf ("%d", &n);
    for (i=1; i<=n; i++)
    {
      printf ("%d %s %d %s %s", i, ho)
	
    }*/
	
	Queue my_queue;
	Init (my_queue);
	
	/*AddFirst (my_list, new_ele1);
	AddFirst (my_list, new_ele2);
	AddFirst (my_list, new_ele3);
	
	/*AddTail (my_list, new_ele1);
	AddTail (my_list, new_ele2);
	AddTail (my_list, new_ele3);*/
	
	PrintQueue (my_queue);
    	
	return 0;
}
