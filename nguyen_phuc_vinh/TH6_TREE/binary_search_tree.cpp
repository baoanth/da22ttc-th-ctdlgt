#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
}TNODE;

typedef TNODE *TREE;

void Print_NLR(TREE Root)
{
    if(Root!=NULL)
    {
        printf("%3d", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if(Root!=NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if(Root!=NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf("%3d", Root->Key);
    }
}

TNODE* SearchNode(TREE Root, int x)
{
	TNODE* p=Root;
	
	while(p!=NULL)
	{
		if(x==p->Key)
			return p;
		else
			if(x<p->Key)
				p=p->pLeft;
			else
				p=p->pRight;	
	}
	return NULL;
}

int InsertNode(TREE &T, int x)
{
    if(T)
    {
        if(T->Key==x)
            return 0;
        if(T->Key>x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    
    T = new TNODE;
    if(T==NULL)
        return -1;
    T->Key = x;
    T->pLeft = T->pRight = NULL;
        return 1;
}

void searchStandFor(TREE &p, TREE &q)
{
    if(q->pLeft)
        searchStandFor(p, q->pLeft);
    else
    {
        p->Key=q->Key;
        p=q;
        q=q->pRight;
    }
}

int delNode(TREE &T, int x)
{
    if(T==NULL)
        return 0;
    if(T->Key>x)
        return delNode(T->pLeft, x);
    if(T->Key<x)
        return delNode(T->pRight, x);
    else
    {
        TNODE* p=T;
        
        if(T->pLeft==NULL)
            T = T->pRight;
        else
        {
            if(T->pRight==NULL)
                T=T->pLeft;
            else
            {
                TNODE* q=T->pRight;
                searchStandFor(p,q);
            }
            delete p;
        }  
    }
}

void ChucNang()
{
	int i, n;
	TREE my_tree=NULL;
    
    printf("Nhap so luong nut cua TREE: ");
    scanf("%d", &n);

    while(i<n)
    {
    	int a[n];
    	
    	printf("Nhap gia tri nut %d: ", i+1);
    	scanf("%d", &a[i]);
    	InsertNode(my_tree, a[i]);
    	i++;
    }
}

int main()
{
	TREE my_tree = NULL;
	int kt, i, n;

	printf("MENU LUA CHON:\n");
    printf("1. Them cay nhi phan\n");
    printf("0. EXIT");

    printf("\n\nNhap chuc nang MENU: ");
    scanf("%d", &kt);


	while(1)
	{
		if(kt==0)
		{
			break;
		}else if (kt==1)
        {
            system("cls");
            ChucNang();
        }
	}


/*	int i, n;
    printf("Nhap so luong nut cua TREE: \n");
    scanf("%d", &n);

    while(i<n)
    {
    	int a[n];
    	
    	printf("Nhap gia tri nut %d: ", i+1);
    	scanf("%d", &a[i]);
    	InsertNode(my_tree, a[i]);
    	i++;
    }
	
/*  InsertNode(my_tree, 20);
    InsertNode(my_tree, 30);
    InsertNode(my_tree, 10);
    InsertNode(my_tree, 12);
    InsertNode(my_tree, 2);
    InsertNode(my_tree, 11);
    InsertNode(my_tree, 34);
    InsertNode(my_tree, 46);
    InsertNode(my_tree, 23);
    InsertNode(my_tree, 16);
    
    printf("Node Left Right: ");
    Print_NLR(my_tree);
	printf("\nLeft Node Right: ");    
    Print_LNR(my_tree);
    printf("\nLeft Right Node: ");
    Print_LRN(my_tree);
    
    int x;
    
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);  
    
    TNODE* Find = SearchNode(my_tree, x);

    if(Find!=NULL)
    {
    	printf("Tim thay gia tri %d", x);
    }
    else
    {
    	printf("Khong tim thay gia tri");
    }
*/
    
    return 0;
}
