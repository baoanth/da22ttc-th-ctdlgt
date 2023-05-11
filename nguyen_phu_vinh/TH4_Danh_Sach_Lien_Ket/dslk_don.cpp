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
    l.pHead = l.pTail = NULL;
}
void PrintList(List l)
{
	Node* p=l.pHead;
	while(p!=NULL)
	{
		printf("%d %s %s\n",p->Info.id,p->Info.fname,p->Info.lname);
		p=p->pNext;
	}
	
}
<<<<<<< HEAD
void AddTail (List &l,Node *new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail-> pNext = new_ele;
		l.pTail = new_ele;
	}
	
}
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39


int main()
{
    struct Person per1 = {1, "Nguyen", "Vinh" };
	struct Person per2 = {2, "Phu", "Vinh" };
	struct Person per3 = {3, "Vinh", "Phu" };
<<<<<<< HEAD
    struct Person per4 = {4, "vinh", "nguyen" };
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
<<<<<<< HEAD
    Node* new_ele4 = GetNode(per4);
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);
<<<<<<< HEAD
    
//	PrintList(my_list);
	
//	AddTail(my_list, new_ele1);
//   AddTail(my_list, new_ele2);


    AddTail(my_list, new_ele4);
	PrintList(my_list);
	
	return 0;
=======
	PrintList(my_list);

>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
}

