#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một nút trong cây AVL
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Hàm tạo mới một nút với khóa là 'key'
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Khi tạo mới, độ cao là 1
    return (node);
}

// Hàm lấy chiều cao của cây AVL
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Hàm trả về tổng trên hai số nguyên
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Hàm xoay phải khi cây bị mất cân bằng
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Thực hiện xoay phải
    x->right = y;
    y->left = T2;

    // Cập nhật độ cao của nút
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Trả về nút mới sau khi xoay
    return x;
}

// Hàm xoay trái khi cây bị mất cân bằng
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Thực hiện xoay trái
    y->left = x;
    x->right = T2;

    // Cập nhật độ cao của nút
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Trả về nút mới sau khi xoay
    return y;
}

// Hàm lấy độ chênh lệch độ cao giữa hai con trái và phải của một cây AVL
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Chèn một khóa key vào trong cây AVL
struct Node* insert(struct Node* node, int key) {
    // Bước 1: Tạo mới cây bằng cấp phát động nếu cây rỗng
    if (node == NULL)
        return (newNode(key));
    
    // Bước 2: Chèn node vào cây tương ứng
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Trường hợp key đã tồn tại trong cây
        return node;

    // Bước 3: Cập nhật lại độ cao của node trên đường từ node gốc tới thêm được mới nút
    node->height = 1 + max(height(node->left), height(node->right));

    // Bước 4: Kiểm tra xem cây đã bị mất cân bằng chưa
    int balance = getBalance(node);

    // Nếu cây mất cân bằng, có các trường hợp đặc biệt để xoay
    // Trường hợp Left Left:
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Trường hợp Right Right:
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Trường hợp Left Right:
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left:
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Nếu cây vẫn cân bằng, trả về nút
    return node;
}

// Hàm in thứ tự trước để hiển thị cây AVL
void preOrder(struct Node *root) {
    if (root != NULL) {
        preOrder(root->left);
        printf(" %2d ", root->key);
        preOrder(root->right);
    }
}

// Hàm main để kiểm tra một số chức năng
int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Cay AVL duyet theo thu tu giua: ");
    preOrder(root);

    return 0;
<<<<<<< HEAD

    
=======
>>>>>>> a65ffb3d4984ea508b157343156eb146dc44309a
}
