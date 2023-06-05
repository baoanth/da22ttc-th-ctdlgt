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
    Node *p = new Node;

    if (p == NULL)
    {
        printf("---Khong du bo nho de cap phat---");
        return 0;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

void AddFirst(Stack &S, Node *new_ele)
{
    if (S.pHead == NULL)
    {
        S.pHead = new_ele;
        S.pTail = S.pHead;
    }
    else
    {
        new_ele->pNext = S.pHead;
        S.pHead = new_ele;
    }
}

void RemoveHead(Stack &S)
{
    Node *p;

    if (S.pHead != NULL)
    {
        p = S.pHead;
        S.pHead = S.pHead->pNext;
        delete p;

        if (S.pHead == NULL)
            S.pTail = NULL;
    }
}

void Init(Stack &S)
{
    S.pHead = S.pTail = NULL;
}

char IsEmpty(Stack &S)
{
    if (S.pHead == NULL)
        return 1;
    else
        return 0;
}

void Push(Stack &S, char x)
{
    Node *new_ele = GetNode(x);
    AddFirst(S, new_ele);
}

char Pop(Stack &S)
{
    char x;

    if (IsEmpty(S))
        return NULL;

    x = S.pHead->Info;
    RemoveHead(S);

    return x;
}

char Top(Stack &S)
{
    if (IsEmpty(S))
        return NULL;

    return S.pHead->Info;
}

int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";

    Stack myStack;
    Init(myStack);

    printf("Chuoi ban dau: %s", str);

    int i;
    char x;

    printf("\nKet qua: ");

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '*')
        {
            x = Pop(myStack);
            printf("%c", x);
        }
        else
        {
            Push(myStack, str[i]);
        }
    }
    
    return 0;
}
