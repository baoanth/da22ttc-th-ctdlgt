#include <stdio.h>
#include <stdlib.h>
//CHUA XONG
typedef struct node {
    int key;
    struct node *left, *right;
} Node;

Node *create_node(int key) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

int count_leaves(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

int count_single_child_nodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if ((root->left && !root->right) || (root->right && !root->left)) {
        return 1 + count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
    }
    return count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
}

int count_two_child_nodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left && root->right) {
        return 1 + count_two_child_nodes(root->left) + count_two_child_nodes(root->right);
    }
    return count_two_child_nodes(root->left) + count_two_child_nodes(root->right);
}

int count_nodes_less_than_x(Node *root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->key < x) {
        return 1 + count_nodes_less_than_x(root->left, x) + count_nodes_less_than_x(root->right, x);
    }
    return count_nodes_less_than_x(root->left, x);
}

int count_nodes_greater_than_x(Node *root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->key > x) {
        return 1 + count_nodes_greater_than_x(root->left, x) + count_nodes_greater_than_x(root->right, x);
    }
    return count_nodes_greater_than_x(root->right, x);
}

int count_nodes_between_x_and_y(Node *root, int x, int y) {
    if (root == NULL) {
        return 0;
    }
    if (x < root->key && root->key < y) {
        return 1 + count_nodes_between_x_and_y(root->left, x, y) + count_nodes_between_x_and_y(root->right, x, y);
    }
    else if (root->key <= x) {
        return count_nodes_between_x_and_y(root->right, x, y);
    }
    else {
        return count_nodes_between_x_and_y(root->left, x, y);
    }
}

int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int main() {
    Node *root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf("Number of leaves: %d\n", count_leaves(root));
    printf("Number of nodes with exactly one child: %d\n", count_single_child_nodes(root));
    printf("Number of nodes with exactly two children: %d\n", count_two_child_nodes(root));
    printf("Number of nodes with key less than 40: %d\n", count_nodes_less_than_x(root, 40));
    printf("Number of nodes with key greater than 70: %d\n", count_nodes_greater_than_x(root, 70));
    printf("Number of nodes with key between 30 and 70: %d\n", count_nodes_between_x_and_y(root, 30, 70));
    printf("Height of tree: %d\n", height(root));
    return 0;
}

