#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 200


typedef struct Person
{
    int tuoi;
    char hoten[20];
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
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->info=x;
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

char IsEmpty(Queue &s)
{
    if(s.pHead == NULL)
        return 1;
    else return 0;
}

void EnQueue(Queue &s, Person x)
{

    Node* new_ele = GetNode(x);
    if(new_ele != NULL)
    	AddTail(s, new_ele);
}

Person Front(Queue &s)
{	Person x;
    if(IsEmpty(s)) return x;
    return s.pHead->info;
}

void Inputqueue(Queue &s)
{
    Person per_tam;
    printf("Nhap benh nhan moi.\n");

    printf("Nhap stt: ");
    scanf("%d", &per_tam.stt);


    printf("nhap tuoi: ");
    scanf("%d",per_tam.tuoi);

    fflush(stdin);
    printf("First name: ");
    gets(per_tam.fname);

    fflush(stdin);
    printf("Last name: ");
    gets(per_tam.lname);

    fflush(stdin);
    printf("dia chi : ");
    gets(per_tam.diachi);

    fflush(stdin);
    printf("tinh trang benh: ");
    gets(per_tam.ttbenh);

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
            printf("%3d%3d%10s%10s%10s%10s\n", p->info.stt,p->info.tuoi ,p->info.fname , p->info.lname, p->info.diachi, p->info.ttbenh);
            p= p->pNext;

        }
    }
}

int main()
{

    Queue my_queue;

    Inputqueue(my_queue);
    Inputqueue(my_queue);
    Init(my_queue);

    printf("danh sach sau khi nhap:\n");
    printQueue(my_queue);

    return 0;
}
