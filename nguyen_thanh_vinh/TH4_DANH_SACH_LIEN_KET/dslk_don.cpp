#include <stdio.h>
#include <conio.h>
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
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void AddFirst(List &l, Node * new_ele)
{
if (l.pHead==NULL) 
{
l.pHead = new_ele;
l.pTail = l.pHead;
}
else
{
new_ele->pNext = l.pHead;
l.pHead = new_ele;
}
}

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}
void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

void InputNode(List &1)
{
	Person per_tam;
	printf("Nhap node moi\n");
	
	printf("ID: ");
	scanf("%d", &per_tam.id);
	
	printf("First name:");
	gets(per_tam.fname);
	
	printf("Last name: ");
	gets(per_tam.lname);
	
	Node *new_ele = GetNode(per_tam)
	
	printf("Ban muon them node vao vi tri nao\n");
	printf("1. Dau danh sach\n 2. Cuoi danh sach \n");
	int chon=0;
	
	switch (chon)
	{
		case 1:
			AddFirst(1, new_ele);
			printf("Da them new_ele vao dau danh sach");
			break;
		case 2;
		    AddLast(1, new_ele );
		    printf("Da them new_ele vao cuoi danh sach");
		    break;
		default:
			AddLast(1, new_ele);
			printf("Ban nhap lua chon sai; Da them new_ele vao dau danh sach");
			break;
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

Node *FindNodeById(List l, int idx)
{
    Node *p = l.pHead;
    while (p != NULL && p->Info.id != idx)
        p = p->pNext;
    return p;
}

int main()
{
    struct Person per1 = {1, "Thanh","Vinh"};
    struct Person per2 = {2, "Thanh","Nguyen"};
    struct Person per3 = {3, "Thanh","Ken"};
    
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    Node *tim_kiem = FindNodeById(my_list, idx);
    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay ten co id %d", idx);
    return 0;
}
