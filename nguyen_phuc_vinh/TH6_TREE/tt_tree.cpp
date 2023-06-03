#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TNODE
{
    int Key;
    struct TNODE *pLeft, *pRight;
}TNODE;

typedef TNODE *TREE;


//1
int count_leaves(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

//2
int count_single_child_nodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if ((root->left && !root->right) || (root->right && !root->left)) {
        return 1 + count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
    }
    return count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
}

//3
int count_two_child_nodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left && root->right) {
        return 1 + count_two_child_nodes(root->left) + count_two_child_nodes(root->right);
    }
    return count_two_child_nodes(root->left) + count_two_child_nodes(root->right);
}

//4
int count_nodes_less_than_x(Node *root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->key < x) {
        return 1 + count_nodes_less_than_x(root->left, x) + count_nodes_less_than_x(root->right, x);
    }
    return count_nodes_less_than_x(root->left, x);
}

//5
int count_nodes_greater_than_x(Node *root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->key > x) {
        return 1 + count_nodes_greater_than_x(root->left, x) + count_nodes_greater_than_x(root->right, x);
    }
    return count_nodes_greater_than_x(root->right, x);
}

//6
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

//7
int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}
