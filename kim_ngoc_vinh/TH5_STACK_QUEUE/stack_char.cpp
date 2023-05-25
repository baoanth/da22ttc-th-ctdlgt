#include <stdio.h>
#include <conio.h>
#include <string.h>


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

void AddFirst(Stack &l, Node *new_ele)
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

char IsEmpty(Stack &s)
{
    if (s.pHead == NULL) // stack rỗng
        return 1;
    else 
		return 0;
}

void Init(Stack &s)
{
	s.pHead = NULL;
	s.pTail = NULL;
}

//Dua mot phan tu x vao stack
void Push(Stack &s, char x)
{
    Node* new_ele = GetNode(x);
	AddFirst(s, new_ele);
}

//Lay mot phan tu ra khoi dinh stack
char Pop(Stack &s)
{   
    char x;
    if(IsEmpty(s) )
        return NULL;
    
	x = s.pHead->Info; //Lay gia tri dinh stack    
    RemoveHead(s); // Xoa phan tu dinh stack
    
    return x;
}
// Xem phan tu o dinh stack ma khong lay ra 
char Top(Stack &s)
{ 
    if(IsEmpty(s)) 
        return NULL;
    return s.pHead->Info;
}

int main()
{
    char  str[] = "EAS*Y**QUE***ST***I*ON";
    
    int i; 
    char x;
    Stack my_stack;
    Init(my_stack);
    
	printf("Chuoi goc: %s\n", str);
	printf("\n Ket qua in ra voi STACK:  ");
	
    for (i=0; i<strlen(str); i++)
    {
        if (str[i]=='*')
        {
           x = Pop(my_stack) ;
           printf("%c",x);
        }
        else
            Push(my_stack, str[i]);
    }
    return 0;


}