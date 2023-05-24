#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
  Node* GetNode(Person x)
{
    Node *p;
    p=new Node;
    if(p==NULL)
    {
        printf("erro!"); 
       return NULL;
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
		printf("%4d 30%S 20%S \n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}
int main()
{
	
    struct  per1={"pham"   ,"tho" }
    struct  Per2 ={" kim " , " nan " };
    struct  Per3 ={"ngan"  , "phan"};

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
void AddTail(List &l,Node *new_ele)
{
    if(l.pHead==NULL)
    {
        l.pHead=new_ele;
        l.pTail=l.pHead;
    }
    else
    {
        l.pTail->Next=new_ele;
        l.pTail=New_ele;
    }
}

Node* FindNodeAfter(List &l,int idx)
{
	Node *p;
	p=l.pHead;
	while ((p!=NULL)&&(p->Infno !=idx))
	p=p->pNext;
	return p;
}
void AddNodeAfter(List &l, int idx)
{
	if (l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
else
    {
        new_ele->pNext=l.pHead;
	    l.pHead=new_ele;
   }
}	 
  void RemoveHead(List &l)
{
     Node *p;
     Data x;
     if ( l.pHead != NULL)
{
     p = l.pHead; x = p->data;
     l.pHead = l.pHead->pNext;
     delete p;
     if(l.pHead == NULL) l.pTail = NULL;
}
    return x;
}
	void RemoveLast(List &l)
{
	Node*p;
if ( q != NULL)
{
p = q ->pNext ;
if ( p != NULL)
{
if(p == l.pTail)
l.pTail = q;
q->pNext = p->pNext;
delete p;
}
else
RemoveHead(l);
}



