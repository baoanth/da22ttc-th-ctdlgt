#include<stdio.h>
#include<stdlib.h>

typedef struct TNODE
{
	int Key;
	struct TNODE *pLeft, *pRight;
}TNODE;

typedef TNODE*TREE;

void NLR(TREE Root)
{
	if (Root != NULL)
	{
		printf("%5d", Root->Key);
		NLR(Root->pLeft);
		NLR(Root->pRight);
	}
}

void LNR(TREE Root)
{
	if (Root != NULL)
	{
		LNR(Root->pLeft);
		printf("%5d", Root->Key);
		LNR(Root->pRight);
	}
}

void LRN(TREE Root)
{
	if(Root != NULL)
	{
		 LRN(Root->pLeft);
		 LRN(Root->pRight);
		 printf("%5d", Root->Key);	}
}

TNODE* searchNode(TREE T, int x)
{
	if(T)
	{
		if (T->Key == x)
	 	    return T;
		if (T->Key > x)
		    return searchNode(T->pLeft, x);
		else
		    return searchNode(T->pRight, x);
	}
	return NULL;
}

int InsertNode(TREE &T, int x)
{
	 if(T)
	 {
	 	if(T->Key == x)
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
	 T->pLeft = T->pRight =NULL;
	 return 1;	 	     
}

int main()
{
	TREE my_tree = NULL;
	
	int a[]={8,3,5,2,20,11,30,9,18,4};
	
	for(int i=0; i<10; i++)
	    InsertNode(my_tree,a[i]);
/*	InsertNode(my_tree,8);
	InsertNode(my_tree,3);
    InsertNode(my_tree,5);
    InsertNode(my_tree,2);
	InsertNode(my_tree,20);
	InsertNode(my_tree,11);
	InsertNode(my_tree,30);
	InsertNode(my_tree,9);
	InsertNode(my_tree,18);
	InsertNode(my_tree,4); */
	NLR(my_tree);
	printf("\n");
	LNR(my_tree);
	printf("\n");
	LRN(my_tree);
	
	int x;
	printf("\n nhap gia tri x can tim = ");
	scanf("%d",&x);
	TNODE *value=searchNode(my_tree, x);
	if(value == NULL)
	{
		printf("khong tim thay %d",x);
	}
	else
	    printf("Tim thay gia tri %d",x);
}





