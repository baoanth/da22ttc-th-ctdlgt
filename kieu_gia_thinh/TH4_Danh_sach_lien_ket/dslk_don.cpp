#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;

typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

//Viet ham GetNode(Person x)
Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

//Viet ham void AddFirst(List &l, Node *new_ele)
void AddFirst(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
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

//Viet ham void AddTail(List &l, Node *new_ele)
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

//Viet ham void InputNode(List &l)
void InputNode(List &l)
{
<<<<<<< HEAD
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
			printf("| %5d | %20s | %20s |\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;	
		}
	}
}
=======
    Person per_tam;
    printf("\nNhap node moi\n");
    
    printf("ID: ");
    scanf("%d", &per_tam.id);
	
	fflush(stdin);
    printf("First name: ");
    gets(per_tam.fname);
>>>>>>> 5d589f3b4e81d921ad8d3b294e7e052061cd23d1

	fflush(stdin);
    printf("Last name: ");
    gets(per_tam.lname);

    Node *new_ele = GetNode(per_tam) ;

    printf("\nChon vi tri cho nut moi: 1. Dau danh sach; 2.Cuoi danh sach  ");
    
    fflush(stdin);
	int chon=0;
	scanf("%d", &chon);
    switch (chon)
    {
        case 1: 
            AddFirst(l, new_ele );
            printf("Da them new_ele vao dau danh sach\n");
            break;
        case 2:
            AddTail(l, new_ele);
            printf("Da them new_ele vao cuoi danh sach\n");
            break;
        default:
            AddTail(l, new_ele );
            printf("Ban nhap lua chon xa lo; Da them new_ele vao cuoi danh sach\n");
            break;
    }
}

//Viet ham void RemoveHead(List &l)
void RemoveHead(List &l)
{
    Node *p;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}

//Viet ham void RemoveAfter(List &l, Node *q)
void RemoveAfter(List &l, Node *q)
{
    Node *p;
    if (q != NULL)
    {
        p = q->pNext;
        if (p != NULL)
        {
            if (p == l.pTail)
                l.pTail = q;
            q->pNext = p->pNext;
            delete p;
        }
    }
    else
        RemoveHead(l);
}

//Viet ham int RemoveNode(List &l, int idx)
int RemoveNode(List &l, int idx)
{
    // Tim nut co id = idx
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
    {
        return 0;
        printf("Khong tim thay Node co id = %d", idx);
    }
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

//Viet ham Node *FindNodeByID(List l, int idx)
Node *FindNodeByID(List l, int idx)
{
    Node *p;
    p = l.pHead;

    while ((p != NULL) && (p->Info.id != idx))
        p = p->pNext;

    return p;
}

//Viet ham void Init(List &l)
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham void PrintNode(Node *p)
void PrintNode(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

//Viet ham void PrintNode(Node *p)
void PrintList(List &l)
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


//Ham main
int main()
{
    struct Person per1 = {1, "Kieu", "Gia Thinh"};
    struct Person per2 = {2, "Nguyen", "Tra My"};
    struct Person per3 = {3, "Con", "Vit"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    
	List my_list;
    Init(my_list);

//   AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
<<<<<<< HEAD
    
    AddTail(my_list, new_ele1);
=======

//    AddTail(my_list, new_ele1);
>>>>>>> 5d589f3b4e81d921ad8d3b294e7e052061cd23d1
//    AddTail(my_list, new_ele2);
//    AddTail(my_list, new_ele3);

    PrintList(my_list);
    
	int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    
	Node *node_kq = FindNodeByID(my_list, idx);
    if (node_kq != NULL)
        PrintNode(node_kq);
    else
        printf("Tim khong thay node co id %d", idx);

    // PrintList(my_list);

    printf("\nNhap id can xoa ");
    scanf("%d", &idx);
    
	int kq = RemoveNode(my_list, idx);
    if (kq!=0)    
        printf("Da xoa Node co id = %d", idx);
    else
        printf("Khong the xoa nut co id = %d", idx);
        
    printf("\nDanh sach sau thao tac \n"); 

    PrintList(my_list);

    InputNode(my_list);
    InputNode(my_list);
    InputNode(my_list);

    PrintList(my_list);

    return 0;
}
