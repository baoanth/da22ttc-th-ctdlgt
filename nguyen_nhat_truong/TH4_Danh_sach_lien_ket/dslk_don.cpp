
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
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void AddTail(List &l, Node *new_ele)
{
<<<<<<< HEAD
<<<<<<< HEAD
	if (l.pHead == NULL)
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (l.pTail == NULL)
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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
<<<<<<< HEAD
>>>>>>> e93a10bcd9e9120c687b7176025727b939abbd6b
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
	if (l.pTail == NULL)
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
<<<<<<< HEAD
		p = l.pHead;
=======
<<<<<<< HEAD
<<<<<<< HEAD
		p = l.pTail;
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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
<<<<<<< HEAD
>>>>>>> e93a10bcd9e9120c687b7176025727b939abbd6b
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
		p = l.pTail;
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}
	}
=======
=======
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885
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

void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
    p = p->pNext;
}

Node *FindNodeByID(List l, int idx)
{
    Node *p = l.pHead;
    while ((p != NULL) && (p->Info.id != idx))
    {
        p = p->pNext;
    }
    return p;
}

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
    Person p;
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
    struct Person per1 = {1, "giap", "at"};
    struct Person per2 = {2, "binh", "dinh"};
    struct Person per3 = {3, "mau", "ky"};
    struct Person per4 = {4, "canh", "Tan"};
    struct Person per5 = {5, "nham", "quy"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);
    Node *new_ele5 = GetNode(per5);

    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele3);

    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele4);

    PrintList(my_list);

    int idx;
    printf("Nhap id :");
    scanf("%d", &idx);

    Node *node_kq =
        FindNodeByID(my_list, idx);
    if (node_kq != NULL)
    {
        PrintNode(node_kq);
    }
    else
    {
        printf("Khong tim thay id %d\n", idx);
    }

        AddNodeAfter(my_list, idx, new_ele5);

    printf("Sau khi them nut : \n");
    printf("\n");
    PrintList(my_list);

    RemoveHead(my_list);
    printf("Sau khi xoa nut dau : \n");
    printf("\n");

    PrintList(my_list);

    RemoveLast(my_list);
    printf("Sau khi xoa nut cuoi : \n");
    printf("\n");

    PrintList(my_list);

    printf("Nhap id can xoa:");
    scanf("%d", &idx);
    RemoveNode(my_list, idx);
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    InputNode(my_list);
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    return 0;
}