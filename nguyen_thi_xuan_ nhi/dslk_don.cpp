#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person
{
   int id;
   char fname[20];
   char lname[20];
}Person;
typedef struct Node
{
    person Info;
    Node* pNext;
}Node;
typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;
Node *new_ele;
void Init(List &l)
{
    l.pHead=l.pTail=NULL;
    
}

void GetNode(person x)
{
    Node *p;
    p=new Node;
    if(p==NULL)
    {
        printf("\n khong du dung liuong");
        
    }
    p->Info = x;
    p->pNext = NULL;
    
}
void AddFirst(List &l,Node * new_ele)
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

void printList(List l)
{
    Node *p = l.pHead;
    while(p!= NULL)
    {
        printf("%4s%6s%3s\n",p->Info.id,p->Info.fname,p->Info.lname);
        p=p->pNext;
    }
}







int main()
{
	
    struct person per1 = {1,"nguyen","thi"};
    struct person per2 = {2,"xuan","thi"};
     Node *new_ele0 = GetNode(per1);
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    List my_list;
    Init(my_list);
    printList(my_list);
    return 0;
}
