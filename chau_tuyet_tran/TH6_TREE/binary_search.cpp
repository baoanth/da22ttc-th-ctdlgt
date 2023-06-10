#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

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
        Print_LNR(Root->pLeft);
        Print_LNR(Root->pRight); 
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
        else 
			if (x < p->Key)
           		p = p->pLeft;
        	else
            	p = p->pRight;
    }
    return NULL;
}

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

void SearchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft)
		SearchStandFor(p, q->pLeft);
	else
	{
		p->Key = q->Key;
		p=q;
		q=q->pRight;
	}
}

int DelNode(TREE &T, int X)
{
    if(T==NULL) 
    return 0;
    
    if(T->Key > X) 
    return DelNode (T->pLeft, X);
    
    if(T->Key < X) 
    return DelNode (T->pRight, X);
    else 
    { 
        TNODE* p = T;
        if(T->pLeft == NULL) 
            T= T->pRight;
        else 
            if(T->pRight == NULL) 
                T = T->pLeft;
            else 
            {
                TNODE* q = T->pRight;
                SearchStandFor(p, q);
            }
        delete p;
    }
}

int main()
{
    TREE my_tree = NULL;
    
	int k;
	
	do
	{
    	printf("So nut muon nhap: ");
		scanf("%d", &k);
	
    	if(k<=0)     
			printf("Nhap sai! Hay nhap so nguyen duong de chuong trinh co the thuc hien.\n\n");
    }while(k<=0);
	
	for(int i = 1; i<=k; i++)
	{	
		int tmp;
		printf("Nhap vao gia tri thu %d: ", i);
		scanf("%d", &tmp);
		InsertNode(my_tree, tmp);
	}
			
	printf("In theo thu tu truoc:");
    Print_NLR(my_tree);
    printf("\n");
    printf("In theo thu tu giua: ");
    Print_LNR(my_tree);
    printf("\n");
	printf("In theo thu tu sau: ");
    Print_LRN(my_tree);
    
    printf ("------------------------------------");
    int X, m, j;
    
    do
    {
    	printf("\n\nTim node bao nhieu lan: ");
    	scanf("%d", &m);
    	if(m<=0) 
			printf("Nhap sai! Hay nhap so nguyen duong de chuong trinh co the thuc hien.");
    } while(m<=0);
    
    for(j = 1; j<=m; j++)
    {
    	printf("\nNhap Node can tim thu %d: ", j);
    	scanf("%d", &X);
    
    	TNODE* Tk = SearchNode(my_tree, X);
    	if(Tk == NULL) 
    		printf("Khong tim thay!", X);
    	else 
    		printf("Da tim thay!", X);
    }
    
	int n, biendem = 0;
	
	do
	{
		printf("\n\nXoa bao nhieu lan: ");
		printf(" "); scanf("%d", &n);
		if(n<=0) 
			printf("Nhap sai! Hay nhap so nguyen duong de chuong trinh co the thuc hien.");
	} while(n<=0);
		
	for(int i = 1; i<=n; i++)
	{
		biendem++;
		//Xoa phan tu
		int Y;
		printf("\nNhap vao Node can xoa lan thu %d: ", i);
		scanf("%d", &Y);
		int Xoa = DelNode(my_tree, Y);
		if(Xoa == NULL) 
    		printf("Khong the xoa!", Y);
  	 	else 
    		printf("Da xoa: %d", Y);
	}

		printf("\nIn theo thu tu truoc, sau khi xoa %d lan: \n", biendem);
   	 	Print_NLR(my_tree);
    	
		printf("\n");
		
    	printf("In theo thu tu giua, sau khi xoa %d lan: \n", biendem);
    	Print_LNR(my_tree);
    	
		printf("\n");
    	
		printf("In theo thu tu sau, sau khi xoa %d lan: \n", biendem);
    	Print_LRN(my_tree);
    	
    return 0;
}

