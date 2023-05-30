#include <stdio.h>
#include <stdlib.h>

// Khai bao cay
typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
} TNODE;
typedef TNODE* TREE;

//In cay theo thu tu truoc
void Print_NLR(TREE Root)
{
    if (Root != NULL)
    {
        printf("%3d", Root->Key);
		
		Print_NLR(Root->pLeft);
        Print_NLR(Root->pRight);
    }
}

//In cay theo thu tu giua
void Print_LNR(TREE Root)
{
    if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        printf("%3d", Root->Key);		
        Print_LNR(Root->pRight);
    }
}

//In cay theo thu tu sau
void Print_LRN(TREE Root)
{
	 if (Root != NULL)
    {
        Print_LNR(Root->pLeft);
        Print_LNR(Root->pRight); 
		printf("%3d", Root->Key);	
    }
}

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

//Them nut vao cay
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

//Tim phan tu the mang cho nut p
void SearchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft)
		SearchStandFor(p, q->pLeft);
	else
	{
		p->Key = q->Key;
		p=q;
		q=q->pRight;
	}
}
void searchStandFor(TREE &p, TREE &q)
{
if(q->pLeft) searchStandFor(p, q->pLeft);
else {
p->Key = q->Key;
p = q;
q = q->pRight;
}
}

//Huy mot phan tu co khoa X
int delNode(TREE &T, int X)
{
if(T==NULL) return 0;
if(T->Key > X) return delNode (T->pLeft, X);
if(T->Key < X) return delNode (T->pRight, X);
else { //T->Key == X 
TNODE* p = T;
if(T->pLeft == NULL) T= T->pRight;
else 
if(T->pRight == NULL) T = T->pLeft;
else { //T có c? 2 con 
TNODE* q = T->pRight;
searchStandFor(p, q);
}
delete p;
}
}

//************

//Khai bao cay, chen vao 10 nut, in ra 3 kieu
int main()
{
    TREE my_tree = NULL;
    InsertNode(my_tree, 24);
    InsertNode(my_tree, 23);
    InsertNode(my_tree, 3);
    InsertNode(my_tree, 7);
    InsertNode(my_tree, 37);
    InsertNode(my_tree, 50);
    InsertNode(my_tree, 15);
    InsertNode(my_tree, 24);
    InsertNode(my_tree, 20);
    InsertNode(my_tree, 11);
    InsertNode(my_tree, 45);

	printf("In theo thu tu truoc\n");
    Print_NLR(my_tree);
    printf("\n");
    printf("In theo thu tu giua\n");
    Print_LNR(my_tree);
    printf("\n");
	printf("In theo thu tu sau\n");
    Print_LRN(my_tree);
    
//Tim phan tu X
    int X;
    printf("\nNhap Node can tim :");
    scanf("%d", &X);
    printf("\n");
    
    TNODE* Tk = SearchNode(my_tree, X);
    if(Tk == NULL) 
    	printf("Khong tim thay %d", X);
    else 
    	printf("Da tim thay %d", X);

	int Y;
	printf("\nNhap vao Node can xoa: ");
	scanf("%d", &Y);
	
	int Xoa = delNode(my_tree, Y);
	if(Xoa == NULL) 
    	printf("Khong xoa duoc %d", Y);
    else 
    	printf("Da xoa %d", Y);
//In lai sau khi xoa
	printf("\nIn theo thu tu truoc sau khi xoa\n");
    Print_NLR(my_tree);
    printf("\n");
    printf("In theo thu tu giua sau khi xoa\n");
    Print_LNR(my_tree);
    printf("\n");
	printf("In theo thu tu sau sau khi xoa\n");
    Print_LRN(my_tree);
	
    
    return 0;
   
}

