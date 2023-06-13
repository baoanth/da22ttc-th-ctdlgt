#0include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int key;
	struct Node *pLeft, *pRight;
	
}Node;

typedef Node*TREE;

void Node_Left_Right(TREE Root)
{
	if(Root != NULL)
	{
		printf("%4d", Root->key);
		Node_Left_Right(Root->pLeft);
		Node_Left_Right(Root->pRight);
	}
}

void Left_Node_Right(TREE Root)
{
	if(Root != NULL)
	{
		Left_Node_Right(Root->pLeft);
		printf("%4d", Root->key);
		Left_Node_Right(Root->pRight);
	}
}

void Left_Right_Node(TREE Root)
{
	if(Root!=NULL)
	{
		Left_Right_Node(Root->pLeft);
		Left_Right_Node(Root->pRight);
		printf("%4d",Root->key);
	}
}

Node* SearchNode(TREE Root, int x)
{
	Node *p = Root;
    while (p != NULL)
    {
        if (x == p->key)
            return p;
        else if (x < p->key)
            p = p->pLeft;
        else
            p = p->pRight;

    }	
	return NULL;
}

int InsertNode(TREE &t, int x)
{
	if(t)
	{
		if(t->key == x)
			return 0;
		if(t->key > x)
			return InsertNode(t->pLeft,x);
		else
			return InsertNode(t->pRight,x);                                      		
	}
	
	t = new Node;
	if(t == NULL)
		return -1;
		
	t->key = x;
	t->pLeft = t->pRight = NULL;
	return 1;	
}

void SearchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft)
		SearchStandFor(p, q->pLeft);
	else 
	{
		p->key = q->key;
		p = q;
		q = q->pRight;
	}	
}

int DeleteNode( TREE &t, int x)
{
	if( t==NULL)
		return 0;
	if( t->key > x)
		return DeleteNode( t->pLeft, x);
	if( t->key < x) 
		return DeleteNode( t->pRight, x);
	else
	{
		Node* p=t;
		if( t->pLeft == NULL)
			t = t->pRight;
		else
			if(t->pRight == NULL)
				t = t->pLeft;
			else
			{
				Node* q = t->pRight;
				SearchStandFor(p, q);
			}	
	delete p;
	}		
}


int main()
{
	int x,c ;
	TREE root = NULL;
	
	 InsertNode(root,1);
	 InsertNode(root,4);
	 InsertNode(root,99);
	 InsertNode(root,18);
	 InsertNode(root,19);
	 InsertNode(root,87);
	 InsertNode(root,2);
	 InsertNode(root,4);
	 InsertNode(root,5);
	 InsertNode(root,15);		
	
	 printf("Day ban dau: 1  4  99  18  19  87  2  4  5  15");
	 printf("\n");
/*	printf("\nCAC DAY SAU KHI SAP XEP \n");
	printf("\n");
	printf("DAY 1:\n");
	printf("Sap xep theo thu tu NLR ");
	Node_Left_Right(root);
	printf("\n");
	printf("DAY 2: \n");
	printf("Sap xep theo thu tu LNR ");
	Left_Node_Right(root);
	printf("\n");
	printf("DAY 3:\n");
	printf("Sap xep theo thu tu LRN ");
	Left_Right_Node(root);
	
	printf("\n");
	
	printf("\nNhap x can tim: ");
	scanf("%d",&x);
	if(SearchNode(root,x)!=NULL)
	{
		printf("Tim thay %d trong day ",x);
	}
	else
	{
		printf("Khong tim thay %d trong day ",x);
	}

	printf("\n");
	printf("\nNhap x can chen: ");
	scanf("%d",&x);
	
	printf("Chen %d vao day 1: ",x);
	InsertNode(root, x);
	Node_Left_Right(root);
	printf("\n");
	
	printf("Chen %d vao day 2: ",x);
	InsertNode(root, x);
	Left_Node_Right(root);
	printf("\n");
	
	printf("Chen %d vao day 3: ",x);
	InsertNode(root, x);
	Left_Right_Node(root);
	printf("\n\n");
	
	
	printf("Nhap node can xoa: ");
	scanf("%d",&x);
	DeleteNode(root,x);
	
	printf("Day 1 sau khi xoa ");
	Node_Left_Right(root);
	printf("\nDay 2 sau khi xoa ");
	Left_Node_Right(root);
	printf("\nDay 3 sau khi xoa ");
	Left_Right_Node(root);
	
*/	printf("\n");
	while(1)
	{
		printf("\n========================================================================\n");
		printf("\nHAY CHON MOT THAO TAC!");
		printf("\n 1.Sap xep day theo thu tu NLR\n 2.Sap xep theo thu tu LNR\n 3.Sap xep theo thu tu LRN\n 4.Chen them mot nut vao day\n 5.Xoa mot nut trong day\n 6.Tim mot nut trong day\n 7.Thoat \nNhap thao tac can thuc hien: ");
		scanf("%d",&c);
		
		if(c==7)
			break;
		else if(c==1)
		{
			printf("Sap xep theo thu tu NLR ");
			Node_Left_Right(root);
			printf("\n");
		}	
		else if(c==2)
		{
			printf("Sap xep theo thu tu LNR ");
			Left_Node_Right(root);
			printf("\n");
		}
		else if(c==3)
		{
			printf("Sap xep theo thu tu LRN ");
			Left_Right_Node(root);
			printf("\n");
		}
		else if(c==4)
		{
			printf("Nhap x can chen: ");
			scanf("%d",&x);
			
			printf("Chen %d vao day NLR: ",x);
			InsertNode(root, x);
			Node_Left_Right(root);
			printf("\n");
			
			printf("Chen %d vao day LNR: ",x);
			InsertNode(root, x);
			Left_Node_Right(root);
			printf("\n");
			
			printf("Chen %d vao day LRN: ",x);
			InsertNode(root, x);
			Left_Right_Node(root);
			printf("\n");
		}
		else if(c==5)
		{
			printf("Nhap node can xoa: ");
			scanf("%d",&x);
			DeleteNode(root,x);
	
			printf("Day NLR sau khi xoa ");
			Node_Left_Right(root);
			printf("\nDay LNR sau khi xoa ");
			Left_Node_Right(root);
			printf("\nDay LRN sau khi xoa ");
			Left_Right_Node(root);
			printf("\n");
		}
		else if(c==6)
		{
			printf("\nNhap x can tim: ");
			scanf("%d",&x);
			if(SearchNode(root,x)!=NULL)
			{
				printf("Tim thay %d trong day ",x);
			}
			else
			{
				printf("Khong tim thay %d trong day ",x);
			}
			printf("\n");
		}
		
	}
	return 0;
}














