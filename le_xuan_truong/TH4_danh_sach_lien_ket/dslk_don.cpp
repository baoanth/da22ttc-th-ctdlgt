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
<<<<<<< HEAD

=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
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
<<<<<<< HEAD

=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
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
=======
<<<<<<< HEAD
	
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
	struct person per3 = {3, "Le Thach Hue", "Meo"};

	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======

=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
<<<<<<< HEAD
<<<<<<< HEAD
    AddTail(my_list, new_ele2);
<<<<<<< HEAD
    AddTail(my_list, new_ele3);
   
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    AddTail(my_list, new_ele2);
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
    AddFirst(my_list, new_ele2);
=======
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
    
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
	PrintList(my_list);
	
	return 0;
}

