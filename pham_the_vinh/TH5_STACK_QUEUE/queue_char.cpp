#include <stdio.h>
#include <conio.h>
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

void AddTail(Queue &Q, Node *new_ele)
{
    if (Q.pHead == NULL)
    {
        Q.pHead = new_ele;
        Q.pTail = Q.pHead;
    }
    else
    {
        Q.pTail->pNext = new_ele;
        Q.pTail = new_ele;
    }
}

void RemoveHead(Queue &Q)
{
    Node *p;

    if (Q.pHead != NULL)
    {
        p = Q.pHead;
        Q.pHead = Q.pHead->pNext;
        delete p;

        if (Q.pHead == NULL)
            Q.pTail = NULL;
    }
}

void Init(Queue &Q)
{
    Q.pHead = Q.pTail = NULL;
}

char IsEmpty(Queue &Q)
{
    if (Q.pHead == NULL)
        return 1;
    else
        return 0;
}

void EnQueue(Queue &Q, char x)
{
    Node *new_ele = GetNode(x);
    AddTail(Q, new_ele);
}

char DeQueue(Queue &Q)
{
    char x;

    if (IsEmpty(Q))
        return NULL;

    x = Q.pHead->Info;
    RemoveHead(Q);

    return x;
}

char Front(Queue &Q)
{
    if (IsEmpty(Q))
        return NULL;

    return Q.pHead->Info;
}

int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";

    Queue myQueue;
    Init(myQueue);

    printf("Chuoi ban dau: %s", str);

    int i;
    char x;

    printf("\nKet qua: ");

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '*')
        {
            x = DeQueue(myQueue);
            printf("%c", x);
        }
        else
        {
            EnQueue(myQueue, str[i]);
        }
    }
    
    return 0;
}
