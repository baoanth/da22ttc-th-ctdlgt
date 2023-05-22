#include <stdio.h>
#include <stdio.h>
#include <string.h>
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;
typedef struct Node
{
    Person Info;
    Node* pNext;
} Node;
typedef struct List
{
    Node* pHead;
    Node* pTail;
} List;


void Init ( List &l )
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode (Person x)
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

void AddFirst ( List &l, Node *new_ele )
{
    if ( l. pHead == NULL )
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else 
    {
        new_ele -> pNext = l.pHead;
        l.pHead = new_ele;
    }
}

void PrintList ( List l )
{
   Node *p = l.pHead;
   while ( p!=NULL )
   {
   		printf ("%d %s %s \n", p -> Info.id, p -> Info.fname, p-> Info.lname);
   		p = p -> pNext;
   }
}

void AddTail (List &l, Node *new_ele)
{
    if (l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail -> pNext = new_ele;
        l.pTail = new_ele;
    }
}

void Output (List l)
{
    Node*p = l.pHead;
    while (p!=NULL)
    {
        p = p -> pNext;
    }
}

Node* FindNodeByID(List l, int idx, int id)
{
    Node*p = l.pHead ;
    while ( p != NULL && p -> Info.id != idx )
            p = p -> pNext;
    return p;
}

int main ()
{
	struct Person per1 = { 1, "dau", "tay"};
	struct Person per2 = { 2, "dua", "hau"};
	struct Person per3 = { 3, "vai", "thieu"};
	Node *new_ele0 = GetNode (per1);
	Node *new_ele1 = GetNode (per1);
	Node *new_ele2 = GetNode (per2);
	Node *new_ele3 = GetNode (per3);
	
	List my_list;
	Init (my_list);
	
	AddFirst (my_list, new_ele1);
	AddFirst (my_list, new_ele2);
	AddFirst (my_list, new_ele3);
	
	PrintList (my_list);
	
	int idx;
	printf ("nhap id can tim: \n");
	scanf ("%d",&idx);
	
	Node *new_ele = FindNodeByID(my_list, idx);
		
		
} 
