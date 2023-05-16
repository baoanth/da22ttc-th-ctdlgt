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

void AddFist(List &l, Node *new_ele)
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

void AddNodeAfter(List &l, int idx, Node *new_ele)
{
    Node *q = FindNodeByID(l, idx);

    if (q != NULL && new_ele != NULL)
    {
        new_ele->pNext = q->pNext;
        q->pNext = new_ele;
        if (q == l.pTail)
            l.pTail = new_ele;
    }
    //	else
    //	AddFirst(l, new_ele);
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

void AddPerson(List &l)
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

    AddNodeAfter(l, idx-1, new_node);

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

    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele3);

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

    Node *new_ele5 = GetNode(per5);
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
    
    AddPerson(my_list);
    PrintList(my_list);

    return 0;
}
