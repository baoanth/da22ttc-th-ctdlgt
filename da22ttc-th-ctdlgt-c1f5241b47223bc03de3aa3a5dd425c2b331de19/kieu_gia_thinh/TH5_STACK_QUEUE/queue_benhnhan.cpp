#include<stdio.h>
#include<conio.h>
#include<string.h>

//********************
struct BenhNhan
{
    char hoten[20];
    int tuoi;
    char diachi[30];
    char tinhtrang[40];
};

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
//********************

//Tao GetNode
Node *GetNode(BenhNhan x)
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

//Viet ham void AddTail
void AddTail(Queue &l, Node *new_ele)
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

//Viet ham Init
void Init(Queue &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham RemoveHead
char RemoveHead(Queue &l)
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

//Kt hang doi rong
char IsEmpty(Queue &l)
{
    if (l.pHead == NULL)

        return 1;
    else
        return 0;
}

//Trich/Huy phan tu o dau hang doi
void DeQueue(Queue &l, BenhNhan &x)
{
    if (IsEmpty(l))
        return;
    x = l.pHead->Info;
    RemoveHead(l);
}

//Viet ham in hang doi
void PrintQueue(Queue l)
{
	Node*p = l.pHead;
	while(p!= NULL)
	{
		printf("\nHo ten benh nhan:%s", p->Info.hoten);
		printf("\nTuoi %d",p->Info.tuoi);
		printf("\nDia chi: %s",p->Info.diachi);
		printf("\nTinh trang suc khoe:%s",p->Info.tinhtrang);
		p = p->pNext;
	}
}

//Them 1 phan tu vao cuoi hang doi
void EnQueue(Queue &s)
{
    BenhNhan x;
    fflush(stdin);
    printf("\nNhap ten benh nhan: ");
    gets(x.hoten);
	
	fflush(stdin);
    printf("\nNhap tuoi: ");
    scanf("%d", &x.tuoi);
    
	fflush(stdin);
    printf("\nNhap dia chi: ");
    gets(x.diachi);
    
	fflush(stdin);
    printf("\nNhap tinh trang suc khoe: ");
   
    gets(x.tinhtrang);
    Node *p = GetNode(x);
    AddTail(s,p);
}

//Viet ham main
int main()
{

	Queue my_queue;
    Init(my_queue);
    EnQueue(my_queue);
    EnQueue(my_queue);
    
    PrintQueue(my_queue);
	
    return 0;
}
