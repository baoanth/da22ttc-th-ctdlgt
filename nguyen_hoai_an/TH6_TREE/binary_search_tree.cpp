#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode
{
    int Key;
    struct TNode *pLeft, *pRight;
}TNode;
typedef TNode* TREE;

void Print_NLR(TREE Root)
{
    if(Root !=NULL)
    {
        printf("%5d ", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if(Root !=NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%5d ", Root->Key);
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if(Root !=NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf("%5d ", Root->Key);

    }
}

TREE SearchNode(TREE T, int x)
{
    if(T) 
    {
        if(T->Key== x)  
            return T;
        if(T->Key > x) 
            return SearchNode(T->pLeft, x);
        else 
            return SearchNode(T->pRight, x);
    }
    return NULL;
}

int InsertNode(TREE &T, int x)
{
    if(T) 
    {
        if(T->Key == x)
            return 0;
        if(T->Key > x)
            return InsertNode(T->pLeft, x);
        else 
            return InsertNode(T->pRight, x);
    }
    T = new TNode;
    if(T == NULL)
    return -1;
    T->Key = x;
    T->pLeft = T->pRight = NULL;
    return 1;
}

int main()
{
    TREE my_tree = NULL;

 	InsertNode(my_tree, 15); 
    InsertNode(my_tree, 24);
	InsertNode(my_tree, 39);
	InsertNode(my_tree, 50);
    InsertNode(my_tree, 5);
    InsertNode(my_tree, 13);
    InsertNode(my_tree, 20);
	InsertNode(my_tree, 1);

    printf("Duyet theo thu tu truoc: \n");
    Print_NLR(my_tree);
    
    printf("\nDuyet theo thu tu giua: \n");
	Print_LNR(my_tree);

    printf("\nDuyet theo thu tu sau: \n");
	Print_LRN(my_tree);

    return 0;
}
