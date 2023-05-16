#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

//Khai bao Node voi Info la kieu Person
typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

//Khai bao danh sach lien ket don List voi thanh phan la Node 
typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

//Viet ham khoi tao danh sach lien ket 
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham tao mot Node moi tu cau truc x kieu  Person
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

//Viet ham them mot Node mo vao dau danh sach
void AddFirst(List &l, Node* new_ele)
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

//Ham duyet va in danh sach ra man hinh
void PrintList(List &l)
{
	if(l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while(p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;	
		}
	}
}

//Viet ham chen vao cuoi danh sach
void AddTail(List &l, Node *new_ele)
{
	if(l.pHead = NULL)
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

//Viet ham void RemoveHead(List &l)
void RemoveHead(List &l)
{
	Node *p;
	
	if(l.pHead !=NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead -> pNext;
		delete p;
		if(l.pHead == NULL)
		l.pTail = NULL;
	}
}

//Viet ham void RemoveAfter(List &l, Node *q)
void RemoveAfter(List &l, Node *q)
{
	Node *p;
	
	if(q!= NULL)
	{
		p = q -> pNext;
		if(p!=NULL)
		{
			if(p==l.pTail)
			l.pTail = q;
			q->pNext = p->pNext;
			delete p;
		}
	}
}

//Viet ham cai dat int RemoveNode(List &l, idx)
int RemoveNode(List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while(p!=NULL)
	{
		if(p->Info.id = idx)
		break;
		
		q = p; 
		p = p->pNext;
	}
	if(p == NULL)
	return 0;//Khong tim thay Idx
	
	if(p == l.pTail)
	{
		if(p==l.pTail)
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

//Viet ham Node* FindNodeByID(List l, int idx 
Node* FindNodeByID(List l, int idx) 
{
	Node *p;
	p=l.pHead;
	
	while((p!=NULL) && (p->Info.id !=idx))
		p=p->pNext;
		
		return p;
}

//Viet ham void PrintNode(Node *p)
void PrintNode(Node *p)
{
	printf("%3d | %20s | %10s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

//Ham main
int main()
{
    struct Person per1 = {1, "Kieu", "Gia Thinh"};
	struct Person per2 = {2, "Nguyen Thi", "Tra My"};
	struct Person per3 = {3, "Con", "Vit"};
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
    
//    AddTail(my_list, new_ele1);
//    AddTail(my_list, new_ele2);
//    AddTail(my_list, new_ele3);
    
    PrintList(my_list);
    
    int idx;
    printf("\nNhap ID can tim: ");
    scanf("%d", &idx);
    printf("\n");
    Node* KQ = FindNodeByID(my_list, idx);
    if(KQ !=NULL)
    	PrintNode(KQ);
	else 
	printf("\nKhong tim thay Node co ID: %d", idx);
	
	return 0;
}

