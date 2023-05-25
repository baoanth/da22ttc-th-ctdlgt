#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Person
{
    int stt;
    int tuoi;
    char hoten[20];
    char diachi[20];
    char ttbenh[20];

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

Node* GetNode(Person x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho."); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void AddTail(Queue &s, Node *new_ele)
{
	if (s.pHead == NULL)
	{
		s.pHead = new_ele;
		s.pTail = s.pHead;
	}
	else
	{
		s.pTail->pNext = new_ele;
		s.pTail = new_ele;
	}
}
/*
void RemoveHead(Queue &s)
{
	Node *p;
    char x;
	if(s.pHead != NULL)
	{
		p = s.pHead; 	
		s.pHead = s.pHead->pNext;
		delete p;
		if(s.pHead == NULL) s.pTail = NULL;
	}
}
*/
char IsEmpty(Queue &s)
{
    if (s.pHead == NULL)
    return 1;
    else return 0;
}

void Enqueue(Queue &s, Person x)
{
    Node* new_ele = GetNode(x);
    if(new_ele!= NULL)
    AddTail(s, new_ele);
}

Person Front(Queue &s)
{
    Person x;
    if(IsEmpty(s)) return x; 
    return s.pHead->Info;
}

void Init(Queue &s)
{
    s.pHead = s.pTail = NULL;
}

void InputQueue(Queue &s)
{
    Person per_tam;
    printf("\nNhap info thang benh nhan. \n");

    fflush(stdin);
    printf("\nNhap stt: ");
    scanf("%d", per_tam.stt);

    fflush(stdin);
    printf("\nNhap ho ten: ");
    scanf("%s", per_tam.hoten);

    fflush(stdin);
    printf("\nNhap tuoi: ");
    scanf("%d", per_tam.tuoi);

    fflush(stdin);
    printf("\nNhap dia chi: ");
    scanf("%s", per_tam.diachi);

    fflush(stdin);
    printf("\nNhap tinh trang benh: ");
    scanf("%s", per_tam.ttbenh);


    Enqueue(s, per_tam);
}

void printQueue(Queue &s)
{
    if(s.pHead == NULL)
    {
        printf("Danh sach rong. \n");
    }
    else
    {
        Node* p;
        p = s.pHead;
        while(p!= NULL)
        {
            printf("%3d %10d %3d %10s %10s\n", p->Info.stt, p->Info.hoten,p->Info.tuoi, p->Info.diachi, p->Info.ttbenh);
            p= p->pNext;

        }
    }
}

int main()
{
    Queue my_queue;
    
    InputQueue(my_queue);
    InputQueue(my_queue);
    Init(my_queue);

    printf("Danh sach sau khi nhap:\n");
    printQueue(my_queue);

    return 0;
}
