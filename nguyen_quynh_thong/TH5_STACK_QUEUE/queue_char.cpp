#include <stdio.h>
#include <string.h>

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

void Init(Queue &l)
{
    l.pHead = l.pTail = NULL;
}

Node *GetNode(char x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

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

void RemoveHead(Queue &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail == NULL;
        delete p;
    }
}

char RemoveFirst(Queue &l, char x)
{
    Node*p = l.pHead;
    x = p->Info;
    RemoveHead(l);
    return x;
}

char IsEmpty(Queue &l)
{
    if (l.pHead == NULL)
        return 1;
    else
        return 0;
}

void Push(Queue &l, char x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

char Pop(Queue &l)
{
    char x;
    if (IsEmpty(l))
        return NULL;
    x = RemoveFirst(l, x);
    return x;
}

char Top(Queue &l)
{
    if (IsEmpty(l))
        return NULL;
    return l.pHead->Info;
}

int main()
{
    Queue my_queue;
    Init(my_queue);
    char str[] = "EAS*Y**QUE***ST***I*ON";
    char x;
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '*')
            Push(my_queue, str[i]);
        else
        {
            x = Pop(my_queue);
            printf("%c", x);
        }
        
    }
    return 0;
}
