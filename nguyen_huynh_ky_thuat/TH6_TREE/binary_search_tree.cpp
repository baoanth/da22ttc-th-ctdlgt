#include <stdio.h>
#include <stdlib.h>

//khai bao cay

typedef struct TNODE
{
	int key;
	struct NODE*pLeft, *pRight;
}TNODE;
typedef TNODE*TREE;

//Duyet cay thu tu truoc

void Print_NLR (TREE Root)
{
	if (Root != NULL)
	{
		printf("%3d",Root->Key);
	    print_NLR(Root->pLeft);
		print_NLR (Root->pRight);
		
	}
}
//Duyet cay thu tu giua

void Print_LNR(TREE Root)
{
	if (Root != NULL)
	{
		Print_LNR(Root->pLeft);
		Printf("%3d", Root->Key);
		Print_LNR(Root->pRight);
		
	}
}

//Duyet cay thu tu sau 
void Print_LRN(TREE Root)
{
	if(Root != NULL)
	{
		Print_LRN(Root->Left);
		Print_LRN(Root->Right);
		printf("%3d", Root->Key);
	}
}

//Tim moy phan tu x trong cay

TNODE* searchNode(TREE Root, Data X)
{
	NODE *p = Root;
	while (p != NULL)
	{
		if(x == p->Key)
		   return p;
	else	if(x < p->Key)
		p = p->pLeft;
	else  
		p = p->pRight;
	}
	return NULL;
}
	

