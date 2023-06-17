#include <stdio.h>
#include <stdlib.h>

// Khai bao cay
typedef struct tagAVLNode
{
  char balFactor; //Ch? s? cân b?ng
  int key;
  struct tagAVLNode * pLeft;
  struct tagAVLNode * pRight;
}
AVLNode;
typedef AVLNode * AVLTree;

int InsertNode(AVLNode &T, int X)
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

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    int x;
   
    
    nhap_cay(my_tree);
    return 0;
}
