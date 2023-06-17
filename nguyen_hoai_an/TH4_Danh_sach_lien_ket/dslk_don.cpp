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

Node* FindNodeByID (List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;	
}

void AddNodeAfter(List &l, Node *q, Node * new_ele, int idx)
{	
	if(q!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if( q == l.pTail)
			l.pTail = new_ele;
	}
	else
		AddFirst(l, new_ele);
}

void RemoveHead(List &l)
{
	Node *p;

	if(l.pHead != NULL)
	{
		p = l.pHead; 
		
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead == NULL) l.pTail = NULL;
	}
}

void RemoveAfter(List &l, Node *q)
{
	Node *p;
	if (q!= NULL)
	{
		p = q->pNext;
		if(p!= NULL)
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
	while(p!=NULL)
	{
		if(p->Info.id == idx) break;
		q = p;
		p = p->pNext;
	}	
	
	if(p == NULL) return 0;
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

//void InputNode(List &l)
//{
//	Person p;
//    printf("Nhap thong tin :\n");
//    printf("ID: ");
//    scanf("%d", &p.id);
//    fflush(stdin);
//    printf("First name: ");
//    gets(p.fname);
//    fflush(stdin);
//    printf("Last name: ");
//    gets(p.lname);
//
//    Node *new_node = GetNode(p);
//
//    int idx;
//    printf("Nhap vi tri can them: ");
//    scanf("%d", &idx);
//
//    AddNodeAfter(l, idx-1, new_node);
//
//    printf("Da them vao danh sach!\n");
//}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%5d %15s %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%5d %15s %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

int main()
{
	struct person per1 = {1, "An", "Nguyen"};
	struct person per2 = {2, "Vinh", "Pham"};
	struct person per3 = {3, "Tong", "Nguyen"};
    struct person per4 = {4, "Vinh", "Nguyen"};
    struct person per5 = {5, "Tho", "Huynh"};

 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
    Node* new_ele4  = GetNode(per4);
    Node* new_ele5  = GetNode(per5);
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
    AddTail(my_list, new_ele4);
    AddTail(my_list, new_ele5);
   
	PrintList(my_list);
	
	int idx;
	printf("\nNhap ID can tim : ");
	scanf("%d", &idx);

	Node* KQ = FindNodeByID(my_list, idx);
	if(KQ != NULL)
		PrintNode(KQ);
	else
		printf("\nKhong tim thay Node co id : %d", idx);
		
//		Node *new_ele5 = GetNode(per5);
//        AddNodeAfter(my_list, idx, new_ele5);
		
		
	printf("\nNhap ID can xoa : \n");
	scanf("%d", &idx);
	
	int kq = RemoveNode(my_list, idx);
	
	if(kq!=0)
		printf("Da xoa Node co id = %d\n", idx);
	else	
		printf("Khong the xoa Node.\n");
		
		printf("Danh sach sau khi thuc hien:\n");
		PrintList(my_list);
		
		
	return 0;
}

