#include <stdio.h>
#include <stdlib.h>

/*Khai bao cay*/
typedef struct TNODE
{
    int Key;
    struct NODE *pLeft, *pRight;
}TNODE;
typedef TNODE *TREE;

/*In theo thu tu truoc*/
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        /*Xu ly*/
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }

}

/*Ins theo thu tu giua*/
void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR (Root->Left);
        /*Xu ly*/
        Print_LNR (Root->Right);
    }
    
}

/*In theo thu tu sau*/
void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->Left);
        Print_LRN(Root->Right);
        /*xu ly*/
    }
}

TNODE *SearchNode(TREE T, int x)
{
    if (T)
    {
        if(T->Key == x)
        return T;
        if (T->Key > x)
            return SearchNode(T->pLeft, x);
        else 
            return SearchNode(T->pRight, x);
    }
    return NULL;
}

int InsertNode(TREE &T, int x)
{
    if (T)
    {
        if (T->Key == x)
            return 0;
        if (T->Key > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
       T = new_TNode;
       if (T == NULL)
        return -1;
    T->Key = x;
    T->pLeft = T->pRight = NULL;
    return 1;  
}



int main()
{

    return 0;
}