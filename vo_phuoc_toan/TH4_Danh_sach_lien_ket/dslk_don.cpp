#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
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
    Node* pHead;
    Node* pTail;
}List;

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFist(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}
void Init(List &l)
{
    l.pHead = NULL;
	l.pTail = NULL;
}
void AddLast(List& l, Node* new_ele)
{
	if(l.Head==NULL)
	{
		l.Tail=new_ele;
	}
	else
	{
		l.Head->next_ele;
		l.Tail->new_ele;
	}
}
void PrintList(List l)
{
	Node* p=l.Head;
	while (p!=NULL)
	{
		printf("ID: %d, Ten: %s %s\n", p->info.id, p->info.fname, p->info.lname);
		p=p->next;
	}
}
Node* FindNodeByID(List l, int idx)
{
	Node* p=l.Head;
	while(p!=NULL && p->info.id!=idx)
	{
		p=p->next;
	}
	return p;
}
void AddNodeAfter(List &l, int idx,  Node* new_ele)
{
	Node* p=FindNodeByID(l,idx);
	if(p==NULL)
	{
		printf("Node with ID %d not found\n", idx);
		return;
	}
	if(p==l.Tail)
	{
		AddLast(l.new_ele);
	}
}
void AddNodeAfter(List &l, int idx, Node *new_ele)
{
	if(l.pHead==NULL)
	{
		l.phhead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail -> Next = new_ele;
		l.pTail = new_ele;
	}
}
void RemoveHead(List &l)
{
	if(l.Head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head==l.Tail)
	{
		free(l.Head);
		l.Head=NULL;
		l.Tail=NULl;
	}
	else
	{
		Node* p=l.Head;
		l.Head=l.Head->next;
		free(p);
	}
}
void RemoveLast(List &l)
{
	if(l.Head=NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head==l.Tail)
	{
		free(l.Head);
		l.Head=NULL;
		l.Tail=NULl;
	}
	else
	{
		Node* p=l.Head;
		while(p->next!=l.Tail)
		{
			p=p->next;
		}
		free(l.Tail);
		l.Tail = p;
		l.Tail -> next = NULL;
	}
}
void RemoveNode(List &l, int idx)
{
	if(l.Head=NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(l.Head->info.id  == idx)
	{
		RemoveHead(l);
		return;
	}
		Node* p=l.Head;
		while(p->next!=NULL && p->next->info.id !=idx)
		{
			p=p
		}
}



int main()
{
    struct Person per1 = {1, "vo", "Phuoc Toan" };
	struct Person per2 = {2, "Chau", "Thanh Thien" };
	struct Person per3 = {3, "Kieu", "Gia Thinh" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);


}

