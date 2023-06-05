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

/*//Tìm ph?n t? th? m?ng cho nút p
void searchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft) searchStandFor(p, q->pLeft);
	else
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
	}
}

//Xoa 1 nut trong cay
int delNode(TREE &T, int X)
{
	if(T==NULL) 
		return 0;
	if(T->Key > X) 
		return delNode (T->pLeft, X);
	if(T->Key < X) 
		return delNode (T->pRight, X);
	else //T->Key == X
	{ 
	TREE* p = T;
	if(T->pLeft == NULL)
		T= T->pRight;
	else
		if(T->pRight == NULL)
			T = T->pLeft;
		else { //T có c? 2 con
			TREE* q = T->pRight;
			searchStandFor(p, q);
		}
		delete p;
	}
}*/


/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    InsertNode(my_tree, 30);
    InsertNode(my_tree, 23);
    InsertNode(my_tree, 19);
    InsertNode(my_tree, 61);
    InsertNode(my_tree, 26);
    InsertNode(my_tree, 15);
    InsertNode(my_tree, 45);
    InsertNode(my_tree, 50);
    InsertNode(my_tree, 38);
    InsertNode(my_tree, 33);
    InsertNode(my_tree, 36);

	char lua_chon;
	
	printf("Vui long nhan vao so tuong ung de chon thu tu in cay , nhan 0 de thoat\n");
	printf("1.Duyet cay theo thu tu truoc:\n");
	printf("2.Duyet cay theo thu tu giua:\n");
	Print_LNR(my_tree);
	printf("3.Duyet cay theo thu tu sau:\n");
	Print_LRN(my_tree);

	 lua_chon = getch(); 
     switch (lua_chon)
        {
            case '1':
            {
                printf("-> Duyet cay theo thu tu truoc:\n");
                Print_NLR(my_tree);	
                break;
            } 
            case '2':
            {
                printf("-> Duyet cay theo thu tu giua:\n");
                Print_LNR(my_tree);
                break;
            }
             case '3':
            {
                printf("-> Duyet cay theo thu tu sau:\n");
                Print_LRN(my_tree);
                break;
            }
			case '0': return 0;
		} 
   /* int x;
    printf("\nNhap x: ");
    scanf("%d", &x);
    TNODE *gia_tri = SearchNode(my_tree, x);
    if (gia_tri == NULL)
        printf("Khong tim thay gia tri x");
    else
        printf("Tim thay gia tri x");*/
    return 0;
}
