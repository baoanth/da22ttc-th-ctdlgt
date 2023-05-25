#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    char hoten[50];
    int tuoi;
    char diachi[50];
    char tinhtrang[50];
} Person;
typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct Queve
{
    Node *pHead;
    Node *pTail;
} Queve;

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

void AddTail(Queve &l, Node *new_ele)
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
void Init(Queve &l)
{
    l.pHead = l.pTail = NULL;
}

//Person RemoveHead(Queve &l)
//{
//    if (l.pHead != NULL)
//    {
//        Node *p = l.pHead;
//        l.pHead = l.pHead->pNext;
//        delete p;
//        if (l.pHead == NULL)
//            l.pTail = NULL;
//    }
//}
char IsEmpty(Queve &l)
{
    if (l.pHead == NULL)

        return 1;

    else
        return 0;
}

void Push(Queve &l, Person x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

//Person Pop(Queve &l)
//{
//    Person x;
//    if (IsEmpty(l))
//        return NULL;
//    x = l.pHead->Info;
//    RemoveHead(l);
//    return x;
//}

Person Top(Queve &l)
{
	Person x;
    if (IsEmpty(l))
        return x;
    return l.pHead->Info;
}

void PrintQueue(Queve &l)
{
    if(l.pHead == NULL)
    {
        printf("Danh sach rong:\n");
    }
    else
    {
        Node* p;
        p = l.pHead;
        while(p!= NULL)
        {
            printf("\nTen: %14s\nTuoi: %7d\nDiaChi: %10s\nTinhTrang: %5s\n", p->Info.hoten, p->Info.tuoi , p->Info.diachi , p->Info.tinhtrang);
            printf("==================================");
            p= p->pNext;

        }
    }
}
main()
{
    Person Per1 = {"N.P.Vinh" , 19 , "TraVinh" , "Nghien FF"};
    Person Per2 = {"P.M.Nhat" , 19 , "TraVinh" , "Nghien FF"};
    
    Node *new1 = GetNode(Per1);
    Node *new2 = GetNode(Per2);
    Queve my_queve;
    Init(my_queve);
    AddTail(my_queve, new1);
    
    AddTail(my_queve, new2);
    PrintQueue(my_queve);

    return 0;
}
