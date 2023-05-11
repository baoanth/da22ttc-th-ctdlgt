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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (l.pHead == NULL)
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
	if (l.pTail == NULL)
=======
	if (l.pHead == NULL)
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
	if (l.pTail == NULL)
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		p = l.pHead;
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
		p = l.pTail;
=======
		p = l.pHead;
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
		p = l.pTail;
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> b8140ab904ab6152d12532e648e1379e71b9184d
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
	
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
