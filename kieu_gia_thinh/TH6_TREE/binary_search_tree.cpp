#include <stdio.h>
#include <stdlib.h>

// Khai bao cay
typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

//In cay theo thu tu truoc
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%3d", Root->Key);
		
		Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

//In cay theo thu tu giua
void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);		
        Print_LNR(Root->pRight);
    }
}

//In cay theo thu tu sau
void Print_LRN(TREE Root)
{
	 if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        Print_LNR(Root->pRight); 
		printf("%3d", Root->Key);	
    }
}

/*Tim kiem nut co gia tri la x*/
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

//Them nut vao cay
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

//Tim phan tu the mang cho nut p
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

//Huy mot phan tu co khoa X
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

//Khai bao cay, chen vao 10 nut, in ra 3 kieu
int main()
{
    TREE my_tree = NULL;
    
	int k;
	
//Dieu kien de chay chuong trinh
	do
	{
    	printf("Ban muon nhap bao nhieu nut cho cay nhi phan: ");
		scanf("%d", &k);
	
    	if(k<=0)     
			printf("Ban da nhap sai. Yeu cau ban nhap vao so duong de chuong trinh chay.\n\n");
    }while(k<=0);
	
	for(int i = 1; i<=k; i++)
	{	
		int tmp;
		printf("Nhap vao gia tri thu %d: ", i);
		scanf("%d", &tmp);
		InsertNode(my_tree, tmp);
	}
	
		
//In
	printf("In theo thu tu truoc\n");
    Print_NLR(my_tree);
    printf("\n");
    printf("In theo thu tu giua\n");
    Print_LNR(my_tree);
    printf("\n");
	printf("In theo thu tu sau\n");
    Print_LRN(my_tree);
    
//Tim phan tu X
    int X;
    printf("\n\nNhap Node can tim :");
    scanf("%d", &X);
    
    
    TNODE* Tk = SearchNode(my_tree, X);
    if(Tk == NULL) 
    	printf("Khong tim thay %d", X);
    else 
    	printf("Da tim thay %d", X);

//XOA
	int n, biendem = 0;
	
	
	do
	{
		printf("\n\nBan muon xoa may lan: ");
		scanf("%d", &n);
		if(n<=0) 
			printf("Ban da nhap sai. Yeu cau nhap vao so nguyen duong de chuong trinh xoa nut chay.");
	} while(n<=0);
	
	
	
//********************************
	for(int i = 1; i<=n; i++)
	{
		biendem++;
		
		//Xoa phan tu
		int Y;
		printf("\nNhap vao Node can xoa lan thu %d: ", biendem);
		scanf("%d", &Y);
	
		int Xoa = DelNode(my_tree, Y);
		if(Xoa == NULL) 
    		printf("Khong xoa duoc: %d", Y);
  	 	else 
    		printf("Da xoa: %d", Y);
	}
//In lai sau khi xoa Node
		printf("\nIn theo thu tu truoc sau khi xoa %d lan\n", biendem);
   	 	Print_NLR(my_tree);
    	
		printf("\n");
		
    	printf("In theo thu tu giua sau khi xoa %d lan\n", biendem);
    	Print_LNR(my_tree);
    	
		printf("\n");
    	
		printf("In theo thu tu sau sau khi xoa %d lan\n", biendem);
    	Print_LRN(my_tree);
    	
    return 0; 
}


