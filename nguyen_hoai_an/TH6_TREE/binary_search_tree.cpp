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

    int n, i, x;
    printf("Nhap so luong tree: ");
    scanf("%d", &n);
    printf("\n");

    while(i<n)
    {
        int a[n];
        printf("Nhap gia tri nut %d : ", i+1);
        scanf("%d", &a[i]);
        InsertNode(my_tree, a[i]);
        i++;
    }

    while(1)
    {
        printf("----- MENU -----\n");
        printf("0. EXIT \n");
        printf("1. Node Left Right \n");
        printf("2. Left Node Right \n");
        printf("3. Left Right Node \n");
        printf("4. Them nut \n");
        printf("5. Tim nut \n");
        printf("6. Xoa nut \n");

        int lua_chon;
        printf("Chon so: ");
        scanf("%d", &lua_chon);

        if (lua_chon == 1)
        {
            printf(" Node Left Right: ");
            Print_NLR(my_tree);
        }

        if (lua_chon == 2)
        {
            printf("Left Node Right : ");
            Print_LNR(my_tree);
        }

        if (lua_chon == 3)
        {
            printf("Left Right Node: ");
            Print_LRN(my_tree);
        }
        if (lua_chon == 4)
        {
            printf("\nNhap x muon them: ");
            scanf("%d", &x);
            InsertNode(my_tree, x);
        }
        if (lua_chon == 5)
        {
            printf("\nNhap x muon tim: ");
            scanf("%d", &x);
            TNode *gia_tri = SearchNode(my_tree, x);
            if (gia_tri == NULL)
                printf("Khong co dau ma kim haha.");
            else
                printf("Thay roi ne haha.");
        }
        if (lua_chon == 6)
        {
            printf("\nNhap x muon xoa: ");
            scanf("%d", &x);
            int kt = DelNode(my_tree, x);
            if (kt == 0)
                printf("Khong thay gia tri can xoa!");
            else
                printf("Xoa roi nhe\n");
        }
        if (lua_chon == 0)
            break;
    }
        return 0;
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