#include <stdio.h>
#include <conio.h>
#include <string.h>

//***************************
typedef struct Node
{
	char Info;
	Node *pNext;
} Node;

typedef struct Queue
{
    Node *pHead;
    Node *pTail;
} Queue;

//***************************

//Viet ham Node *GetNode(char x)
Node *GetNode(char x)
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

//Viet ham void AddFirst(queue &l, Node  *new_ele)
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
//Viet ham void RemoveHead(Queue &l)
void RemoveHead(Queue &l)
{
    Node *p;
    char x;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}

//Kiem tra hang doi rong
char IsEmpty(Queue q)
{
	if(q.pHead == NULL) // Hang doi rong
		return 1;
	else return 0;
}

//Viet ham void Init
void Init(Queue &q)
{
	q.pHead = q.pTail = NULL;
}

//Viet ham chen vao dau danh sach
void InserTail(Queue &q, char x)
{
	Node* new_ele = GetNode(x);
    AddTail(q, new_ele);
}

//Them 1 phan tu x vao Hang doi s
void EnQueue(Queue &q, char x)
{
	InserTail(q, x);
}

//Trich/huy phan tu o  dinh hang doi S
char DeQueue(Queue &q)
{   
    char x;
    if(IsEmpty(q))
        return NULL;
    
	x = q.pHead->Info;  
    RemoveHead(q);
    
    return x;
}

// Xem thong tin cua phan tu o dinh hang doi
char Front(Queue q)
{ 
    if(IsEmpty(q)) 
        return NULL;
    return q.pHead->Info;
}

//Viet ham main
int main()
{
    char  str[] = "GIA*** *THINH***** *NUMBER****** *1*";
     
    char x;
    Queue my_queue;
    Init(my_queue);
    
	printf("Chuoi da cho: %s\n", str);
	printf("\nChuoi in ra man hinh voi QUEUE:  ");
	
    for (int i=0; i < strlen(str); i++)
    {
        if (str[i] == '*')
        {
           	x = DeQueue(my_queue) ;
           	printf("%c",x);
        }
        else
        	EnQueue(my_queue, str[i]);
    }
    return 0;
}











