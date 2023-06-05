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

void InputTree(TREE &T)
{

    int n;
    printf("- Nhap so nut cua cay: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n)
    {
        int number_tam;
        printf("Nhap gia tri nut %d: ", i);
        scanf("%d", &number_tam);
        InsertNode(T, number_tam);
        i++;
    }
}
int main()
{
    TREE my_tree = NULL;

    int stt = 1;

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Nhap cay.");
        printf("\n2. Duyet theo thu tu truoc.");
        printf("\n3. Duyet theo thu tu giua.");
        printf("\n4. Duyet theo thu tu sau.");
        printf("\n5. Xoa nut.");
        printf("\n0. Thoat.\n");

        printf("\n-Nhap chuc nang: ");
        scanf("%d", &stt);
        switch (stt)
        {
        case 1:
            InputTree(my_tree);
            break;
        case 2:
            printf("Duyet theo thu tu truoc:");
            Print_NLR(my_tree);
            break;
        case 3:
            printf("Duyet theo thu tu giua:");
            Print_LNR(my_tree);
            break;
        case 4:
            printf("Duyet theo thu tu sau:");
            Print_LRN(my_tree);
            break;
        case 5:
            int d;
            printf("- Nhap gia tri can xoa: ");
            scanf("%d", &d);
            DeleteNode(my_tree, d);
            break;
        default:
            break;
        }
    } while (stt);

    /*
        int x;
        printf("- Nhap gia tri can tim: ");
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
        }
        else
        {
            printf("--- Khong tim thay gia tri can xoa ---");
        }
    */
    return 0;
}
