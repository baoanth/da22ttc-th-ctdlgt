#include <stdio.h>
#include <stdlib.h>

//Khai bao cay
typedef struct TNODE
{
   int Key;
   struct  TNODE *pLeft, *pRight;

}TNODE;

typedef TNODE *TREE;



/*In cay theo thu tu truoc*/
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        NLR(Root->pLeft);
        NLR(Root->pRight);

    }
}
/*In cay theo thu tu giua*/
void Print_LNR(TREE Root)
{
    if(Root !=NULL)
    {
        LNR(Root->Left);
        LNR(Root->Right);
    }
}
/*In cay theo thu tu sau*/
void Print_LRN(TREE Root)
{
    if(Root !=NULL)
    {
        LRN(Root->Left);
        LRN(Root->Right);
    }
}
/*Tim kiem nut co gia tri la x*/
int SearchNode(TREE T,int X)
{
    if (T)
    {
        if(T-> Key == X)
        return T;
        if(T-> Key > X)
        return SearchNode(T->pLeft,X);
        else return SearchNode(T->Right, X);

    }
    return NULL;
}

/*Them nut vao cay BST*/
int insertNode(TREE &T,int X)
{
    if(T) 
    {
        if(T->Key == X)
        return 0; 
        if(T->Key > X)
        return insertNode(T->pLeft, X);
        else
        return insertNode(T->pRight, X);
    }
    T = new TNode;
    if(T == NULL)
    return -1; 
    T->Key = X;
    T->pLeft =T->pRight = NULL;
    return 1; 
}
/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
   
   
    

    return 0;
}
