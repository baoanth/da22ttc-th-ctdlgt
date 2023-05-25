#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
typedef struct Node
{
    char Info;
    Node *pNext;
} Node;

typedef struct Stack
{
    Node *pHead;
    Node *pTail;
};

Node *GetNode(char x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho !");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void Init(Stack &l)
{
    l.pHead = l.pTail = NULL;
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
        new_ele ->pNext = l.pHead;
        l.pHead = new_ele; 
    }
}

void RemoveFirst(Stack &l)
{
    Node* p;
    if(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if(l.pHead == NULL) l.pTail = NULL;
    }
}

int IsEmpty(Stack &l)
{
    if(l.pHead == NULL)
        return 1;
    else 
        return 0;
}

void Push(Stack &l, char x)
{
	Node* p = GetNode(x);
    AddFirst(l,p);
}

void Pop(Stack &l, char &x)
{
    if(IsEmpty(l)) return;
    Node* p = l.pHead;
    x = p->Info;
    RemoveFirst(l); 
}

char Top(Stack &l)
{
    if(IsEmpty(l)) return 0;
    return l.pHead->Info;
}

int main()
{
    char a[] = "EAS*Y**QUE***ST***I*ON";
    int n = 23;
    Stack mystack;
    Init(mystack);

    for(int i = 0; i<n;i++)
    {
        if(a[i]!='*')
        {
            Push(mystack, a[i]);
        }
        else
        {
            char tmp; Pop(mystack,tmp);
            printf("%3c", tmp );

        }
    }
   
   
    return 0;
}
