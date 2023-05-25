#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Person
{
    char diachi[50];
    char fname[20];
    char lname[20];
    char ttbenh[20];
    int tuoi;
    int stt;
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
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
	p->Info=x;
	p->pNext=NULL;
	return p;	
}

char IsEmpty(List &l)
{
    if(l.pHead == NULL)
        return 1;
    else return 0;
}

Person DeQueue(List &l)
{
    char x;
    if(IsEmpty(l)) 
        return ;
        x = l.pHead->Info;
    RemoveHead(l);
    return x;
}

Person Front(List &l)
{
    if(IsEmpty(s)) return NULL;
    return l.pHead->Info;
}

void InsertTail(List&l, Node *new_ele)
{
    if (l.pHead==NULL)
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

void EnQueue(List l, Person x)
{
    InserTail(l, x);
}
void InputNode(List &l)
{
	Person per_tam;
	printf("\n Moi nhap thong tin benh nhan:");
    printf("\nSTT:");
    scanf("%d", &per_tam.stt);
    
    fflush(stdin);
    printf("First name:");
    gets(per_tam.fname);
    
    fflush(stdin);
    printf("Last name:");
    gets(per_tam.lname);

    fflush(stdin);
    printf("\n Tuoi:");
    scanf("%d", &per_tam.tuoi);
    
    
    fflush(stdin);
    printf("Dia chi:");
    gets(per_tam.diachi);
    
    fflush(stdin);
    printf("Tinh trang benh:");
    gets(per_tam.ttbenh);
    
    
    
}
void PrintNode(Node *p)
{
	printf("%3d %10s %12s %5d %10s %10s\n", p->Info.stt, p->Info.fname, p->Info.lname, p->Info.tuoi, p->Info.diachi, p->Info.ttbenh);    
}

void PrintList(List l)
{
    if(l.pHead==NULL)
    {
	    printf("Danh sach rong\n");
	}
	else
	{
	    Node* p;
	    p=l.pHead;
	    while(p!=NULL)
	    {
	        printf("%3d %10s %12s %5d %10s %10s\n", p->Info.stt, p->Info.fname, p->Info.lname, p->Info.tuoi, p->Info.diachi, p->Info.ttbenh); 
	        p = p->pNext;
		}
	}
}

int main()
{
    List my_list;
    Init(my_list);
    
    InputNode(my_list);
    InputNode(my_list);
    printf("\n Danh sach benh nhan: \n");
    PrintList(my_list);
	
return 0;
}

