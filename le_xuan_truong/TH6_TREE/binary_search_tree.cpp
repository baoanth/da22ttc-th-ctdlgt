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
	if(q->pLeft)	SearchStandFor(p, q->pLeft);
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
}

int main()
{
	int x,n,i;
	
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
	
	printf("\n\nNhap x can chen: ");
	scanf("%d",&x);
	InsertNode(my_tree, x);
	printf("\nSau khi chen %d vao: ",x);
	Print_LNR(my_tree);
	
	printf("\nXoa gia tri x cua cay: ");
	scanf("%d",&x);
	DeleteNode(my_tree,x);
	printf("\nSau khi xoa %d: ",x);
	Print_LNR(my_tree);
	
	printf("\n");
//	while(1) 
//	{
//		printf("\nMa hang: ");
//		fflush(stdin);
//		gets();
//		
//		if (strncmp(, "EXIT", 4)==0){
//   			break;
//   }
//}
	
	return 0;
}

