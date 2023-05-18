
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
#include <stdlib.h>

=======
#include <conio.h>
#include <string.h>
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
#include <stdio.h>
#include <conio.h>
#include <string.h>
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
=======
#include <stdio.h>
#include <conio.h>
#include <string.h>
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead == NULL)
=======
void AddFist(List &l, Node *new_ele)
=======
void AddFirst(List &l, Node *new_ele)
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
=======
void AddFirst(List &l, Node *new_ele)
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
Node *FindNodeByID(List l, int id)
{
    Node *node = l.pHead;
    while (node != NULL)
    {
        if (node->Info.id == id)
        {
            return node;
        }
        node = node->pNext;
    }
    return NULL;
=======
void PrintNode(Node* p)
{
	printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
    p = p->pNext;
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656

=======
=======
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885
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

<<<<<<< HEAD
<<<<<<< HEAD
    Node* node1 = GetNode(per2);
    AddFirst(my_list, node2);
<<<<<<< HEAD

    
=======
=======
=======
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885
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
<<<<<<< HEAD
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
=======
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885

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
    struct Person per1 = {1, "Kim", "Tri"};
    struct Person per2 = {2, "Thach", "Minh"};
    struct Person per3 = {3, "Kim", "Minh"};
    struct Person per4 = {4, "Thach", "Tri"};
    struct Person per5 = {5, "Kim", "MinhTri"};

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

    printf("**************************************************************\n");

    int idx;
    printf("Nhap id :");
    scanf("%d", &idx);

    Node *node_kq =
        FindNodeByID(my_list, idx);
    if (node_kq != NULL)
    {
        PrintNode(node_kq);
        printf("**************************************************************\n");
    }
    else
    {
        printf("Khong tim thay id %d\n", idx);
        printf("**************************************************************\n");
    }
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 12873f93a066a8eddcaa685309c27dac913e12da
=======
>>>>>>> c58b3b7b2760572e4f13e45dea3ee2e63b67a656
=======
>>>>>>> cd4da97f2055dfebe247e87ebc129bf9bd08f885

        AddNodeAfter(my_list, idx, new_ele5);

    printf("Sau khi them nut : \n");
    printf("\n");
    PrintList(my_list);

    RemoveHead(my_list);
    printf("**************************************************************\n");
    printf("Sau khi xoa nut dau : \n");
    printf("\n");

    PrintList(my_list);

    RemoveLast(my_list);
    printf("**************************************************************\n");
    printf("Sau khi xoa nut cuoi : \n");
    printf("\n");

    PrintList(my_list);

    printf("Nhap id can xoa:");
    scanf("%d", &idx);
    RemoveNode(my_list, idx);
    printf("**************************************************************\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    InputNode(my_list);
    printf("**************************************************************\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    return 0;
}