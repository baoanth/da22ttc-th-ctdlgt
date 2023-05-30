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

int main()
{
    TREE Root = NULL;
    int y;

    InsertNode(Root, 30);
    InsertNode(Root, 22);
    InsertNode(Root, 12);
    InsertNode(Root, 21);
    InsertNode(Root, 26);
    InsertNode(Root, 27);
    InsertNode(Root, 45);
    InsertNode(Root, 38);
    InsertNode(Root, 33);
    InsertNode(Root, 36);
    InsertNode(Root, 50);

    printf("In theo thu tu truoc:\n");
    Print_NLR(Root);
    printf("\n");
    printf("In theo thu tu giua:\n");
    Print_LNR(Root);
    printf("\n");
    printf("In theo thu tu sau:\n");
    Print_LRN(Root);

    printf("\nNhap x can tim: ");
    scanf("%d", &y);
    TNODE* gia_tri = SearchNode(Root, y);
    if(gia_tri == NULL)
        printf("Khong co gia tri x = %d\n",y);
    else    
		printf("Tim thay x = %d \n",y);

    return 0;
}
