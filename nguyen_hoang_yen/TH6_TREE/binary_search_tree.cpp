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
//TImkiem X
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

//HAm tao Node
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

void searchStandFor(TREE &p, TREE &q)
{
	if (q-> pLeft) searchStandFor(p, q -> pLeft);
	else
	{
		p -> key = q -> key;
		p = q;
		q = q -> pRight;
	}
}

int delNode(TREE &t , int x)
{
	if(t==NULL)
		return 0;
	if(t -> key > x)
		return delNode (t -> pLeft, x);
	if(t -> key < x)
		return delNode (t -> pRight, x);
	else 
	{
		TNODE*	p = t;
			if(t -> pLeft == NULL )
				t = t -> pRight;
			else 
				if( t -> pRight == NULL) 
					t = t -> pLeft;	
				else
				{
					TNODE*	q = t -> pRight;
					searchStandFor(p, q);
				}
		delete p;		
	}
}


int main()
{
	TREE my_tree = NULL;    
	
	
//	insertNode(my_tree, 10);
//	insertNode(my_tree, 24);
//	insertNode(my_tree, 26);
//	insertNode(my_tree, 11);
//	insertNode(my_tree, 04);	
	
	 int k;
    printf("\nBan muon nhap bao nhieu Node chp cay: ");
    scanf("%d", &k);
    
    for(int i = 1; i<=k; i++)
    {
    	int tmp;
    	printf("\nNhap vao gia tri thu %d: ", i);
    	scanf("%d", &tmp);
    	insertNode(my_tree, tmp);
    }

	
	printf("in theo thu tu dau");
	printf("\n");
	print_NLR(my_tree);
		
	printf("\nin theo thu tu giua");
	printf("\n");
	print_LNR(my_tree);
	
	printf("\nin theo thu tu cuoi");
	printf("\n");
	print_LRN(my_tree);
	
	int X;
	printf("\nBan muon tim kiem Node bao nhieu: ");
	scanf("%d", &X);
	
	TNODE* tk =  searchNode(my_tree, X);
	if(tk == NULL) 
		printf("Ko tim thay %d trong cay nhi phan", X);
	else 
		printf("Tim thay %d trong cay nhi phan", X);
		
	int Y;
	printf("\nNhap Node can xoa:");
	scanf("%d", &Y);
	
	int  kt = delNode(my_tree, Y);
	if(kt == NULL) 
		printf("ko xoa dc %d trong cay nhi phan   ", Y);
	else 
		printf("da xoa %d trong cay nhi phan", Y);
	
	printf("in theo thu tu dau");
	printf("\n");
	print_NLR(my_tree);
		
	printf("\nin theo thu tu giua");
	printf("\n");
	print_LNR(my_tree);
	
	printf("\nin theo thu tu cuoi");
	printf("\n");
	print_LRN(my_tree);
	
    return 0;
}




















