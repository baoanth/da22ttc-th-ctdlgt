#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char info;
    Node* pNext;
}Node;
typedef struct Queue
{
    Node* pHead;
    Node* pTail;
}Queue;
void Init(Queue &q)
{
    q.pHead = q.pTail = NULL;
}
Node* GetNode( char x)
{
    Node* p;
    p = new Node;
    if(p == NULL)
    {
        printf("not du bo nho");
        return 0;
    }
    p -> info = x;
    p -> pNext = NULL;
    return p;
}

void RemoveHead(Queue &q)
{
    Node* p;
    char x;
    if(q.pHead != NULL)
    {
        p = q.pHead;
        q.pHead = q.pHead->pNext;
        delete p;
        if(q.pHead == NULL)
            q.pTail = NULL;

    }
}



char IsEmpty(Queue &q)
{
    if(q.pHead == NULL)
        return 1;
    else 
    return 0;

}
void InsertTail(Queue &q, Node* new_ele)
{
    if(q.pHead == NULL)
    {
        q.pHead = new_ele;
        q.pTail = q.pHead;
    }
    else
    {
        q.pTail ->pNext = new_ele;
        q.pTail = new_ele;
    }
}


void EnQueue(Queue &q, char x)
{
    Node* new_ele = GetNode(x);
    InsertTail(q, new_ele);
}


char DeQueue(Queue &q)
{
    char x;
    if(IsEmpty(q))
        return NULL;
    x = q.pHead ->info;
    RemoveHead(q);
    
    return x;
}

char Front(Queue q)
{
    if(IsEmpty(q))
        return NULL;
    return q.pHead-> info;
}


int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";
    int i;
    char x;
    Queue my_stack;
    Init(my_stack);
    printf("Chuoi ban dau : %s \n", str);
    printf("\n ket qua trong queue : ");

    for(i = 0; i< strlen(str); i ++)
    {
        if(str[i]== '*')
        {
            x = DeQueue(my_stack);
            printf("%c", x);

        }
        else
            EnQueue(my_stack, str[i]);

    }
    return 0;
}
