#include <stdio.h>
#include <stdio.h>
#include <string.h>
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;
typedef struct Node
{
    Person Info;
    Node* pNext;
} Node;
typedef struct List
{
    Node* pHead;
    Node* pTail;
} List;


void Init ( List &l )
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode (Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf ("khong du bo nho");
        return 0;
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

void AddFirst ( List &l, Node *new_ele )
{
    if ( l. pHead == NULL )
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else 
    {
        new_ele -> pNext = l.pHead;
        l.pHead = new_ele;
    }
}

void PrintList ( List l )
{
   Node *p = l.pHead;
   while ( p!=NULL )
   {
   		printf ("%d %s %s \n", p -> Info.id, p -> Info.fname, p-> Info.lname);
   		p = p -> pNext;
   }
}

<<<<<<< HEAD
void AddTail (List &l, Node *new_ele)
{
    if (l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail -> pNext = new_ele;
        l.pTail = new_ele;
    }
}

void Output (List l)
{
    Node*p = l.pHead;
    while (p!=NULL)
    {
        p = p -> pNext;
    }
}

Node* FindNodeByID(List l, int idx, int id)
{
    Node*p = l.pHead ;
    while ( p != NULL && p -> Info.id != idx )
            p = p -> pNext;
    return p;
}

=======
void AddTail(List &l, Node *new_ele)
{
	if (l.pHead==NULL)  
	{
		l.pHead = new_ele;
		l.pTail  = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele ;
	}	
}

void Output (Node* p)
{
	
	printf ("%d %s %s \n", p -> Info.id, p -> Info.fname, p-> Info.lname);
}
	
 Node* FindNodeByID (List l, int idx)
{
	Node* p = l.pHead;
	while ( p != NULL && p -> Info.id != idx)
	p = p -> pNext;
	return p;
}	

/*Data RemoveHead(List &l)
{
	Node *p;
	Data idx;
	if ( l.pHead != NULL)
	{
		p = l.pHead; idx = p->data;
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead == NULL) l.pTail = NULL;
	}
return idx;	
}*/


int RemoveNode(List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while( p != NULL)
	{
		if(p->Info.id == idx) break;
		q = p;
	    p = p->pNext;
	}
	if(p == NULL) 
	return 0; 
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


void InputNode(List &l)
{
	Person per_tam;
	printf ("\n nhap Node moi: ");
	printf ("\n nhap ID: ");
	scanf ("%d", &per_tam.id);
	
	fflush(stdin);
	printf ("\n First name: \n");
	gets(per_tam.fname);
	
	fflush(stdin);
	printf ("\n Last name: \n");
	gets(per_tam.lname);
	
	fflush(stdin);
	Node* new_ele = GetNode(per_tam);
	printf ("\n 1. Them vao dau danh sach; 2. Them vao cuoi danh sach");
	printf ("\n nhap lua chon cua ban: \n");
	
	fflush(stdin);
	int chon = 0;
	scanf ("%d",&chon);
	switch (chon)	
	{
		case 1:
			AddFirst (l, new_ele);
			printf ("\n Da them vao dau danh sach.");
			break;
		case 2:
			AddTail (l, new_ele);
			printf ("\n Da them vao cuoi danh sach.");
			break;
		default:
			AddTail (l, new_ele);
			printf ("\n Da them vao cuoi danh sach.");
			break;
		
	}
	
}
>>>>>>> 2ee17036c6e249051f957e7ed7214990e020feaf
int main ()
{
	struct Person per1 = { 1, "dau", "tay"};
	struct Person per2 = { 2, "dua", "hau"};
	struct Person per3 = { 3, "vai", "thieu"};
	Node *new_ele0 = GetNode (per1);
	Node *new_ele1 = GetNode (per1);
	Node *new_ele2 = GetNode (per2);
	Node *new_ele3 = GetNode (per3);
	
	List my_list;
	Init (my_list);
	
	AddFirst (my_list, new_ele1);
	AddFirst (my_list, new_ele2);
	AddFirst (my_list, new_ele3);
	
	/*AddTail (my_list, new_ele1);
	AddTail (my_list, new_ele2);
	AddTail (my_list, new_ele3);*/
	
	PrintList (my_list);
	
	int idx;
<<<<<<< HEAD
	printf ("nhap id can tim: \n");
	scanf ("%d",&idx);
	
	Node *new_ele = FindNodeByID(my_list, idx);
		
		
=======
	printf ("\n nhap vao ID can tim: ");
	scanf ("%d", &idx);
	Node* node_kq = FindNodeByID(my_list, idx);
	if (node_kq != NULL)
		Output (node_kq);
	else 
		printf ("\n khong tim thay ID %d\n", idx);
	
	//PrintList (my_list);
	
	printf ("\n nhap ID can xoa: ");
	scanf ("%d", &idx);
	int kq = RemoveNode(my_list, idx);
	if (kq != NULL)
		printf ("\n ID da xoa: %d \n",idx);
	else 
		printf ("\n khong the xoa ID %d\n", idx);
	printf ("\n Danh sach sau khi xoa: \n");
	PrintList (my_list);
	
	InputNode (my_list);
	InputNode (my_list);
	InputNode (my_list);
	PrintList (my_list);
	
	return 0;
		
>>>>>>> 2ee17036c6e249051f957e7ed7214990e020feaf
} 
