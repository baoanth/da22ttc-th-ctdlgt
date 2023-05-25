#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char info;
    Node* pNext;
}Node;
typedef struct Stack
{
    Node* pHead;
    Node* pTail;
}Stack;
void Init(Stack &l)
{
    l.pHead = l.pTail = NULL;
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

void RemoveHead(Stack &l)
{
    Node* p;
    char x;
    if(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if(l.pHead == NULL)
            l.pTail = NULL;

    }
}



char IsEmpty(Stack &l)
{
    if(l.pHead == NULL)
        return 1;
    else 
    return 0;

}
void InsertFist( Stack &l, Node* new_ele)
{
    if (l.pHead== NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele -> pNext = l.pHead;
        l.pHead = new_ele;
    }
}

void Push(Stack &l, char x)
{
    Node* new_ele = GetNode(x);
    InsertFist(l, new_ele);
}


char Pop(Stack &l)
{
    char x;
    if(IsEmpty(l))
        return NULL;
    x = l.pHead ->info;
    RemoveHead(l);
    
    return x;
}

char Top(Stack &l)
{
    if(IsEmpty(l))
        return NULL;
    return l.pHead-> info;
}


int main()
{
    char str[] = "EAS*Y**QUE***ST***I*ON";
    int i;
    char x;
    Stack my_stack;
    Init(my_stack);
    printf("Chuoi ban dau : %s \n", str);
    printf("\n ket qua trong stack");

    for(i = 0; i< strlen(str); i ++)
    {
        if(str[i]== '*')
        {
            x = Pop(my_stack);
            printf("%c", x);

        }
        else
            Push(my_stack, str[i]);

    }
    return 0;
}
