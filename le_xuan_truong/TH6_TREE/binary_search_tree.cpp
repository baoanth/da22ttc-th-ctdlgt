#include <stdio.h>
#include <stdlib.h>


typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%3d", Root->Key);
		Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);		
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
    	printf("%3d", Root->Key);		
    }
}

TNODE *SearchNode(TREE Root, int x)
{
    TNODE *p = Root;
    while (p != NULL)
    {
        if (x == p->Key)
            return p;
        else if (x < p->Key)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return NULL;
}

int InsertNode(TREE &T, int X)
{
    if (T)
    {
        if (T->Key == X)
            return 0;
        if (T->Key > X)
            return InsertNode(T->pLeft, X);
        else
            return InsertNode(T->pRight, X);
    }
   
    T = new TNODE;
    if (T == NULL)
        return -1;
    
    T->Key = X;  
    T->pLeft = T->pRight = NULL;
    return 1; 
}


int main()
{
    TREE my_tree = NULL;
    
    InsertNode(my_tree, 80);
    InsertNode(my_tree, 45);
    InsertNode(my_tree, 13);
    InsertNode(my_tree, 72);
    InsertNode(my_tree, 25);
    InsertNode(my_tree, 38);
    InsertNode(my_tree, 33);
    InsertNode(my_tree, 12);
    InsertNode(my_tree, 21);
    InsertNode(my_tree, 27);
    InsertNode(my_tree, 36);
    
    
	printf("Sap xep cay theo NLR:  ");
    Print_NLR(my_tree);
    printf("\n\nSap xep cay theo LNR:  ");
    Print_LNR(my_tree);
    printf("\n\nSap xep cay theo LRN:  ");
    Print_LRN(my_tree);

	return 0;
}

