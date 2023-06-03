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

void ChucNangMENU(int &x)
{
	TREE my_tree = NULL;
	int sl, n, i;
	
	printf("----MENU----\n");
	printf("1. Tao cay nhi phan\n");
	printf("2. Node Left Right\n");
	printf("3. Left Node Right\n");
	printf("4. Left Right Node\n");
	printf("5. Find Node\n");
	printf("0. EXIT\n");
	
	printf("Nhap chuc nang so: ");
	scanf("%d", &sl);
	
	while(1)
	{
		if(sl == 1)
		{
			while(i<n)
    		{
	        	int a[n];
	        	printf("Nhap gia tri %d: ", i+1);
	        	scanf("%d", &a[i]);
	        	InsertNode(my_tree, a[i]);
	        	i++;
    		}
		}
		if (sl == 2)
        {
            printf(" Node Left Right: ");
            Print_NLR(my_tree);
            printf("\n");
        }

        if (sl == 3)
        {
            printf("Left Node Right : ");
            Print_LNR(my_tree);
            printf("\n");
        }

        if (sl == 4)
        {
            printf("Left Right Node: ");
            Print_LRN(my_tree);
            printf("\n");
        }
        if (sl == 5)
        {
        	SearchNode(my_tree, x); 
        }
       /*if (sl == 6)
        {
            printf("\nNhap x muon xoa: ");
            scanf("%d", &x);
            int sl = delNode(my_tree, x);
            if (sl == 0)
                printf("Khong thay gia tri can xoa!");
            else
                printf("Xoa roi nhe");
                printf("\n");
        }*/
        if (sl == 0)
        {
        	 system("cls");
        	 break;
        }   
	}	
}
	
	

int main()
{
	TREE my_tree = NULL;
	int kt, i, n, x;

	 while(1)
    {
    	printf("MENU LUA CHON:\n");
    	printf("1. Them cay nhi phan\n");
    	printf("0. EXIT\n");

        int kt;
		printf("\nChon chuc nang so: ");
        scanf("%d", &kt);
        
        if(kt==1)
        {
        	system("cls");
			ChucNangMENU(x);
        }
		else if(kt==0)
		{
			break;
		}
	if(kt!=0 && kt!=1) printf("\nMoi ban nhap lai chuc nang!\n\n");
	}
	
/*     
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
