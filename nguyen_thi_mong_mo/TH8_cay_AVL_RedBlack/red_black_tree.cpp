#include <stdio.h>
#include <stdlib.h>

// Định nghĩa màu của nút
#define RED 0
#define BLACK 1

// Định nghĩa cấu trúc nút của cây đỏ-đen
struct RedBlackNode
{
    int data;
    int color;
    struct RedBlackNode *left;
    struct RedBlackNode *right;
    struct RedBlackNode *parent;
};

// Khởi tạo một nút mới
struct RedBlackNode *createNode(int data)
{
    struct RedBlackNode *newNode = (struct RedBlackNode *)malloc(sizeof(struct RedBlackNode));
    newNode->data = data;
    newNode->color = RED; // Mặc định màu đỏ
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Hàm kiểm tra một nút có phải là nút gốc không
int isRoot(struct RedBlackNode *node)
{
    return node->parent == NULL;
}

// Hàm kiểm tra một nút có phải là nút lá không
int isLeaf(struct RedBlackNode *node)
{
    return node == NULL;
}

// Hàm kiểm tra một nút có phải là nút con trái không
int isLeftChild(struct RedBlackNode *node)
{
    return node->parent->left == node;
}

// Hàm kiểm tra một nút có phải là nút con phải không
int isRightChild(struct RedBlackNode *node)
{
    return node->parent->right == node;
}

// Hàm thực hiện xoay sang trái
void rotateLeft(struct RedBlackNode **root, struct RedBlackNode *node)
{
    struct RedBlackNode *rightChild = node->right;
    node->right = rightChild->left;

    if (!isLeaf(rightChild->left))
        rightChild->left->parent = node;

    rightChild->parent = node->parent;

    if (isRoot(node))
        *root = rightChild;
    else if (isLeftChild(node))
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;

    rightChild->left = node;
    node->parent = rightChild;
}

// Hàm thực hiện xoay sang phải
void rotateRight(struct RedBlackNode **root, struct RedBlackNode *node)
{
    struct RedBlackNode *leftChild = node->left;
    node->left = leftChild->right;

    if (!isLeaf(leftChild->right))
        leftChild->right->parent = node;

    leftChild->parent = node->parent;

    if (isRoot(node))
        *root = leftChild;
    else if (isRightChild(node))
        node->parent->right = leftChild;
    else
        node->parent->left = leftChild;

    leftChild->right = node;
    node->parent = leftChild;
}

// Hàm kiểm tra màu của nút cha và nút con
int isParentRed(struct RedBlackNode *node)
{
    return node->parent->color == RED;
}

// Hàm cân bằng màu sắc sau khi chèn nút mới
void fixInsertion(struct RedBlackNode **root, struct RedBlackNode *node)
{
    while (isParentRed(node))
    {
        // Trường hợp 1: Nút cha và nút chú là cùng màu đỏ
        if (isLeftChild(node->parent))
        {
            struct RedBlackNode *uncle = node->parent->parent->right;
            // Trường hợp 1.1: Nút chú là màu đỏ
            if (uncle != NULL && uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            // Trường hợp 1.2: Nút chú là màu đen
            else
            {
                // Trường hợp 1.2.1: Nút đang xét là con phải
                if (isRightChild(node))
                {
                    node = node->parent;
                    rotateLeft(root, node);
                }
                // Trường hợp 1.2.2: Nút đang xét là con trái
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(root, node->parent->parent);
            }
        }
        // Tương tự với trường hợp con phải và nút chú là màu đen
        else
        {
            struct RedBlackNode *uncle = node->parent->parent->left;

            if (uncle != NULL && uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (isLeftChild(node))
                {
                    node = node->parent;
                    rotateRight(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(root, node->parent->parent);
            }
        }
    }
    (*root)->color = BLACK; // Màu gốc luôn là đen
}

// Hàm chèn một nút vào cây đỏ-đen
void insert(struct RedBlackNode **root, int data)
{
    struct RedBlackNode *newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
        (*root)->color = BLACK; // Màu gốc là đen
    }
    else
    {
        struct RedBlackNode *current = *root;
        struct RedBlackNode *parent = NULL;

        while (!isLeaf(current))
        {
            parent = current;

            if (data < current->data)
                current = current->left;
            else if (data > current->data)
                current = current->right;
            else
            {
                printf("Error: Duplicate values are not allowed!\n");
                return;
            }
        }

        newNode->parent = parent;

        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixInsertion(root, newNode);
    }
}

// Hàm in-order traversal (duyệt theo thứ tự trái - gốc - phải)
void inOrderTraversal(struct RedBlackNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Hàm main để kiểm tra chương trình
int main()
{
    struct RedBlackNode *root = NULL;
    // Chèn các số nguyên vào cây đỏ-đen
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 25);

    // In cây đỏ-đen sau khi chèn
    printf("Cay do-den sau khi chen: \n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
