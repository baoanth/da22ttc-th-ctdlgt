#include<stdio.h>
#include<stdlib.h>

//Khai bao cay
typedef struct TNODE
{
	int key;
	struct NODE *pLeft, *pRight;
}TNODE;
typedef TNODE *TREE;

/*In cay theo thu tu truoc*/
void Print_NLR(TREE Root)
{
	if(Root != NULL)
	{
		printf("%3d", Root->key);
		printf_NLR (Root->pLeft);
		printf_NLR (Root->pRight);
	}
}

/*In cay theo thu tu giua*/
void Print_LNR(TREE Root)
{
	if(Root! = NULL)
	{
		print_LNR (Root->Left);
		printf("%3d", Root->key);
		print_LNR (Root->Right);
	}
}

/*In cay theo tu thu sau*/
void Printf_LRN(TREE Root)
{
	if(Root! = NULL)
	{
		print_LRN (Root->Left);
		print_LRN (Root->Right);
		printf("%3d", Root->key);
	}
}

/*Tim kiem nut co gia tri la x*/
int SearchNODE(TREE T, int x)
{
	if(T)
	{
		if(T->Key == x)
			return T;
		if(T->Key > x)
			return searchNODE(T->pLeft, x);
		else
			return searchNODE(T->pRight, x);
	}
}

/*Them nut vao cay BST*/
int InsertNODE(TREE &T, int x)
{
	if(T)
	{
		if(T->Key == x)
			return 0;
		if(T->Key > x)
			return InsertNODE(T->pLeft, x);
		else
			return InsertNODE(T->pRight, x);
			
			
	}
}



