#include <stdio.h>
#include <stdlib.h>

//khai bao cay
typedef struct TNODE
{
    int Key; 
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

/*In cay theo thu tu truoc*/
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
       	printf("%3d", Root->Key);
		Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

/*In cay theo thu tu giua*/
void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
		Print_LNR(Root->pLeft);
		printf("%3d", Root->Key);		
		Print_LNR(Root->pRight);
    }
}

/*In cay theo thu tu sau*/
void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->pLeft);		
		Print_LRN(Root->pRight);
    	printf("%3d", Root->Key);
    }
}

/*Tim kiem nut co gia tri la x*/
TNODE* SearchNode(TREE Root, int x)
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

/*Them nut vao cay BTS*/
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
   	
	T = new TNODE;
    if (T == NULL)
        return -1; 
    T->Key = x;  
    T->pLeft = T->pRight = NULL;
    	return 1; 
}

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    
    InsertNode(my_tree,30);
    
    InsertNode(my_tree,22);
    
    InsertNode(my_tree,26);
    
    InsertNode(my_tree,45);
    
    InsertNode(my_tree,50);
    
    InsertNode(my_tree,38);
    
    InsertNode(my_tree,33);
    
    InsertNode(my_tree,12);
    
    InsertNode(my_tree,21);
    
    InsertNode(my_tree,27);
    
    InsertNode(my_tree,36);

    Print_NLR(my_tree);
    printf("\n");
    Print_LNR(my_tree);
    printf("\n");
    Print_LRN(my_tree);

}


