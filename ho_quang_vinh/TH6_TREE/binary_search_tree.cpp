#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNODE
{
 int Key;
struct NODE *pLeft, *pRight;
}TNODE;
typedef TNODE*TREE;
int insertNode(TREE T, int X)
{
if(T) {
if(T->Key == X)
 return 0;
if(T->Key > X)
 return insertNode(T->pLeft, X);
else 
 return insertNode(T->pRight, X);
}
T = new TNODE;
if( T->key == x)
return T;
if (T->key > x)
T->pleft = T->PRight = NULL;
return 1;
}
TNODE* searchNode(TREE T, int X)
{
if(T) 
{
if(T->Key == X)
 return T;
if(T->Key > X) 
 return searchNode(T->pLeft, X);
else
 return searchNode(T->pRight, X);
}
return NULL;
}
void NLR(TREE Root)
{
if (Root != NULL)
{
    NLR(Root->pLeft);
    NLR(Root->pRight);
}
}
void LNR(TREE Root)
{
if (Root != NULL)
{

     LNR(Root->Left);
     LNR(Root->Right);
}
}
int main()
{
	int my_tree[]=( 13, 9, 5, 27, 5, 29, 10, 6, 11, 4);
	printf("xuat mang;\n");
	printf_tree(my_tree);
	printf("\n");
	NLR (my_tree);
	LNR(my_tree);
	LRN(my_tree);
return 0;
}	

