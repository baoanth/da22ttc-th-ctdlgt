#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct BenhNhan
{
    char hoten[20];
    int tuoi;
    char diachi[50];
    char tinhtrang[20];
}BenhNhan;

typedef struct Node
{
    BenhNhan Info;
    Node *pNext;
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;

Node *Get_Node(BenhNhan x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho.");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void Add_Tail(Queue &l, Node *new_ele)
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
void Init(Queue &l)
{
    l.pHead = l.pTail = NULL;
}

char Remove_Head(Queue &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}
char Is_Empty(Queue &l)
{
    if (l.pHead == NULL)

        return 1;

    else
        return 0;
}

void Push(Queue &l, BenhNhan x)
{
    Node *new_ele = Get_Node(x);
    Add_Tail(l, new_ele);
}

void Pop(Queue &l, BenhNhan &x)
{
    if (Is_Empty(l))
        return;
    x = l.pHead->Info;
    Remove_Head(l);
}

void Top(Queue &l, BenhNhan &p)
{
    if (Is_Empty(l))
        return;
    p = l.pHead->Info;
}

void print_queue(Queue l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("\nHo ten thang benh nhan: %s", p->Info.hoten);
        printf("\nTuoi: %d", p->Info.tuoi);
        printf("\nDia chi: %s", p->Info.diachi);
        printf("\nTinh trang suc khoe: %s", p->Info.tinhtrang);
        p = p->pNext;
    }
}

void DeQueue(Queue &l)
{
    if(Is_Empty(l)) return;
    Remove_Head(l);
}
void EnQueue(Queue &s)
{
    BenhNhan x;
    fflush(stdin);
    printf("Ho ten thang benh nhan: ");
    gets(x.hoten);

    fflush(stdin);
    printf("Tuoi: ");
    scanf("%d", &x.tuoi);

    fflush(stdin);
    printf("Dia chi: ");
    gets(x.diachi);

    fflush(stdin);
    printf("Tinh trang suc khoe: ");

    gets(x.tinhtrang);
    Node *p = Get_Node(x);
    Add_Tail(s, p);
}

int main()
{
    Queue my_queve;
    Init(my_queve);
	printf("\nNhap thang benh nhan thu nhat:\n");
    EnQueue(my_queve);
	printf("\nNhap thang benh nhan thu hai: \n");
    EnQueue(my_queve);

    printf("------------------------------------\n");

	printf("Danh sach benh nhan: \n");
    print_queue(my_queve);

    DeQueue(my_queve);
    print_queue(my_queve);
    return 0;
}

