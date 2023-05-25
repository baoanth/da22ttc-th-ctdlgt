#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 200


typedef struct Person
{
    int tuoi;
    char dc[20];
    char tt[20];
    char h[20];
    char t[20];
    int stt;

}Person;

typedef struct Node
{
    Person Info;
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
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho!\n");
    	return 0;
	}
	p->Info=x;
	p->pNext=NULL;
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

void RemoveHead(Queue &s)
{
    Node *p;
    char x;
    if(s.pHead != NULL)
    {
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        delete p;
        if(s.pHead == NULL)	s.pTail = NULL;
    }
}
char IsEmpty(Queue &s)
{
    if(s.pHead == NULL)	return 1;
    else return 0;
}

void EnQueue(Queue &s, Person x)
{
    Node* new_ele = GetNode(x);
    AddTail(s, new_ele);
}

Person DeQueue(Queue &s)
{
    Person x;
    if(IsEmpty(s)) return x;   
    x = s.pHead->Info;
    RemoveHead(s);
    return x;
}

Person Front(Queue &s)
{
	Person x;
    if(IsEmpty(s)) return x;
    return s.pHead->Info;
}

void Inputqueue(Queue &s)
{
    Person per_tam;
   
    printf("STT : ");
    scanf("%d", &per_tam.stt);

    fflush(stdin);
    printf("Tuoi : ");
    scanf("%d",&per_tam.tuoi);
    
    fflush(stdin);
    printf("Ho : ");
    gets(per_tam.h);

    fflush(stdin);
    printf("Ten : ");
    gets(per_tam.t);

    fflush(stdin);
    printf("Dia chi : ");
    gets(per_tam.dc);

    fflush(stdin);
    printf("Tinh trang benh : ");
    gets(per_tam.tt);

  	EnQueue(s, per_tam);

}

void printQueue(Queue &s)
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
            printf("\n%3d|%6d|%10s|%10s|%20s|%20s", p->Info.stt,p->Info.tuoi ,p->Info.h , p->Info.t, p->Info.dc, p->Info.tt);
            p= p->pNext;
        }
    }
}

int main()
{
	int i, n;

    Queue my_queue;
    Init(my_queue);
    
    printf("Nhap so luong benh nhan: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
    	printf("\nNhap benh nhan %d :\n",i);
    	Inputqueue(my_queue);
    }
      
    printf("\ndanh sach sau khi nhap:");
    printf("\nSTT| Tuoi |    Ho    |    Ten   |         DC         |         TTB        ");
    printQueue(my_queue);

//	DeQueue(my_queue);

    return 0;
}


