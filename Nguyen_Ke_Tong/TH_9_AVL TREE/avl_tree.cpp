#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút của cây AVL
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height; 
};

// Hàm tạo một nút AVL mới
struct AVLNode* createNode(int data) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Ban đầu chiều cao của nút là 1
    return newNode;
}

// Hàm tính chiều cao của nút
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Hàm tính giá trị lớn nhất của hai số nguyên
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Hàm xoay phải (right rotation)
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Trả về nút mới sau khi xoay
    return x;
}

// Hàm xoay trái (left rotation)
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Trả về nút mới sau khi xoay
    return y;
}

// Hàm tính độ cân bằng của nút
int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Hàm chèn một nút vào cây AVL
struct AVLNode* insert(struct AVLNode* node, int data) {
    // Thực hiện chèn nút như cây nhị phân bình thường
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Trường hợp nút đã tồn tại
    return node;

    // Cập nhật chiều cao của nút
    node->height = 1 + max(height(node->left), height(node->right));

    // Kiểm tra độ cân bằng của nút
    int balance = getBalance(node);

    // Kiểm tra các trường hợp vi phạm độ cân bằng và thực hiện xoay để cân bằng cây
    // Trường hợp 1: Left Left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Trường hợp 2: Right Right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Trường hợp 3: Left Right
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp 4: Right Left
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Trường hợp không vi phạm độ cân bằng, trả về nút
    return node;
}

// Hàm in-order traversal (duyệt theo thứ tự trái - gốc - phải)
void inOrderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;
    // Chèn các số nguyên vào cây AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // In cây AVL sau khi chèn
    printf("Cay AVL sau khi chen: \n");
    inOrderTraversal(root);
    // 10 20 25 30 40 50

    printf("\n");

	return 0;
}


