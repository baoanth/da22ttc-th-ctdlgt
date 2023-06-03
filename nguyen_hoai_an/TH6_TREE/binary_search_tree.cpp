#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode
{
    int Key;
    struct TNode *pLeft, *pRight;
}TNode;
typedef TNode* TREE;

void Print_NLR(TREE Root)
{
    if(Root !=NULL)
    {
        printf(" %5d ", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if(Root !=NULL)
    {
        Print_LNR(Root->pLeft);
        printf(" %5d ", Root->Key);
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if(Root !=NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf(" %5d ", Root->Key);

    }
}

TREE SearchNode(TREE T, int x)
{
    if(T) 
    {
        if(T->Key== x)  
            return T;
        if(T->Key > x) 
            return SearchNode(T->pLeft, x);
        else 
            return SearchNode(T->pRight, x);
    }
    return NULL;
}

int InsertNode(TREE &T, int x)
{
    if(T) 
    {
        if(T->Key == x)
            return 0;
        if(T->Key > x)
            return InsertNode(T->pLeft, x);
        else 
            return InsertNode(T->pRight, x);
    }
    T = new TNode;
    if(T == NULL)
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
        p = q;
        q = q->pRight;
    }
}

int DelNode(TREE &T, int x)
{
    if(T == NULL)
    return 0;
    if(T->Key > x)
    return DelNode(T->pLeft, x);
    if(T->Key < x)
    return DelNode(T->pRight, x);
    else
    {
        TNode* p = T;
        if(T->pLeft == NULL)
        T = T->pRight;
        else 
        if(T->pRight == NULL)
        T = T->pLeft;
        else
        {
            TNode* q = T->pRight;
            SearchStandFor(p,q);
        }
        delete p;
    }
}

int main()
{
    TREE my_tree = NULL;

    int n, i;
    printf("Nhap so luong tree: ");
    scanf("%d", &n);

    while(i<n)
    {
        int a[n];
        printf("Nhap gia tri nut %d : ", i);
        scanf("%d", &a[i]);
        InsertNode(my_tree, a[i]);
        i++;
    }

/*
 	InsertNode(my_tree, 15); 
    InsertNode(my_tree, 24);
	InsertNode(my_tree, 39);
	InsertNode(my_tree, 50);
    InsertNode(my_tree, 4);
    InsertNode(my_tree, 13);
    InsertNode(my_tree, 20);
	InsertNode(my_tree, 1);
	InsertNode(my_tree, 19);
	InsertNode(my_tree, 36);

    printf("Duyet theo thu tu truoc: \n");
    Print_NLR(my_tree);
    
    printf("\nDuyet theo thu tu giua: \n");
	Print_LNR(my_tree);

    printf("\nDuyet theo thu tu sau: \n");
	Print_LRN(my_tree);
	*/

	int Key;
    printf("\n");
    printf("\nNhap Node can tim: ");
    scanf("%d", &Key);

    TNode* newKey = SearchNode(my_tree, Key);
    if( newKey!= NULL)
    {
        printf("Da tim thay %d trong cay.\n");
    }
    else
    {
        printf("Khong co dau ma tim haha.");
    }

    
    printf("\nNhap Node can xoa: ");
    scanf("%d", &Key);

    int KqDelete = DelNode(my_tree, Key);
    
    if (KqDelete!= NULL)
    {
        printf(" Da xoa.\n");
        printf("\n");
        printf(" Thu tu truoc: \n");
	    Print_NLR(my_tree);
	    printf("\n Thu tu giua: \n");
	    Print_LNR(my_tree);
	    printf("\n Thu tu sau: \n");
	    Print_LRN(my_tree);
    }
    else
    {
        printf("Khong the xoa.");
    } 


    return 0;
}
