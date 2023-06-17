#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int height;
    int balance;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int balance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* rotate_left(struct Node* node) {
    struct Node* right_child = node->right;
    struct Node* left_of_right = right_child->left;
    right_child->left = node;
    node->right = left_of_right;
    node->height = max(height(node->left), height(node->right)) + 1;
    right_child->height = max(height(right_child->left), height(right_child->right)) + 1;
    return right_child;
}

struct Node* rotate_right(struct Node* node) {
    struct Node* left_child = node->left;
    struct Node* right_of_left = left_child->right;
    left_child->right = node;
    node->left = right_of_left;
    node->height = max(height(node->left), height(node->right)) + 1;
    left_child->height = max(height(left_child->left), height(left_child->right)) + 1;
    return left_child;
}

struct Node* new_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->height = 1;
    node->balance = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert_node(struct Node* node, int value) {
    if (node == NULL) return new_node(value);
    if (value < node->value) {
        node->left = insert_node(node->left, value);
    } else if (value > node->value) {
        node->right = insert_node(node->right, value);
    } else {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    node->balance = balance(node);
    if (node->balance > 1 && value < node->left->value) {
        return rotate_right(node);
    }
    if (node->balance < -1 && value > node->right->value) {
        return rotate_left(node);
    }
    if (node->balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (node->balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

struct Node* min_node(struct Node* node) {
    struct Node* current_node = node;
    while (current_node->left != NULL) {
        current_node = current_node->left;
    }
    return current_node;
}

struct Node* delete_node(struct Node* node, int value) {
    if (node == NULL) return node;
    if (value < node->value) {
        node->left = delete_node(node->left, value);
    } else if (value > node->value) {
        node->right = delete_node(node->right, value);
    } else {
        if (node->left == NULL || node->right == NULL) {
            struct Node* temp_node = node->left != NULL ? node->left : node->right;
            if (temp_node == NULL) {
                temp_node = node;
                node = NULL;
            } else {
                *node = *temp_node;
            }
            free(temp_node);
        } else {
            struct Node* temp_node = min_node(node->right);
            node->value = temp_node->value;
            node->right = delete_node(node->right, temp_node->value);
        }
    }
    if (node == NULL) return node;
    node->height = 1 + max(height(node->left), height(node->right));
    node->balance = balance(node);
    if (node->balance > 1 && balance(node->left) >= 0) {
        return rotate_right(node);
    }
    if (node->balance > 1 && balance(node->left) < 0) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (node->balance < -1 && balance(node->right) <= 0) {
        return rotate_left(node);
    }
    if (node->balance < -1 && balance(node->right) > 0) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

void inorder_traversal(struct Node* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->value);
        inorder_traversal(node->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;
    while (1) {
        printf("\n1. Insert a value\n2. Delete a value\n3. Search a value\n4. Display AVL Tree in inorder traversal\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("Value %d has been inserted into the AVL Tree\n", value);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                printf("Value %d has been deleted from the AVL Tree\n", value);
                break;
            case 3:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                struct Node* node = root;
                while (node != NULL) {
                    if (value < node->value) {
                        node = node->left;
                    } else if (value > node->value) {
                        node = node->right;
                    } else {
                        printf("Value %d is present in the AVL Tree\n", value);
                        break;
                    }
                }
                if (node == NULL) {
                    printf("Value %d is not present in the AVL Tree\n", value);
                }
                break;
            case 4:
                printf("Inorder traversal of the AVL Tree: ");
                inorder_traversal(root);
                printf("\n");
                break;
//            case 5:
//                printf("Quitting program...");
//                exit(0);
//            default:
//                printf("Invalid choice\n");
//                break;
        }
    }
    return 0;
}
