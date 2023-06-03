#include <stdio.h>
#include <stdlib.h>

// Khai bao cay
typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE *TREE;

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
TNODE *SearchNode(TREE T, int X)
{
    if (T)
    {
        if (T->Key == X)
            return T;
        if (T->Key > X)
            return SearchNode(T->pLeft, X);
        else
            return SearchNode(T->pRight, X);
    }
    return NULL;
}

/*Them nut vao cay BST*/
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
    if (q->pLeft)
        SearchStandFor(p, q->pLeft);
    else
    {
        p->Key = q->Key;
        p = q;
        q = q->pRight;
    }
}
// xoa nut
int DelNode(TREE &T, int X)
{
    if (T == NULL)
        return 0;
    if (T->Key > X)
        return DelNode(T->pLeft, X);
    if (T->Key < X)
        return DelNode(T->pRight, X);
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



/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{ /*
    TREE my_tree = NULL;
    InsertNode(my_tree, 30);
    InsertNode(my_tree, 22);
    InsertNode(my_tree, 12);
    InsertNode(my_tree, 21);
    InsertNode(my_tree, 26);
    InsertNode(my_tree, 27);
    InsertNode(my_tree, 45);
    InsertNode(my_tree, 50);
    InsertNode(my_tree, 38);
    InsertNode(my_tree, 33);
    InsertNode(my_tree, 36);

    Print_NLR(my_tree);
    printf("\n");
    Print_LNR(my_tree);
    printf("\n");
    Print_LRN(my_tree);
    
	
    int x,y;
    printf("\nNhap x: ");
    scanf("%d", &x);
    TNODE *gia_tri = SearchNode(my_tree, x);
    if (gia_tri == NULL)
        printf("Khong tim thay gia tri x");
    else
        printf("Tim thay gia tri x");
        
    printf("\nNhap y can xoa: ");
    scanf("%d", &y);
    
    int xoa = DelNode(my_tree, y);
    if (xoa == 0)
        printf("Khong tim thay gia tri y = %d \n", y);
    else
        printf("Da xoa nut y = %d \n", y);
	Print_NLR(my_tree);
    printf("\n");
    Print_LNR(my_tree);
    printf("\n");
    Print_LRN(my_tree);
    
    */
    TREE my_tree = NULL;
    int n, i, x;
    printf("Bai toan cay nhi phan!\n");
    printf("Vui long nhap so luong phan tu: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nNhap gia tri thu %d: ", i + 1);
        scanf("%d", &x);
        InsertNode(my_tree, x);
    }

    printf("\nDa them cac gia tri vao cay thanh cong!\n");
    while (1)
    {
        printf("\n\n----------------------------\n");
        printf("1. In cay the thu tu NLR\n");
        printf("2. In cay the thu tu LNR\n");
        printf("3. In cay the thu tu LRN\n");
        printf("4. Them gia tri x\n");
        printf("5. Tim gia tri x\n");
        printf("6. Xoa gia tri x\n");
        printf("0. Thoat\n");

        int lua_chon;
        scanf("%d", &lua_chon);
        if (lua_chon == 1)
        {
            printf("In cay the thu tu NLR: \n");
            Print_NLR(my_tree);
        }

        if (lua_chon == 2)
        {
            printf("In cay the thu tu LNR: ");
            Print_LNR(my_tree);
        }

        if (lua_chon == 3)
        {
            printf("In cay the thu tu LRN: ");
            Print_LRN(my_tree);
        }
        if (lua_chon == 4)
        {
            printf("\nNhap gia tri x can them: ");
            scanf("%d", &x);
            InsertNode(my_tree, x);
        }
        if (lua_chon == 5)
        {
            printf("\nNhap x can tim: ");
            scanf("%d", &x);
            TNODE *gia_tri = SearchNode(my_tree, x);
            if (gia_tri == NULL)
                printf("Khong tim thay gia tri x");
            else
                printf("Tim thay gia tri x");
        }
        if (lua_chon == 6)
        {
            printf("\nNhap x can xoa: ");
            scanf("%d", &x);
            int kt = DelNode(my_tree, x);
            if (kt == 0)
                printf("Khong tim thay gia tri can xoa!");
            else
                printf("Xoa gia tri x thanh cong");
        }
        if (lua_chon == 0)
            break;
    }
  
    return 0;
}

