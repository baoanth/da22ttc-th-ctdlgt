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

TNODE* SearchNode(TREE Root, int x)
{
	TNODE* p=Root;
	
	while(p!=NULL)
	{
		if(x==p->Key)
			return p;
		else
			if(x<p->Key)
				p=p->pLeft;
			else
				p=p->pRight;	
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
    
    int x;
    
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);  
    
    TNODE* Find = SearchNode(my_tree, x);

    if(Find!=NULL)
    {
    	printf("Tim thay gia tri %d", x);
    }
    else
    {
    	printf("Khong tim thay gia tri");
    }
    
    return 0;
}
