#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int hs;
    int bac;
} DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;



int main()
{

    return 0;
}



