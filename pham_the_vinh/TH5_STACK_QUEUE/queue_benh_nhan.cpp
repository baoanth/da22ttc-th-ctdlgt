#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct BenhNhan
{
    int stt;
    int tuoi;
    char hoten[20];
    char diachi[30];
    char tinhtrang[30];
} BenhNhan;

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

Node *GetNode(BenhNhan x)
{
    Node *p = new Node;

    if (p == NULL)
    {
        printf("--- Khong du bo nho de cap phat ---");
        return 0;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

void AddTail(Queue &Q, Node *new_ele)
{
    if (Q.pHead == NULL)
    {
        Q.pHead = new_ele;
        Q.pTail = Q.pHead;
    }
    else
    {
        Q.pTail->pNext = new_ele;
        Q.pTail = new_ele;
    }
}

void Init(Queue &Q)
{
    Q.pHead = Q.pTail = NULL;
}

void EnQueue(Queue &Q)
{
    BenhNhan x;

    printf("** De dung, nhap so thu tu: 0 **\n"); 
    
    while(1)
    {
		printf("\nNhap so thu tu: ");
    	scanf("%d", &x.stt); 

		if(x.stt != 0)
		{ 
		    fflush(stdin);
		    printf("\nNhap ten: ");
		    gets(x.hoten);

		    fflush(stdin);
		    printf("\nNhap tuoi: ");
		    scanf("%d", &x.tuoi);

		    fflush(stdin);
		    printf("\nNhap dia chi: ");
		    gets(x.diachi);

		    fflush(stdin);
		    printf("\nNhap tinh trang benh: ");
		    gets(x.tinhtrang);

		    printf("--------------------------------");

		    Node *new_ele = GetNode(x);
		    AddTail(Q, new_ele);
		}
		else
			break; 
	}
}

void Print(Queue Q)
{
    Node *p = Q.pHead;

    printf("%5s%25s%20s%25s%30s\n", "Stt","Ho va ten","Tuoi","Dia chi","Tinh trang benh"); 

    while (p != NULL)
    {
        printf("%5d%25s%20d%25s%30s\n",p->Info.stt, p->Info.hoten, p->Info.tuoi, p->Info.diachi, p->Info.tinhtrang);
       
        p = p->pNext;
    }
}

int main()
{
    Queue myQueue;
    Init(myQueue);

    printf("--- Nhap thong tin benh nhan ---\n"); 
    EnQueue(myQueue);

    printf("--- Thong tin benh nhan da nhap ---\n"); 
    Print(myQueue);

    return 0;
}
