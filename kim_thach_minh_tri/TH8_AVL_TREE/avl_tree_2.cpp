#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {

        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void search_avl(Node *root, int value)

{
    struct Node *node = root;
    while (node != NULL)
    {
        if (value < node->key)
        {
            node = node->left;
        }
        else if (value > node->key)
        {
            node = node->right;
        }
        else
        {
            printf("Value %d is present in the AVL Tree\n", value);
            break;
        }
    }
    if (node == NULL)
    {
        printf("Value %d is not present in the AVL Tree\n", value);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Traversing the constructed AVL tree...\n");
    preOrder(root);

    int choice, value;
    do
    {
        printf("MENU\n");
        printf("1. Them phan tu\n");
        printf("2. Xoa phan tu\n");
        printf("3. Tim kiem phan tu\n");
        printf("4. In phan tu\n");
        printf("5. Thoat\n");

        printf("Nhap vao lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Ban da chon chuc nang them phan tu\n");
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value %d has been inserted into the AVL Tree\n", value);
            break;
        case 2:
            printf("Ban da chon chuc nang xoa phan tu\n");
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value %d has been deleted from the AVL Tree\n", value);
            break;
        case 3:
            printf("Ban da chon chuc nang tim kiem phan tu\n");
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            search_avl(root, value);
            break;
        case 4:
            printf("Ban da chon vhuc nang in phan tu\n");
            preOrder(root);
            break;
        case 5:
            printf("Ban da chon chuc nang thoat\n");
            return 0;

        default:
            printf("Lua chon khong hop le\n");
            break;
        }
        printf("\n");
    } while (choice != 5);

    printf("Cam on ban da su dung chuong trinh\n");

    return 0;
}
