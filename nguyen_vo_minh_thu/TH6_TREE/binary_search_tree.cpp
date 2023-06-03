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

//Tim phan tu the cho nut p
void searchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft) 
		searchStandFor(p, q->pLeft);
	else 
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
	}
}

//Xoa
int delNode(TREE &T, int X)
{
	if(T == NULL)
		return 0;
	if(T->Key > X)
		return delNode (T->pLeft, X);
	if(T->Key < X)
		return delNode (T->pRight, X);
	else 
	{
		TNODE* p = T;
		if(T->pLeft == NULL)
			T = T->pRight;
		else
		{
			if(T->pRight == NULL)
				T = T->pLeft;
			else
			{
				TNODE* q = T->pRight;
				searchStandFor(p,q);
			}
		delete p;
		}
		                                    
	}
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
	
	printf("\nIn theo thu tu truoc:\n");
	Print_NLR(my_tree);
    printf("\n");
    printf("\nIn theo thu tu giua:\n");
    Print_LNR(my_tree);
    printf("\n");
    printf("\nIn theo thu tu cuoi:\n");
    Print_LRN(my_tree);
    
	int X;
	printf("\n\nBan muon tim node bao nhieu: ");
	scanf("%d", &X);
	
	TNODE* tk=SearchNode(my_tree, X);
	if(tk == NULL)
		printf("\nKhong tim thay %d trong cay", X);
	else
		printf("\nDa tim thay %d trong cay", X);
		
	int Y;
	printf("\n\nBan muon xoa node bao nhieu: ");
	scanf("%d", &Y);
	
	int  xoa= delNode(my_tree, Y);
	if(xoa == NULL)
		printf("\nKhong the xoa %d trong cay", Y);
	else
		printf("\nDa xoa %d trong cay", Y);
	
	printf("\nIn theo thu tu truoc sau khi xoa:\n");
	Print_NLR(my_tree);
    printf("\n");
    printf("\nIn theo thu tu giua sau khi xoa:\n");
    Print_LNR(my_tree);
    printf("\n");
    printf("\nIn theo thu tu cuoi sau khi xoa:\n");
    Print_LRN(my_tree);
    
}























