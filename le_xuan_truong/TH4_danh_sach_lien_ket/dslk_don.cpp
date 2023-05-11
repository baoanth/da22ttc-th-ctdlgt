#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int id;
    char fname[20];
    char lname[20];
}person;

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

Node* GetNode(person x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho !"); 
		return NULL; 
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
		l.pTail  = l.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
void AddTail(List &l, Node *new_ele)
{
	if (l.pHead == NULL)
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

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

int main()
{
	struct person per1 = {1, "Le Xuan", "Truong"};
	struct person per2 = {2, "Thach Thi Hue", "Trinh"};
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
	
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
	struct person per3 = {3, "Le Thach Hue", "Meo"};
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
<<<<<<< HEAD
    AddFirst(my_list, new_ele2);
=======
<<<<<<< HEAD
<<<<<<< HEAD
    AddTail(my_list, new_ele2);
=======
<<<<<<< HEAD
    AddFirst(my_list, new_ele2);
=======
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
    
	PrintList(my_list);
	
	return 0;
}

