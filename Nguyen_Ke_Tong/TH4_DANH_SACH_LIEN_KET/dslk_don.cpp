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
//khoi tao danh sach lien ket
void Init(List &l)
{ 
    l.pHead = l.pTail = NULL;
}
//khai bao Node voi info la kieu person
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
//chen cao dau danh sach
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
//chen vao cuoi danh sach
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
//tim kiem nut boi id voi gia tri la idx
Node* FindNodeByID (List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;	
	
}

void PrintNode(Node *p)
{
	printf("%3d | %5s  %s\n",p->Info.id, p->Info.fname, p->Info.lname);
}
//duyet va in ra mang hinh
void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%3d | %5s  %s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}
//them mot nut sau nut co ID la idx
void AddNodeAfter(List &l, int idx, Node *new_ele5)
{
    Node *q = FindNodeByID(l, idx);

    if (q != NULL && new_ele5 != NULL)
    {
        new_ele5->pNext = q->pNext;
        q->pNext = new_ele5;
        if (q == l.pTail)
            l.pTail = new_ele5;
    }
    else
        AddFirst(l, new_ele5);
}
//xoa nut dau
void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
    }
}
//xoa nut cuoi
void RemoveLast(List &l)
{
    if (l.pTail != NULL)
    {
        Node *p = l.pHead;
        Node *q = NULL;
        while (p->pNext != NULL)
        {
            q = p;
            p = p->pNext;
        }
        if (q != NULL)
            q->pNext = NULL;
        else
            l.pHead = NULL;
        l.pTail = q;
        delete p;
    }
}
//xoa nut co ID la idx
int RemoveNode(List &l, int idx)
{
    Node *p = l.pHead;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->Info.id == idx)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == l.pTail)
            l.pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;
}

void InputNode(List &l)
{
    person p;
    printf("Nhap thong tin nguoi:\n");
    printf("ID: ");
    scanf("%d", &p.id);
    fflush(stdin);
    printf("First name: ");
    gets(p.fname);
    fflush(stdin);
    printf("Last name: ");
    gets(p.lname);

    Node *new_node = GetNode(p);

    int idx;
    printf("Nhap vi tri can them: ");
    scanf("%d", &idx);

    AddNodeAfter(l, idx - 1, new_node);

    printf("Da them nguoi vao danh sach!\n");
}

int main()
{
	struct person per1 = {1, "Nguyen Ke", "Tong"};
	struct person per2 = {2, "Nguyen Thi Huyen", "Tran"};
	struct person per3 = {3, "Lam Tri Thuc", "Thuc"};
	struct person per4 = {4, "Nguyen Thanh", "Vinh"}; 
	struct person per5 = {5, "Pham Thanh", "Tinh"};
	
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
  	Node* new_ele4  = GetNode(per4);
    Node* new_ele5  = GetNode(per5);

    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele3);

    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele4);
   
	PrintList(my_list);
	
	printf("--------------------------------------");
	
	int idx;
	printf("\nNhap ID can tim : ");
	scanf("%d",&idx);
	
	Node* KQ = FindNodeByID(my_list, idx);
	if(KQ != NULL)
	{
        PrintNode(KQ);
        printf("--------------------------------------\n");
    }
    else
    {
        printf("Khong tim thay id %d\n", idx);
        printf("--------------------------------------\n");
    }

    AddNodeAfter(my_list, idx, new_ele5);

    printf("Sau khi them nut : \n");
    printf("\n");
    PrintList(my_list);

    RemoveHead(my_list);
    printf("--------------------------------------\n");
    printf("Sau khi xoa nut dau : \n");
    printf("\n");

    PrintList(my_list);

    RemoveLast(my_list);
    printf("--------------------------------------\n");
    printf("Sau khi xoa nut cuoi : \n");
    printf("\n");

    PrintList(my_list);

    printf("Nhap id can xoa:");
    scanf("%d", &idx);
    RemoveNode(my_list, idx);
    printf("--------------------------------------\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    InputNode(my_list);
    printf("--------------------------------------\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);
	
	return 0;
}

