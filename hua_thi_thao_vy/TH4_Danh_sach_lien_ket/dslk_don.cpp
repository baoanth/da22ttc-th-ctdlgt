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

<<<<<<< HEAD
void AddTail (List &l, Node* new_ele)
{
	if(l.pHead==NULL)
=======
void AddTail(List &l, Node* new_ele)
{
	if (l.pHead==NULL)
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
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
Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p =l.pHead;
	
	while ((p!==NULL) && )
=======
void RemoveHead(List &l)
{
	Node *p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
		   l.pTail == NULL;
	}
}

void RemoveAfter(List &l, Node *q)
{
	Node *p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if(p == l.pTail)
			l.pTail = q;
			q->pNext = p->pNext;
			delete p;
		}
		
	}
	else
	RemoveHead(l);
}

int RemoveNode(List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while(p != NULL)
	{
		if(p->Info.id == idx)
		  break;
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
	{
	    return 0;
        printf("Khong tim thay Node co id = %d", idx);
    }
    if(q != NULL)
	{
		if(p == l.pTail)
		l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	else
	{
		l.pHead = p->pNext;
		if(l.pHead == NULL)
		   l.pTail = NULL;
	}
	return 1;
}

Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	if (l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}
	}
}


int main()
{
	struct Person per1 = {1, "Vy" , "Hua" };
	struct Person per2 = {2, "Truong" , "Nguyen" };
	struct Person per3 = {3, "Hoi" , "Nguyen" };
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	
	List mylist;
	Init(mylist);
	
<<<<<<< HEAD
	/*AddFirst(mylist, new_ele1);
	AddFirst(mylist, new_ele2);
	AddFirst(mylist, new_ele3);	*/
	
	AddTail(mylist, new_ele1);
	AddTail(mylist, new_ele2);
	AddTail(mylist, new_ele3);
=======
	AddFirst(mylist, new_ele1);
	/*AddFirst(mylist, new_ele2);
	AddFirst(mylist, new_ele3);*/	
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
	
	//AddTail(mylist, new_ele1);
	AddTail(mylist, new_ele2);
	AddTail(mylist, new_ele3);	
	
	PrintList(mylist);
	
	int idx;
	printf("\nNhap ID can tim : ");
	scanf("%d",&idx);
	printf("\n");
	Node* KQ = FindNodeByID(mylist, idx);
	if(KQ != NULL)
		PrintNode(KQ);
	else
		printf("\nKhong tim thay Node co ID : %d",idx);
	
	
	printf("\nNhap id can xoa ");
	scanf("%d", &idx);
	int kq = RemoveNode(mylist, idx);
	if (kq!=0)
	   printf("\nDa xoa Node co id = %d", idx);
	else
	   printf("\nKhong the xoa Node co id = %d", idx);
	printf("\nDanh sach sau khi thao tac\n");
	PrintList(mylist);
	
	return 0;
}
