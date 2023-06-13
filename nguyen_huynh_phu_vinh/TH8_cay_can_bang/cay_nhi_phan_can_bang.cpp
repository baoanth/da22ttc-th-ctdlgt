#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

// định nghĩa cấu trúc Nút cho cây AVL
struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// tạo một nút mới
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// tìm chiều cao của nút
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// lấy giá trị cân bằng của nút
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// thực hiện phép xoay sang trái
struct Node* rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // thực hiện xoay
    y->left = x;
    x->right = T2;

    // cập nhập chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // trả về nút mới được xoay
    return y;
}

// thực hiện phép xoay sang phải
struct Node* rotateRight(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // thực hiện xoay
    x->right = y;
    y->left = T2;

    // cập nhập chiều cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // trả về nút mới được xoay
    return x;
}

// chèn phần tử mới vào cây AVL
struct Node* insert(struct Node* node, int data) {
    // chèn như trong cây nhị phân thông thường
    if (node == NULL)
        return(newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // trường hợp trùng lặp - bỏ qua
        return node;

    // cập nhập chiều cao của nút
    node->height = max(height(node->left), height(node->right)) + 1;

    // lấy giá trị cân bằng của nút
    int balance = getBalance(node);

    // thực hiện các phép xoay và trả về nút mới được cân bằng
    // trường hợp cây bị mất cân bằng sẽ dẫn đến 4 trường hợp xoay
    if (balance > 1 && data < node->left->data) 
        return rotateRight(node); 

    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // trả về nút được cân bằng
    return node;
}

// hiển thị cây AVL
void printTree(struct Node *node) {
    if(node != NULL)
    {
        printTree(node->left);
        printf("%d ", node->data);
        printTree(node->right);
    }
}

void printTreeVertical2(struct Node *node, int depth, int shift) {
    if (node == NULL) {
        return;
    }
    depth++;
    printTreeVertical2(node->right, depth, shift + 3);
    printf("%*s%c--%d\n", shift, "", '|', node->data);
    printf("%*s%c\n", shift, "", '|');
    printTreeVertical2(node->left, depth, shift + 3);
}

int main() {
    struct Node *root = NULL;

    // chèn các phần tử vào cây
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 60);
    root = insert(root, 43);
    root = insert(root, 90);
    root = insert(root, 35);

    // hiển thị cây AVL
    printTree(root);
    printf("\n");
    printTreeVertical2(root, 1, 50);
    return 0;
}
