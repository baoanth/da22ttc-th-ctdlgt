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
        return 0; // Không tìm thấy idx
        printf("Khong tim thay Node co id = %d", idx);

    }
    if (q != NULL)
    {
        if (p == l.pTail) // Nut can xoa la pTail
            l.pTail = q; 
        q->pNext = p->pNext;
        delete p;
    }
    else // p là phần tử đầu danh sách
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;  
}

Node *FindNodeByID(List l, int idx)
{
    Node *p;
    p = l.pHead;

    while ((p != NULL) && (p->Info.id != idx))
        p = p->pNext;

    return p;
}

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
<<<<<<< HEAD
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
=======
    if (l.pHead == NULL)
    {
        printf("Danh sach rong\n");
    }
    else
    {
        Node *p;
        p = l.pHead;
        while (p != NULL)
        {
            printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
            p = p->pNext;
        }
    }
>>>>>>> 6925b7cc4dd77deded6c9e5c526061a2d9449055
}

int main()
{
    struct Person per1 = {1, "Nguyen", "Le Hoa Binh"};
    struct Person per2 = {2, "Le", "Binh"};
    struct Person per3 = {3, "Tran", "Hoa"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    // AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);

    AddTail(my_list, new_ele1);
    // AddTail(my_list, new_ele2);
    // AddTail(my_list, new_ele3);

    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim ");
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
    printf("Danh sach sau thao tac \n");
    PrintList(my_list);
    return 0;
}
