#include <stdio.h>
#include <conio.h>
#include <string.h>

//***************************
typedef struct Node
{
	char Info;
	Node *pNext;
} Node;

typedef struct Stack
{
    Node *pHead;
    Node *pTail;
} Stack;

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

//Viet ham void AddFirst(Stack &l, Node  *new_ele)
void AddFirst(Stack &l, Node  *new_ele)
{
	if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;      
    }
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
}

//Viet ham void RemoveHead(Stack &l)
void RemoveHead(Stack &l)
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
char IsEmpty(Stack &s)
{
	if(s.pHead == NULL) // stack rong
		return 1;
	else return 0;
}

//Viet ham void Init
void Init(Stack &s)
{
	s.pHead = s.pTail = NULL;
}

//Viet ham chen vao dau danh sach
void InserHead(Stack &s, char x)
{
	Node* new_ele = GetNode(x);
    AddFirst(s, new_ele);
}

//Them 1 phan tu x vao Stack s
void Push(Stack &s, char x)
{
	InserHead(s, x);
}

//Trich/huy phan tu o  dinh Stack S
char Pop(Stack &s)
{   
    char x;
    if(IsEmpty(s))
        return NULL;
    
	x = s.pHead->Info;  
    RemoveHead(s);
    
    return x;
}

// Xem thong tin cua phan tu o dinh Stack
char Top(Stack &s)
{ 
    if(IsEmpty(s)) 
        return NULL;
    return s.pHead->Info;
}

//Viet ham main
int main()
{
    char  str[] = "AIG*** *HNIHT***** *REBMUN****** *1*";
     
    char x;
    Stack my_stack;
    Init(my_stack);
    
	printf("Chuoi da cho: %s\n", str);
	printf("\nChuoi in ra man hinh voi STACK:  ");
	
    for (int i=0; i < strlen(str); i++)
    {
        if (str[i] == '*')
        {
           	x = Pop(my_stack) ;
           	printf("%c",x);
        }
        else
        	Push(my_stack, str[i]);
    }
    return 0;
}











