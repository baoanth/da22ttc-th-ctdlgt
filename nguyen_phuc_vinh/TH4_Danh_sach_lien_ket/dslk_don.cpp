#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Person
{
    int id;
    char fname[30];
    char lname[30];
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

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node* Get_Node(Person x)
{
	Node *p;
	p = new Node;
	
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return 0;
	}
	p->Info=x;
	p->pNext=NULL;
	
	return p;
}

void Print_Node(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
}

void Print_List(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
			p = p->pNext;
		}		
	}
}

void Add_First(List &l, Node* new_ele)
{
	if(l.pHead=NULL)
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

void Add_Tail(List &l, Node* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail=new_ele;
	}
}

void Input_Tail(List &l)
{
	int n;
	Person x;
}

Node* FindNodeByID(List l, int idx)
{
	Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p->Info.id !=idx))
        p = p->pNext;

    return p;
}

void Add_After(List &l, Node *q, Node *new_ele)
{
	if(q!=NULL && new_ele!=NULL)
	{
		new_ele->pNext=q->pNext;
		q->pNext=new_ele;
		if(q==l.pTail)
			l.pTail=new_ele;
	}
	else
	{
		Add_First(l, new_ele);
	}
}

void RemoveHead(List &l)
{
	Node *p;

	if(l.pHead!=NULL)
	{
		p=l.pHead;
		l.pHead=l.pHead->pNext;
		delete p;
		if(l.pHead==NULL)
		l.pTail=NULL;
	}
}

void RemoveLast(List &l, Node *q)
{
	Node *p;
	if(q!=NULL)
	{
		p=q->pNext;
		if(p!=NULL)
		{
			if(p==l.pTail)
			l.pTail=q;
			q->pNext=p->pNext;
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
	
	while(p!=NULL)
	{
		if(p->Info.id==idx)
		break;
		q=p;
		p=p->pNext;
	}
	if(p==NULL)
		return 0;
	if(q!=NULL)
	{
		if(p==l.pTail)
			l.pTail=q;
		q->pNext=p->pNext;
		delete p;	
	}
	else
	{
		l.pHead=p->pNext;
		if(l.pHead==NULL)
			l.pTail=NULL;
	}
	return 1;
}

void InputNode(List &l)
{
	Person p;
	
	printf("NHAP THONG TIN PERSON:\n");
	printf("Nhap First Name: ");
	gets(p.fname);
	printf("Nhap Last Name: ");
	gets(p.lname);
	printf("Ban muon them vao vi tri so: ");
	scanf("%d", &p.id);
}

int main()
{
	struct Person per1 = {1, "Nguyen", "Vinh"};
	struct Person per2 = {2, "Le", "Huy"};
	struct Person per3 = {3, "Tran", "Ngoc"};
	
	Node* new_ele1  = Get_Node(per1);
    Node* new_ele2  = Get_Node(per2);
	Node* new_ele3  = Get_Node(per3);
	List my_list;
	Init(my_list);
	
	Add_First(my_list, new_ele2);
    Add_First(my_list, new_ele3);
    Add_Tail(my_list, new_ele1);
    
    Print_List(my_list);
    int idx;
    printf("\nNhap id can tim ");
    scanf("%d", &idx);
    Node *node_kq  = FindNodeByID(my_list, idx);
    
    if (node_kq!=NULL)
        Print_Node(node_kq);
    else   
        printf("Tim khong thay node co id %d", idx);
    
    return 0;
}

