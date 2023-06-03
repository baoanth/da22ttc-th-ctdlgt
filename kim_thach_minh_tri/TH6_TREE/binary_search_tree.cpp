#include <stdio.h>
#include <stdlib.h>

/*Khai bao cay*/
typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE *TREE;

/*In theo thu tu truoc*/
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%3d", Root->Key);
        Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

/*In theo thu tu giua*/
void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);
        Print_LNR(Root->pRight);
    }
}

/*In theo thu tu sau*/
void Print_LRN(TREE Root)
{
    if (Root != NULL)
    {
        Print_LRN(Root->pLeft);
        Print_LRN(Root->pRight);
        printf("%3d", Root->Key);
    }
}

/*Tim kiem x trong cay*/
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

/*Them x vao cay*/
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

/*Tim phan tu the mang*/
void searchStandFor(TREE &p, TREE &q)
{
    if (q->pLeft)
        searchStandFor(p, q->pLeft);
    else
    {
        p->Key = q->Key;
        p = q;
        q = q->pRight;
    }
}

/*Xoa mot nut*/
int delNode(TREE &T, int X)
{
    if (T == NULL)
        return 0;
    if (T->Key > X)
        return delNode(T->pLeft, X);
    if (T->Key < X)
        return delNode(T->pRight, X);
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
            searchStandFor(p, q);
        }
        delete p;
    }
}

int main()
{
    TREE Root = NULL;
    int y, x, n, i;

    printf("==========Nhap cay nhi phan==========\n");
    printf("Nhap so luong phan tu : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Nhap gia tri thu %d = ", i + 1);
        scanf("%d", &x);
        InsertNode(Root, x);
    }

    printf("==========Lua chon cac thao tac==========\n");
    printf("1. In theo thu tu truoc:\n");
    printf("2. In theo thu tu giua:\n");
    printf("3. In theo thu tu sau:\n");
    printf("4. Tim gia tri x:\n");
    printf("5. Xoa gia tri x:\n");
    //    InsertNode(Root, 30);
    //    InsertNode(Root, 22);
    //    InsertNode(Root, 12);
    //    InsertNode(Root, 21);
    //    InsertNode(Root, 26);
    //    InsertNode(Root, 27);
    //    InsertNode(Root, 45);
    //    InsertNode(Root, 38);
    //    InsertNode(Root, 33);
    //    InsertNode(Root, 36);
    //    InsertNode(Root, 50);

    int lua_chon;
    while(1){
    
    printf("Nhap lua chon: ");
    scanf("%d", &lua_chon);

    if (lua_chon == 1)
    {
        printf("In theo thu tu truoc:\n");
        Print_NLR(Root);
    }
    if (lua_chon == 2)
    {
        printf("In theo thu tu giua:\n");
        Print_LNR(Root);
    }
    if (lua_chon == 3)
    {
        printf("In theo thu tu sau:\n");
        Print_LRN(Root);
    }
    if (lua_chon == 4)
    {
        printf("\nNhap y can tim: ");
        scanf("%d", &y);
        TNODE *gia_tri = SearchNode(Root, y);
        if (gia_tri == NULL)
            printf("Khong co gia tri y = %d\n", y);
        else
            printf("Tim thay y = %d \n", y);
    }
    if (lua_chon == 5)
    {
        printf("\nNhap x can xoa: ");
        scanf("%d", &x);
        int xoa = delNode(Root, x);
        if (xoa == 0)
            printf("Khong tim thay gia tri x = %d \n", x);
        else
            printf("Da xoa nut x = %d \n", x);
    }
}

    return 0;
}
