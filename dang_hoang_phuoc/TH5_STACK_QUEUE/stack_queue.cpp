#include <stdio.h>
#include <conio.h>
#include <string.h>



typedef struct Node
{
char Info; 
Node* pNext; 
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
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void AddFirst(Stack &l, Node* new_ele)
{
	if (l.pHead==NULL) //Danh sách r?ng
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
void Init(List &l)
{
    S.pHead = S.pTail = NULL;
}
char IsEmpty(List &S)
{
	if (S.pHead == NULL) // stack r?ng
	return 1;
	else return 0;
}



void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}
void AddTail(List &l, Node *new_ele)
{
    if (S.pHead == NULL)
    {
        S.pHead = new_ele;
        l.pTail = S.pHead;
    }
    else
    {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}
/*NODE* InsertHead(List &l, char x)
{
	NODE* new_ele = GetNode(x);
		if (new_ele ==NULL) return NULL;
		if (S.pHead==NULL)
		{
			S.pHead = new_ele;
			l.pTail = S.pHead;
		}
			else
			{
				new_ele->pNext = S.pHead; // (1)
				S.pHead ->pPrev = new_ele; // (2)
				S.pHead = new_ele; // (3)
			}
				return new_ele;
}*/

void RemoveHead(List &s)
{
	Node *p;
	char x;
	if ( l.pHead != NULL)
	{
		p = l.pHead; x = p->data;
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead == NULL) 
			l.pTail = NULL;
	}
		
}
char IsEmpty(Stack &s)
{
	if (s.pHead == NULL) // stack r?ng
	return 1;
	else return 0;
}
void Push(Stack &s, char x)
{
	Node* new_ele = GetNode(x);
	AddFirst(s, new_ele);
}
char Pop(LIST &S)
{
	char x;
	if(isEmpty(S)) 
		return NULL;
	x = s.pHead->Info;
	RemoveHead(S);
	return x;
}
char Top(LIST &S)
{
	if(isEmpty(S))
		return NULL;
	return s.Head->Info;
}
int main()
{
	char str[] = "EAS*Y**QUE***ST**TION"
	int i;
	char x;
	Stack my_stack;
	Init(my_stack);
	
	printf("Chuoi ban dau: %s\n", str);
	printf("Ket qua in ra voi STACK:  ");
	
	for (i=o; i<strlen(str);i++)
	{
		if(str[i] =='*')
		{
			x = Pop(my_stack);
			printf("%c",x);
		}
		else
			Push(my_stack, str[i]);
	}
	return 0;
}
