<<<<<<< HEAD
#include<stdio.h>
#include<conio.h>

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
=======
#include <stdio.h>
#include <stdlib.h>


typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%3d", Root->Key);
		Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);		
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
    	printf("%3d", Root->Key);		
    }
}

TNODE *SearchNode(TREE Root, int x)
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

int InsertNode(TREE &T, int X)
{
    if (T)
    {
        if (T->Key == X)
            return 0;
        if (T->Key > X)
            return InsertNode(T->pLeft, X);
        else
            return InsertNode(T->pRight, X);
    }
   
    T = new TNODE;
    if (T == NULL)
        return -1;
    
    T->Key = X;  
    T->pLeft = T->pRight = NULL;
    return 1; 
}

void SearchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft)
		SearchStandFor(p, q->pLeft);
	else
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
	}
}

int DeleteNode(TREE &T, int x)
{
	if(T==NULL)	return 0;
	if(T-> Key > x)
		return DeleteNode(T-> pLeft, x);
	if(T-> Key < x)
		return DeleteNode(T-> pRight, x);
	else
	{
		TNODE *p =T;
	
		if(T-> pRight == NULL)
			T= T-> pLeft;
		else
		{
			TNODE *q = T->pRight;
			SearchStandFor(p,q);
		}
	delete p;
	}
>>>>>>> d7a911db6973d4f4ef42cd331a7a3b26ba109617
}

int main()
{
<<<<<<< HEAD
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






=======
	int x,n,i;
	char c;
	
    TREE my_tree = NULL;
    
//    InsertNode(my_tree, 80);
//    InsertNode(my_tree, 45);
//    InsertNode(my_tree, 13);
//    InsertNode(my_tree, 72);
//    InsertNode(my_tree, 25);
//    InsertNode(my_tree, 38);
//    InsertNode(my_tree, 33);
//    InsertNode(my_tree, 12);
//    InsertNode(my_tree, 21);
//    InsertNode(my_tree, 27);
//    InsertNode(my_tree, 36);
    
    printf("Nhap so nut tren cay: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
    	printf("Nhap gia tri cho nut %d: ",i);
		scanf("%d",&x);
		InsertNode(my_tree, x);
    }
    
   	printf("\nSap xep cay theo NLR:  ");
    Print_NLR(my_tree);
    printf("\n\nSap xep cay theo LNR:  ");
    Print_LNR(my_tree);
    printf("\n\nSap xep cay theo LRN:  ");
    Print_LRN(my_tree);
    		
	printf("\n\nNhap x can tim: ");
	scanf("%d",&x);
	if(SearchNode(my_tree,x)==NULL)
	{
		printf("Khong tim thay %d trong day ",x);
	}
	else
	{
		printf("Tim thay %d trong day ",x);
	}
	
//	printf("\n\nNhap x can chen: ");
//	scanf("%d",&x);
//	InsertNode(my_tree, x);
//	printf("\nSau khi chen %d vao: ",x);
//	Print_LNR(my_tree);
//	
//	printf("\nXoa gia tri x cua cay: ");
//	scanf("%d",&x);
//	DeleteNode(my_tree,x);
//	printf("\nSau khi xoa %d: ",x);
//	Print_LNR(my_tree);
	
	printf("\n");
	while(1) 
	{
		printf("\nNhap thao tac can thuc hien: ");
		printf("\n0.Thoat ra");
		printf("\n1.Chen them nut");
		printf("\n2.Xoa nut");
		printf("\n3.Sap xep cay theo NLR");
		printf("\n4.Sap xep cay theo LNR");
		printf("\n5.Sap xep cay theo LRN\n");		
		scanf("%d",&c);
		
		if(c==0)	break;
		else if(c==1)
		{
			printf("\n\nNhap x can chen: ");
			scanf("%d",&x);
			InsertNode(my_tree, x);
			printf("\nSau khi chen %d vao: ",x);
			Print_LNR(my_tree);
		}
		else if(c==2)
		{
			printf("\nXoa gia tri x cua cay: ");
			scanf("%d",&x);
			DeleteNode(my_tree,x);
			printf("\nSau khi xoa %d: ",x);
			Print_LNR(my_tree);
		}
		else if(c==3)
		{
			printf("\nSap xep cay theo NLR:  ");
   			Print_NLR(my_tree);
		}
		else if(c==4)
		{
			printf("\nSap xep cay theo LNR:  ");
    		Print_LNR(my_tree);
		}
		else if(c==5)
		{
			printf("\nSap xep cay theo LRN:  ");
    		Print_LRN(my_tree);
		}
   }

	return 0;
}

>>>>>>> d7a911db6973d4f4ef42cd331a7a3b26ba109617
