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

void nhap_cay(TREE &T)
{
    int n, i, x;
    printf("Vui long nhap so nut: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nNhap nut thu %d: ", i + 1);
        scanf("%d", &x);
        InsertNode(T, x);
    }
}

int dem_nut_la(TREE T)
{
    if (T == NULL)
        return 0;
    else if (T->pLeft == NULL && T->pRight == NULL)
        return 1;
    else
        return dem_nut_la(T->pLeft) + dem_nut_la(T->pRight);
}

int dem_nut_1_cay_con(TREE T)
{
    if (T == NULL || T->pLeft == NULL && T->pRight == NULL)
        return 0;
    else if (T->pLeft == NULL || T->pRight == NULL)
        return 1 + dem_nut_1_cay_con(T->pLeft) + dem_nut_1_cay_con(T->pRight);
    else
        return dem_nut_1_cay_con(T->pLeft) + dem_nut_1_cay_con(T->pRight);
}

int dem_nut_2_cay_con(TREE T)
{
    if (T == NULL || T->pLeft == NULL && T->pRight == NULL)
        return 0;
    else if (T->pLeft != NULL && T->pRight != NULL)
        return 1 + dem_nut_2_cay_con(T->pLeft) + dem_nut_2_cay_con(T->pRight);
    else
        return dem_nut_2_cay_con(T->pLeft) + dem_nut_2_cay_con(T->pRight);
}

int nut_khoa_nho_hon_x(TREE T, int x)
{
    if (T == NULL || T->Key >= x)
        return 0;
    else
        return 1 + nut_khoa_nho_hon_x(T->pLeft, x) + nut_khoa_nho_hon_x(T->pRight, x);
}

int nut_khoa_lon_hon_x(TREE T, int x)
{
    if (T == NULL || T->Key <= x)
        return 0;
    else
        return 1 + nut_khoa_lon_hon_x(T->pLeft, x) + nut_khoa_lon_hon_x(T->pRight, x);
}

int chieu_cao_cay(TREE T)
{
    if (T == NULL)
        return -1;
    else
    {
        int trai_cao = chieu_cao_cay(T->pLeft);
        int phai_cao = chieu_cao_cay(T->pRight);
        if (trai_cao > phai_cao)
            return trai_cao + 1;
        else
            return phai_cao + 1;
    }
}

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    int x;
    printf("1. Nhap cay nhi phan\n");
    printf("2. In cay the thu tu NLR\n");
    printf("3. In cay the thu tu LNR\n");
    printf("4. In cay the thu tu LRN\n");
    printf("5. Them gia tri x\n");
    printf("6. Tim gia tri x\n");
    printf("7. Xoa gia tri x\n");
    printf("8. Dem nut la\n");
    printf("9. Dem nut co 1 cay con\n");
    printf("10. Dem nut co 2 cay con\n");
    printf("11. Dem so nut khoa nho hon x\n");
    printf("12. Dem so nut khoa lon hon x\n");
    printf("13. Chieu cao cua cay\n");
    printf("0. Thoat\n");
    while (1)
    {
        int lua_chon;
        printf("\nNhap: ");
        scanf("%d", &lua_chon);
        if (lua_chon == 1)
            nhap_cay(my_tree);
        if (lua_chon == 2)
        {
            printf("In cay the thu tu NLR: ");
            Print_NLR(my_tree);
        }

        if (lua_chon == 3)
        {
            printf("In cay the thu tu LNR: ");
            Print_LNR(my_tree);
        }

        if (lua_chon == 4)
        {
            printf("In cay the thu tu LRN: ");
            Print_LRN(my_tree);
        }
        if (lua_chon == 5)
        {
            printf("\nNhap gia tri x can them: ");
            scanf("%d", &x);
            InsertNode(my_tree, x);
        }
        if (lua_chon == 6)
        {
            printf("\nNhap x can tim: ");
            scanf("%d", &x);
            TNODE *gia_tri = SearchNode(my_tree, x);
            if (gia_tri == NULL)
                printf("Khong tim thay gia tri x");
            else
                printf("Tim thay gia tri x");
        }
        if (lua_chon == 7)
        {
            printf("\nNhap x can xoa: ");
            scanf("%d", &x);
            int kt = delNode(my_tree, x);
            if (kt == 0)
                printf("Khong tim thay gia tri can xoa!");
            else
                printf("Xoa gia tri x thanh cong");
        }
        if (lua_chon == 8)
        {
            int nut_la = dem_nut_la(my_tree);
            printf("So nut la: %d", nut_la);
        }
        if (lua_chon == 9)
        {
            int nut_la = dem_nut_1_cay_con(my_tree);
            printf("So nut co 1 cay con: %d", nut_la);
        }
        if (lua_chon == 10)
        {
            int nut_la = dem_nut_2_cay_con(my_tree);
            printf("So nut co 2 cay con: %d", nut_la);
        }
        if (lua_chon == 11)
        {
            printf("Nhap x: ");
            scanf("%d", &x);
            int nut_la = nut_khoa_nho_hon_x(my_tree, x);
            printf("So nut khoa nho hon x: %d", nut_la);
        }
        if (lua_chon == 12)
        {
            printf("Nhap x: ");
            scanf("%d", &x);
            int nut_la = nut_khoa_lon_hon_x(my_tree, x);
            printf("So nut khoa lon hon x: %d", nut_la);
        }
        if (lua_chon == 13)
        {
            int nut_la = chieu_cao_cay(my_tree);
            printf("Chieu cao cua cay la: %d", nut_la);
        }
        if (lua_chon == 0)
            break;
    }
    return 0;
}

