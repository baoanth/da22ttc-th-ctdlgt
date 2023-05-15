#include <stdio.h>
#include<stdlib.h>


typedef struct Person
{
     int id;
     char fname[20];
     char lname[20];
}Person;
typedef struct Node
{
    Person Info; 
    Node* pNext;
}Node;

      typedef struct List
{
    Node *pHead;
    Node *pTail;
}List;
void Init( List &l)
{
	
	l.pHead=l.pTail;
}
  void GetNode(Person x)
{
    Node *p;
    p=new Node;
    if(p==NULL)
    {
        printf("erro!"); 
       
    }
    p->Info=x;
    p->pNext=NULL;
    
}
void AddFirst(List &l, Node * new_ele)
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
void PrintList(List l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%4d 30%S 40%S \n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}
void main()
{
	
    struct nguoi Per1 = { 1, " pham " , " tho "  };
    struct nguoi Per2 = { 2, " kim "  , " nan "  };
    struct nguoi Per3 = { 3 , "ngan"  ,   "phan" };

    Node* new_ele1  = GetNode(Per1);
    Node* new_ele2  = GetNode(Per2);
	Node* new_ele3   =GetNote(Per3);
	
	List my_list;
	
	 
	AddFirst(my_list, new_ele2);
	AddFirst(my_list, new_ele1);
	AddFirst(my_list, new_ele3);
	PrintList(my_list);

    return 0;
}




