#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <conio.h>
#include <string.h>
=======

<<<<<<< HEAD
//Khai bao cay
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366



/*In cay theo thu tu truoc*/
<<<<<<< HEAD
void Print_NLR();

/*In cay theo thu tu giua*/
void Print_LNR();

/*In cay theo thu tu sau*/
void Print_LRN();

/*Tim kiem nut co gi;a tri la x*/
int SearchNode();

/*Them nut vao cay BST*/
int InsertNode();



=======
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
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366
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
<<<<<<< HEAD
    
	if (Root != NULL)
=======
    if (Root != NULL)
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366
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

<<<<<<< HEAD
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
	char input[50];

    while (1) {
        printf("Enter a number or type \"EXIT\" to quit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the trailing newline

        if (strcmp(input, "EXIT") == 0) {
            break;
        }

        // Convert the input string to a number if it's a valid number
        int number;
        if (sscanf(input, "%d", &number) == 1) 
		{
            InsertNode(T, number);        
			printf("Inserted %d into the BST \n", number);    
			
        }
		else
		{
            printf("Invalid input. Please enter a number.\n");
        }
    }	
}

=======
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366
/*Khai bao 1 cay, chen vao 10 nut, in ra 3 kieu*/
int main()
{
    TREE my_tree = NULL;
<<<<<<< HEAD
    int selection =1;
   
	do
	{	
		printf("\n*** BINARY SEARCH TREE DEMO ***\n\n");
		
		printf("Enter your selection\n");
		printf("1. Input number to BST\n");
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
=======
    InsertNode(my_tree, 30 );
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366
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
<<<<<<< HEAD
    DelNode(my_tree, 31);
    
    printf("\nSau khi xoa nut\n");
    Print_NLR(my_tree);
    */

}

=======
    printf("\n");
    Print_LNR(my_tree);

}
>>>>>>> 7c824c252a81952b5aa42d5d5323e8013f81784a
>>>>>>> 7400ce63eacd8577f395a2ca3237913e973e0366
