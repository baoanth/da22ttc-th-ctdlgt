#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int key;
    struct node *left, *right;
    int height;
} Node;
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int height(Node *N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}
 
Node* newNode(int key) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}
 
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
 
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
 
int getBalance(Node *N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}
 
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return (newNode(key));
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }
 
    node->height = 1 + max(height(node->left), height(node->right));
 
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
 
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
 
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
void preOrder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    

    /*printf("Nhap so phan tu: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nhap gia tri cua phan tu %d: ", i + 1);
        scanf("%d", &num);
        root = insert(root, num);
    }

    printf("\nCac gia tri trong cay AVL theo thu tu truoc khi chen them phan tu: \n");
    preOrder(root);

    int new_num;
    printf("\nNhap gia tri cua phan tu can chen: ");
    scanf("%d", &new_num);

    root = insert(root, new_num);

    printf("\nCac gia tri trong cay AVL theo thu tu sau khi da chen them phan tu: \n");
    preOrder(root);
	*/
	while(1)
	{
		int n, i, num;
    	Node *root = NULL;
		int choice1, choice2;
		
		printf("====MENU====\n");
		printf("1. TREE AVL\n");
		printf("0. EXIT\n");
		
        do
        {
            printf("\nNhap lua chon: ");
            scanf("%d", &choice1);
            if(choice1!=1)printf("\n*Khong hieu, moi ban nhap lai*\n");
        }while(choice1!=1 && choice1!=0);
		system("cls");

		switch(choice1)
		{
			case 1:
				while(1)
				{
					printf("====MENU====\n");
					printf("1. CREATE TREE AVL\n");
					printf("2. INSERT\n");
					printf("0. EXIT\n");
					printf("\nNhap lua chon: ");
					scanf("%d", &choice2);
					system("cls");
				
					if(choice2==0)
					{
						break;
					}else if(choice2==1)
					{
						printf("Nhap so phan tu: ");
	    				scanf("%d", &n);
	
	    				for (i = 0; i < n; i++)
						{
	        				printf("Nhap gia tri cua phan tu %d: ", i + 1);
	        				scanf("%d", &num);
	        				root = insert(root, num);
	    				}
					}else if(choice2==2)
					{
						int new_num;
	    				printf("Nhap gia tri cua phan tu can chen: ");
	    				scanf("%d", &new_num);
	    				root = insert(root, new_num);
					}
			case 0:
				printf("EXIT");
				break;
		}
    return 0;
		}
	}
}



