#include<stdio.h>
#include<stdlib.h>

// Khai b�o c?u tr�c c?a m?t n�t trong c�y AVL
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}Node;

// H�m t?o m?t n�t m?i c� gi� tr? key
struct Node* NewNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// H�m t�nh chi?u cao c?a c�y
int Height(struct Node* node)
{
    if(node == NULL) return 0;
    else return node->height;
}

// H�m t�nh ch�nh l?ch chi?u cao gi?a 2 b�n
int Balance(struct Node* L, struct Node* R)
{
    return Height(L) - Height(R);
}

// H�m xoay tr�i
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

// H�m xoay ph?i
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

// H�m xoay tr�i-ph?i
struct Node* Rotate_LeftRight(struct Node* root)
{
    root->left = Rotate_Left(root->left);
    return Rotate_Right(root);
}

// H�m xoay ph?i-tr�i
struct Node* Rotate_RightLeft(struct Node* root)
{
    root->right = Rotate_Right(root->right);
    return Rotate_Left(root);
}

// H�m ch�n m?t n�t v?i gi� tr? key v�o c�y AVL
struct Node* Insert(struct Node* root, int key)
{
    if(root == NULL) return NewNode(key);

    if(key > root->key) root->right = Insert(root->right, key);
    else root->left = Insert(root->left, key);

    root->height = 1 + (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right));

    // X�c d?nh tr?ng th�i v� c�n b?ng c�y
    int balance = Balance(root->left, root->right);

    if(balance > 1 && key < root->left->key) return Rotate_Right(root);
    if(balance < -1 && key > root->right->key) return Rotate_Left(root);
    if(balance > 1 && key > root->left->key) return Rotate_LeftRight(root);
    if(balance < -1 && key < root->right->key) return Rotate_RightLeft(root);

    return root;
}

// H�m t�m ki?m m?t n�t v?i gi� tr? key trong c�y AVL
struct Node* Search(struct Node* root, int key)
{
    if(root == NULL || root->key == key) return root;

    if(key < root->key) 
		return Search(root->left, key);
    else 
		return Search(root->right, key);
}

// H�m in ra to�n b? c�y AVL theo th? t? gi� tr? tang d?n
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

