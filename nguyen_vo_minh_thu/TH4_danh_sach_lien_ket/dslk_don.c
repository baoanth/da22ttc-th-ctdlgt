#include<stdio.h>
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
		Node* pHead;
		Node* pTail;
	}List;

	Node* GetNode(Person x)
	{
		Node *p;
		p = new Node;
		if (p==NULL)
		{
			printf("khong du bo nho de cap phat cho nut moi");
			exit(1);
		}
		p->Info = x;
		p->pNext = NULL;
		return p;
	}
	
	void AddFist(List &l; Node* new_ele)	
	{
		if (l.pHead == NULL)
		{
			l.pHead = new_
		}
	}

