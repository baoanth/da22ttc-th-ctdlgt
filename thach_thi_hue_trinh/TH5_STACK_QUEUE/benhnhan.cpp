#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 200


typedef struct Person
{
    int tuoi;
    char diachi[20];
    char ttbenh[20];
    char fname[20];
    char lname[20];
    int stt;

}Person;

typedef struct Node
{
    Person info;
    Node *pNext;
}Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
}Queue;

void Init(Queue &s)
{
    s.pHead = s.pTail = NULL;
}

Node* GetNode(Person x)
{
	Node* p;
    p = new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->info = x;
	p->pNext = NULL;
	return p;	
}

void AddTail(Queue &s, Node* new_ele)
{
    if(s.pHead==NULL)
    {
	    s.pHead=new_ele;
	    s.pTail=s.pHead;
	}
	else
	{
	    s.pTail->pNext = new_ele;
        s.pTail = new_ele;
	}
}

/*void RemoveHead(Queue &s)
{
    Node *p;
    char x;
    if(s.pHead != NULL)
    {
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        delete p;
        if(s.pHead == NULL)
            s.pTail = NULL;
    }
}*/
char IsEmpty(Queue &s)
{
    if(s.pHead == NULL)
        return 1;
    else return 0;
}

void EnQueue(Queue &s, Person x)
{

    Node* new_ele = GetNode(x);
    	AddTail(s, new_ele);
}

/*Person DeQueue(Queue &s)
{
    Person x;
    if(IsEmpty(s)) 
        return x;
        
        x = s.pHead->Info;
    RemoveHead(s);
    return x;
}
*/
Person Front(Queue &s)
{	
	Person x;
    if(IsEmpty(s)) return x;
    return s.pHead->info;
}

void Inputqueue(Queue &s)
{
    Person per_tam;
    
    printf("\nNhap STT: ");
    scanf("%d", &per_tam.stt);

    fflush(stdin);
    printf("Nhap Tuoi: ");
    scanf("%d",&per_tam.tuoi);
    
    fflush(stdin);
    printf("Nhap Ho: ");
    gets(per_tam.fname);

    fflush(stdin);
    printf("Nhap Ten: ");
    gets(per_tam.lname);

    fflush(stdin);
    printf("Dia chi: ");
    gets(per_tam.diachi);

    fflush(stdin);
    printf("Tinh trang benh: ");
    gets(per_tam.ttbenh);
	printf("\n");
  	EnQueue(s, per_tam);

}

void PrintQueue(Queue &s)
{
    if(s.pHead == NULL)
    {
        printf("Danh sach rong:\n");
    }
    else
    {
        Node* p;
        p = s.pHead;
        while(p!= NULL)
        {
            printf("\n%3d| %4d | %6s | %7s | %9s | %14s |", p->info.stt,p->info.tuoi ,p->info.fname , p->info.lname, p->info.diachi, p->info.ttbenh);
            p= p->pNext;

        }
    }
}

int main()
{
	int i,n;

    Queue my_queue;
    Init (my_queue);
    
    printf("Nhap so luong nguoi benh: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
    	printf("\nNhap thong tin benh nhan %d:\n ",i);
    	Inputqueue(my_queue);
	}
    
    printf("DANH SACH SAU KHI NHAP\n");
    printf("\n");
    printf("STT| Tuoi |   Ho   |   Ten   |  Dia chi  |   Tinh trang   |");
    PrintQueue(my_queue);

    return 0;
}


