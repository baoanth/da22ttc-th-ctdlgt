#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Hàm tính chiều cao của một nút
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Hàm tính giá trị tối đa của hai số
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Hàm xoay sang trái
Node* rotateLeft(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;

    // Thực hiện xoay
    y->left = z;
    z->right = T2;

    // Cập nhật chiều cao
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Hàm xoay sang phải
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Hàm cân bằng cây AVL
int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Hàm chèn một nút vào cây AVL
Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else // Không chấp nhận các giá trị trùng lặp

    // Cập nhật chiều cao của nút hiện tại
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Kiểm tra cân bằng và cân bằng lại cây nếu cần
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)
        return rotateRight(root);

    if (balanceFactor < -1 && data > root->right->data)
        return rotateLeft(root);

    if (balanceFactor > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Hàm duyệt cây AVL theo thứ tự trước (preorder)
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("Cay AVL duyet theo thu tu preorder: \n");
    preorderTraversal(root);

    return 0;
}
