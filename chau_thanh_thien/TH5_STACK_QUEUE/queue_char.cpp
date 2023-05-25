#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Node
{
    char Info;
    Node *pNext;
} Node;

typedef struct Queve
{
    Node *pHead;
    Node *pTail;
} Queve;

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

void AddTail(Queve &l, Node *new_ele)
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
void Init(Queve &l)
{
    l.pHead = l.pTail = NULL;
}

char RemoveHead(Queve &l)
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
char IsEmpty(Queve &l)
{
    if (l.pHead == NULL)

        return 1;

    else
        return 0;
}

void Push(Queve &l, char x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

char Pop(Queve &l)
{
    char x;
    if (IsEmpty(l))
        return NULL;
    x = l.pHead->Info;
    RemoveHead(l);
    return x;
}

char Top(Queve &l)
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
    Queve my_queve;
    Init(my_queve);
    printf("Chuoi goc: %s\n ", str);
    printf("Ket qua Queve in :");
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '*')
        {
            Push(my_queve, str[i]);
        }
        else
        {
            x = Pop(my_queve);
            printf("%c", x);
        }
    }

    return 0;
}