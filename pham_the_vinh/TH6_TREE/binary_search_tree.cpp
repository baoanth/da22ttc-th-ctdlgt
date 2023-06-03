#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;

typedef TNODE *TREE;

void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%5d", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%5d", Root->Key);
        Print_LNR(Root->pRight);
    }
}

void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf("%5d", Root->Key);
    }
}

TNODE *SearchNode(TREE T, int x)
{
    if (T)
    {
        if (T->Key == x)
            return T;
        if (T->Key > x)
            return SearchNode(T->pLeft, x);
        else
            return SearchNode(T->pRight, x);
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
    if (q->pLeft)
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
    if (T == NULL)
        return 0;
    if (T->Key > x)
        return DeleteNode(T->pLeft, x);
    if (T->Key < x)
        return DeleteNode(T->pRight, x);
    else
    {
        TNODE *p = T;
        if (T->pLeft == NULL)
            T = T->pRight;
        else if (T->pRight == NULL)
            T = T->pLeft;
        else
        {
            TNODE *q = T->pRight;
            SearchStandFor(p, q);
        }
        delete p;
    }
}

int main()
{
    TREE my_tree = NULL;
    
    int n;
    printf("- Nhap so nut cua cay: ");
    scanf("%d", &n);
    
	int i;
    while(i<n)
    {
    	int a[n];
    	printf("Nhap gia tri nut %d: ", i);
    	scanf("%d", &a[i]);
    	InsertNode(my_tree, a[i]);
    	i++;
    }

    printf("- Thu tu truoc: ");
    Print_NLR(my_tree);
    printf("\n- Thu tu giua: ");
    Print_LNR(my_tree);
    printf("\n- Thu tu sau: ");
    Print_LRN(my_tree);

    int x;
    printf("\n\n- Nhap gia tri can tim: ");
    scanf("%d", &x);

    TNODE *KqSearch = SearchNode(my_tree, x);
    if (KqSearch != NULL)
    {
        printf("--- Da tim thay ---");
    }
    else
    {
        printf("--- Khong tim thay ---");
    }

	int d;
	printf("\n\n- Nhap gia tri can xoa: ");
	scanf("%d", &d);
	    
    int KqDelete = DeleteNode(my_tree, d);
    
    if (KqDelete != NULL)
    {
        printf("--- Da xoa ---\n");
        printf("Thu tu truoc: ");
	    Print_NLR(my_tree);
	    printf("\nThu tu giua: ");
	    Print_LNR(my_tree);
	    printf("\nThu tu sau: ");
	    Print_LRN(my_tree);
    }
    else
    {
        printf("--- Khong tim thay gia tri can xoa ---");
    }
    
    return 0;
}
