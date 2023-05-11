#include <stdio.h> 
#include <stdlib.h> 
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
		exit(1);
	}
	p->Info = x;
	p->pNext = NULL;
	return p;
}

void AddFirst(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
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
	l.pHead = l.pTail = NULL;
}

void PrintList(List &l)
{
	if (l.pTail == NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pTail;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}
	}
}

int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	
	List mylist;
	Init(mylist);
	
	AddFirst(mylist, new_ele1);
	AddFirst(mylist, new_ele2);
	AddFirst(mylist, new_ele3);	
	
	PrintList(mylist);
	
	return 0;
}
