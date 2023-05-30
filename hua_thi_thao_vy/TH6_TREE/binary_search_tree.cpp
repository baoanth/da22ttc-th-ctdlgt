#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE
{
	int Key;
	struct TNODE *pLeft, *pRight;
}TNODE;
typedef TNODE*TREE;

void Print_NLR(TREE Root)
{
	if (Root !=NULL)
	{
		printf("%4d", Root->Key);
		Print_NLR(Root->pLeft);
		Print_NLR(Root->pRight);
	}
}

void Print_LNR(TREE Root)
{
	if (Root !=NULL)
	{
		Print_LNR(Root->pLeft);
		printf("%4d", Root->Key);
		Print_LNR(Root->pRight);
	}
}

void Print_LRN(TREE Root)
{
	if (Root != NULL)
	{
		Print_LRN(Root->pLeft);
		Print_LRN(Root->pRight);
		printf("%4d", Root->Key);
	}
}

TNODE* SearchNode(TREE T, int x)
{
	if(T)
	{
		if(T->Key == x)
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
	T = new TNODE;
	if(T == NULL)
	    return -1;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}

int main()
{
	TREE my_tree = NULL;
	
	InsertNode(my_tree, 12);
	InsertNode(my_tree, 4);
	InsertNode(my_tree, 10);
	InsertNode(my_tree, 26);
	InsertNode(my_tree, 9);
	InsertNode(my_tree, 1);
	InsertNode(my_tree, 97);
	InsertNode(my_tree, 30);
	InsertNode(my_tree, 6);
	InsertNode(my_tree, 95);
	
	Print_NLR(my_tree);
	printf("\n");
	Print_LNR(my_tree);
	printf("\n");
	Print_LRN(my_tree);
	
	int x;
	printf("\nTim gia tri cua x= ");
	scanf("%d", &x);
	TNODE *giatri=SearchNode(my_tree, x);
	if(giatri == NULL)
	{
		printf("Khong tim thay gia tri ");
	}
	else 
	    printf("Tim thay gia tri");
}
