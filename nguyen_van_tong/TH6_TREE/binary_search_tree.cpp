#include <bits/stdc++.h>

using namespace std;

typedef struct Tree *tree;
struct Tree
{
    int key;
    Tree *left, *right;
};

void Print_NLR(tree root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        Print_NLR(root->left);
        Print_NLR(root->right);
    }
}

void Print_LNR(tree root)
{
    if (root != NULL)
    {
        Print_LNR(root->left);
        cout << root->key << " ";
        Print_LNR(root->right);
    }
}

void Print_LRN(tree root)
{
    if (root != NULL)
    {
        Print_LRN(root->left);
        Print_LRN(root->right);
        cout << root->key << " ";
    }
}

tree searchNode(tree T, int x)
{
    if (T)
    {
        if (T->key == x)
            return T;

        if (T->key > x)
            return searchNode(T->left, x);

        if (T->key < x)
            return searchNode(T->right, x);
    }
    return NULL;
}

int insertNode(tree &T, int x)
{
    if (T)
    {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return insertNode(T->left, x);
        else
            return insertNode(T->right, x);
    }
    T = new Tree;
    if (T == NULL)
        return -1;
    T->key = x;
    T->left = T->right = NULL;
    return 1;
}

void searchStandfor(tree &p, tree &q)
{
    if (q->left)
        searchStandfor(p, q->left);
    else
    {
        p->key = q->key;
        p = q;
        q = q->right;
    }
}
int delNode(tree &T, int x)
{
    if (T == NULL)
        return 0;
    if (T->key > x)
        return delNode(T->left, x);
    if (T->key < x)
        delNode(T->right, x);
    else
    {
        tree tmp = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        else
        {
            tree q = T->right;
            searchStandfor(tmp, q);
        }
        delete (tmp);
    }
}

int main()
{
    int a[] = {12, 3, 6, 87, 32, 7, 5, 98, 45, 34, 80, 43, 90};
    tree T = NULL;

    for (int i = 0; i < 13; i++)
        insertNode(T, a[i]);

    Print_NLR(T);
    cout << endl;
    Print_LNR(T);
    cout << endl;
    Print_LRN(T);

    int x;
    cout << "\nnhap vao gia tri can xoa ";
    cin >> x;
    //    tree p = searchNode(T, x);
    //    if (p != NULL)
    //        cout << "\ntim thay ";
    //    else
    //        cout << "\nKHONG tim thay";
    int i = delNode(T, x);
    if (i != 0)
    {
        cout << "da xoa ";
        cout << "\ncay sau khi xoa :";
        Print_NLR(T);
    }
    else
        cout << "khong tom thay gia tri " << x << " trong cay";
}