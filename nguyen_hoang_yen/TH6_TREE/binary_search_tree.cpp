#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct TNODE
{
	int key;
	struct TNODE *pLeft, *pRight;
}TNODE;
typedef TNODE*TREE;

void print_NLR(TREE Root)
{
	if ( Root != NULL)
	{
	    printf ("%4d", Root -> key);
		print_NLR (Root -> pLeft);
		print_NLR (Root -> pRight);
	}
}
void print_LNR(TREE Root)
{
	if ( Root != NULL )
	{
		print_LNR (Root -> pLeft);
		printf ("%4d", Root -> key);
		print_LNR(Root -> pRight);
	}
}
void print_LRN(TREE Root )
{
	if ( Root != NULL)
	{
		print_LRN (Root -> pLeft);
		print_LRN (Root -> pRight); 
		printf ("%4d", Root -> key);
	}
}

TNODE* searchNode(TREE t, int x)
{
	if(t)
	{
		if(t -> key == x) 
			return t;
		if(t -> key > x)  
			return searchNode(t -> pLeft, x);
		else return searchNode(t -> pRight, x);
	}
    return NULL;
}

int insertNode(TREE &t, int x)
{
	if(t)
	{
		if(t -> key == x)
			return 0;
		if(t -> key > x)
			return insertNode(t->pLeft, x);
		else
			return insertNode(t -> pRight, x);
	}
	t = new TNODE;
	if(t == NULL)
		return -1;
	t -> key = x;
	t -> pLeft = t -> pRight = NULL;
	return 1;
}
int main()
{
	TREE my_tree = NULL;
	
	insertNode(my_tree, 30);
	insertNode(my_tree, 22);
	insertNode(my_tree, 12);
	insertNode(my_tree, 21);
	insertNode(my_tree, 26);
	insertNode(my_tree, 27);
	insertNode(my_tree, 45);
	insertNode(my_tree, 38);
	insertNode(my_tree, 33);
	insertNode(my_tree, 36);
	insertNode(my_tree, 50);
	
	printf("in theo thu tu dau");
	print_NLR(my_tree);
		printf("\n");
	printf("in theo thu tu giua");
	print_LNR(my_tree);
		printf("\n");
	printf("in theo thu tu cuoi");
	print_LRN(my_tree);

}




















