#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
#include <string.h>



//Khai bao cay




/*In cay theo thu tu truoc*/
void Print_NLR();

/*In cay theo thu tu giua*/
void Print_LNR();

/*In cay theo thu tu sau*/
void Print_LRN();

/*Tim kiem nut co gi;a tri la x*/
int SearchNode();

/*Them nut vao cay BST*/
int InsertNode();



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

/*Xoa nut trong cay*/
int DelNode(TREE &T, int X)
{
	if(T==NULL)
	{
	 	printf("\nKhong tim thay nut co khoa X = %d", X);
		return 0;
	}
	if(T->Key > X) 
		return DelNode (T->pLeft, X);
	if(T->Key < X) 
		return DelNode (T->pRight, X);
	else 
	{ //T->Key == X
		TNODE* p = T;
		if(T->pLeft == NULL) 
			T= T->pRight;
		else
			if(T->pRight == NULL) 
				T = T->pLeft;
			else 
			{ //T có cả 2 con
				TNODE* q = T->pRight;
				SearchStandFor(p, q);
			}	
			delete p;
	}
}

void InputNode(TREE &T)
{
	int n =0;
    int i;
    int num;
    printf("Ban muon nhap bao nhieu nut?");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Nhap so thu %d: ", i);
        scanf("%d", &num);
        InsertNode(T, num);
    }
}

/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
    int selection =1;
   
	do
	{	
		printf("\n*** BINARY SEARCH TREE DEMO ***\n\n");
		
		printf("Enter your selection\n");
		printf("1. Input numbers to BST\n");
		printf("2. Print BST in First order (NLR)\n");     
		printf("3. Print BST in Middle order (LNR)\n");     
		printf("4. Print BST in Last order (LRN)\n");     
		printf("5. Delete node in BST\n");
		printf("0. EXIT\n");
		
		printf("Your selection: ");
		scanf("%d", &selection);
		
		switch (selection)
		{
		
			case 1:				
				InputNode(my_tree);
				break;
				
			case 2:
				
				break;
				
			case 3:	
				printf("\nThe BST in Middle Order (LNR)\n");			
				Print_LNR(my_tree);
				break;
				
			case 4:				
				break;
				
			case 5:				
				break;
				
			default:				
				break;
				
		
		}
		
	} while (selection);
	
	
	
	
	/*InsertNode(my_tree, 30 );
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
    DelNode(my_tree, 31);
    
    printf("\nSau khi xoa nut\n");
    Print_NLR(my_tree);
    */

}


