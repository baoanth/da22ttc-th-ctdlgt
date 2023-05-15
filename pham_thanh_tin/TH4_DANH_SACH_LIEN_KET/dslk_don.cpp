#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

typedef struct Node
{
    Person Infor;
    Node* pNext;
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode(Person x)
{
	Node* p;
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->Infor=x;
	p->pNext=NULL;
	return p;	
}

void AddFirst(List &l, Node* new_ele)
{
    if(l.pHead==NULL)
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

void AddTail(List &l, Node *new_ele)
{
    if (l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

Node* FindNodeByID(List l, int idx)
{
	Node* p=l.pHead;
	while(p!=NULL && p->Infor.id!=idx)
	p=p->pNext;
	return p;
}

void Output(List l)
{
	    Node* p;
	    p=l.pHead;
	    if(p!=NULL)
	    {
	        printf("%3d %10s %12s \n", p->Infor.id, p->Infor.fname, p->Infor.lname);
	        p = p->pNext;
		}
}

void PrintList(List l)
{
    if(l.pHead==NULL)
    {
	    printf("Danh sach rong\n");
	}
	else
	{
	    Node* p;
	    p=l.pHead;
	    while(p!=NULL)
	    {
	        printf("%3d %10s %12s \n", p->Infor.id, p->Infor.fname, p->Infor.lname);
	        p = p->pNext;
		}
	}
}

int main()
{
    struct Person per1= {1, "Pham", "Thanh Tin"};
    struct Person per2= {2, "Pham", "Van Thach"};
    struct Person per3= {3, "Nguyen", "Thi Kim Le"};
    
    Node* new_ele1 = GetNode(per1);
    Node* new_ele2 = GetNode(per2);
    Node* new_ele3 = GetNode(per3);
    
    List my_list;
    Init(my_list);
    
    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    
    
    AddTail(my_list, new_ele3);
    
    PrintList(my_list);
    int idx;
    printf("Nhap id can tim: \n");
    scanf("%d", &idx);
    Output(my_list, *idx);
}







