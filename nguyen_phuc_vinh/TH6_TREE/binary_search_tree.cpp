#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
}TNODE;

typedef TNODE *TREE;

void Print_NLR(TREE Root)
{
    if(Root!=NULL)
    {
        printf("%3d", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if(Root!=NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if(Root!=NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf("%3d", Root->Key);
    }
}

TNODE* SearchNode(TREE T, int x)
{
	if(T)
	{
		if(T->Key==x)
		    return T;
	    if(T->Key>x)
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
        if(T->Key==x)
            return 0;
        if(T->Key>x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    
    T = new TNODE;
    if(T==NULL)
        return -1;
    T->Key = x;
    T->pLeft = T->pRight = NULL;
        return 1;
}

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
	TREE my_tree = NULL;
	
    InsertNode(my_tree, 20);
    InsertNode(my_tree, 30);
    InsertNode(my_tree, 10);
    InsertNode(my_tree, 12);
    InsertNode(my_tree, 2);
    InsertNode(my_tree, 11);
    InsertNode(my_tree, 34);
    InsertNode(my_tree, 46);
    InsertNode(my_tree, 23);
    InsertNode(my_tree, 16);
    
    printf("Node Left Right: ");
    Print_NLR(my_tree);
	printf("\nLeft Node Right: ");    
    Print_LNR(my_tree);
    printf("\nLeft Right Node: ");
    Print_LRN(my_tree);
    
}
