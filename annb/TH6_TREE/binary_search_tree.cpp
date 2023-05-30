#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
//Khai bao cay



/*In cay theo thu tu truoc*/
void Print_NLR()

/*In cay theo thu tu giua*/
void Print_LNR()

/*In cay theo thu tu sau*/
void Print_LRN()

/*Tim kiem nut co gia tri la x*/
int SearchNode()

/*Them nut vao cay BST*/
int InsertNode()


/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
=======
// Khai bao cay
typedef struct TNODE
{
    int Key; // Data là kiểu dữ liệu ứng với thông tin lưu tại nút
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

/*In cay theo thu tu truoc*/
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
       // Xu ly ROOT
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
	   // Xu ly ROOT
        printf("%3d", Root->Key);		
		
        Print_LNR(Root->pRight);
    }
}

/*In cay theo thu tu sau*/
void Print_LRN();

/*Tim kiem nut co gia tri la x*/
TNODE *SearchNode(TREE Root, int x)
{
    TNODE *p = Root;
    while (p != NULL)
    {
        if (x == p->Key)
            return p;
        else if (x < p->Key)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return NULL;
}

/*Them nut vao cay BST*/
int InsertNode(TREE &T, int x)
{
    if (T)
    {
        if (T->Key == x)
            return 0; // đã có X
        if (T->Key > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
   
    T = new TNODE;
    if (T == NULL)
        return -1; // thiếu bộ nhớ
    
    // Da tim dung vi tri
    T->Key = x;  
    T->pLeft = T->pRight = NULL;
    return 1; // thêm vào thành công
}

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    InsertNode(my_tree, 30 );
    InsertNode(my_tree, 22);
    InsertNode(my_tree, 26);
    InsertNode(my_tree, 45);
    InsertNode(my_tree, 50);
    InsertNode(my_tree, 38);
    InsertNode(my_tree, 33);
    InsertNode(my_tree, 12);
    InsertNode(my_tree, 21);
    InsertNode(my_tree, 27);
    InsertNode(my_tree, 36);

    Print_NLR(my_tree);
    printf("\n");
    Print_LNR(my_tree);

}
>>>>>>> 7c824c252a81952b5aa42d5d5323e8013f81784a
