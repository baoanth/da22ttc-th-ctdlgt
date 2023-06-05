#include<stdio.h>
#include<stlib.h>
typedef struct 
{
    int Key;
    strct TNODE *pLeft,*pRight;
}TNODE;
typedef TNODE*TREE;
void Print_NLR(TREE ROOT)
{
    if ROOT!=NULL

    {
        printf("%d",ROOT->key);
        NLR(ROOT->pLeft);
        NLR(ROOT->pRight);

    }
}
void Print_LNR(TREE ROOT)
{
    if (ROOT!=NULL)
    {
      printf_  LNR(ROOT->Left);
        printf("%d",ROOT->key);
        LNR(ROOT->Right);
    }
}
void Print_LRN(TREE ROOT)
{
    if (ROOT!=NULL)
    {
        LNR(ROOT->Left);
        LNR(ROOT->Right);
        printf("%d",ROOT->key);
    }
}


