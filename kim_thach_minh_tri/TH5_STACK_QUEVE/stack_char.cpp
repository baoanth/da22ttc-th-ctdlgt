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

        new_ele->pNext = l.pHead;

        l.pHead = new_ele;
    }
}
void Init(Stack &l)
{
    l.pHead = l.pTail = NULL;
}

char RemoveHead(Stack &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
        
    }
}

char IsEmpty(Stack &l)
{
    if (l.pHead == NULL)

        return 1;

    else
        return 0;
}

void Push(Stack &l, char x)
{
    Node *new_ele = GetNode(x);
    AddFirst(l, new_ele);
}

char Pop(Stack &l)
{
    char x;
    if (IsEmpty(l))
        return NULL;
    x = l.pHead->Info;
     RemoveHead(l);
    return x;
}

char Top(Stack &l)
{
    if (IsEmpty(l))
        return NULL;
    return l.pHead->Info;
}

main()
{
    char str[] = "EAS*Y**QUE***ST***I**ON";
    int i;
    char x;
    Stack my_stack;
    Init(my_stack);
    printf("Chuoi goc: %s\n ", str);
    printf("Ket qua Stack in :");
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '*')
        {
            Push(my_stack, str[i]);
        }
        else
        {
            x = Pop(my_stack);
            printf("%c", x);
        }
    }

    return 0;
}


