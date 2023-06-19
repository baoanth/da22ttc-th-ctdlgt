#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}Node;


struct Node* NewNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}


int Height(struct Node* node)
{
    if(node == NULL) return 0;
    else return node->height;
}


int Balance(struct Node* L, struct Node* R)
{
    return Height(L) - Height(R);
}


struct Node* Rotate_Left(struct Node* root)
{
    struct Node* T1 = root->right->left;
    struct Node* T2 = root->right;
    T2->left = root;
    root->right = T1;
    root->height = 1 + (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right));
    T2->height = 1 + (Height(T2->left) > Height(T2->right) ? Height(T2->left) : Height(T2->right));
    return T2;
}


struct Node* Rotate_Right(struct Node* root)
{
    struct Node* T1 = root->left->right;
    struct Node* T2 = root->left;
    T2->right = root;
    root->left = T1;
    root->height = 1 + (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right));
    T2->height = 1 + (Height(T2->left) > Height(T2->right) ? Height(T2->left) : Height(T2->right));
    return T2;
}


struct Node* Rotate_LeftRight(struct Node* root)
{
    root->left = Rotate_Left(root->left);
    return Rotate_Right(root);
}

struct Node* Rotate_RightLeft(struct Node* root)
{
    root->right = Rotate_Right(root->right);
    return Rotate_Left(root);
}


struct Node* Insert(struct Node* root, int key)
{
    if(root == NULL) return NewNode(key);

    if(key > root->key) root->right = Insert(root->right, key);
    else root->left = Insert(root->left, key);

    root->height = 1 + (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right));

    
    int balance = Balance(root->left, root->right);

    if(balance > 1 && key < root->left->key) return Rotate_Right(root);
    if(balance < -1 && key > root->right->key) return Rotate_Left(root);
    if(balance > 1 && key > root->left->key) return Rotate_LeftRight(root);
    if(balance < -1 && key < root->right->key) return Rotate_RightLeft(root);

    return root;
}


struct Node* Search(struct Node* root, int key)
{
    if(root == NULL || root->key == key) return root;

    if(key < root->key) 
		return Search(root->left, key);
    else 
		return Search(root->right, key);
}


void Inorder(struct Node* root)
{
    if(root == NULL) return;

    Inorder(root->left);
    printf("%d ", root->key);
    Inorder(root->right);
}

int main()
{
    struct Node* my_avl = NULL;
    int n, key;

    printf("Moi nhap so luong cho cay AVL: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
		printf("Nhap cac phan thu %d: ", i+1);
        scanf("%d", &key);
        my_avl = Insert(my_avl, key);
    }

    printf("Cay AVL sau khi chen cac phan tu la:\n");
    Inorder(my_avl);

    int k;
    printf("\nNhap gia tri can tim kiem: ");
    scanf("%d", &k);
    struct Node* search_result = Search(my_avl, k);

    if(search_result == NULL)
		printf("Phan tu %d khong co trong cay AVL!\n", k);
    else 
		printf("Phan tu %d co trong cay AVL!\n", k);

    return 0;
}

