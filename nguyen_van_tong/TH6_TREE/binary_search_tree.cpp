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

void themnode(tree &T)
{
    int n;
    cout << "nhap vao so luong phan tu trong cay ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "nhap phan tu thu " << i << " ";
        cin >> x;
        insertNode(T, x);
    }
}

void removeTree(tree &T)
{
    if (T)
    {
        removeTree(T->left);
        removeTree(T->right);
        delete (T);
    }
}
int main()
{
    tree T = NULL;

    int lc;
    while (1)
    {
        cout << "\n-----------------MENU-----------------\n";
        cout << "\n0. Exit \n1. Them nut vao cay\n2. In theo dang NLR \n3. In theo dang LNR \n4. In theo dang LRN \n5. Xoa note trong cay \n6. Xoa toan bo cay";
        cout << "\nnhap lua chon ";
        cin >> lc;
        if (lc == 0)
            return 0;
        else if (lc == 1)
            themnode(T);
        else if (lc == 2)
            Print_NLR(T);
        else if (lc == 3)
            Print_LNR(T);
        else if (lc == 4)
            Print_LRN(T);
        else if (lc == 5)
        {
            int x;
            cout << "nhap gia tri can xoa ";
            cin >> x;
            int tmp = delNode(T, x);
            if (tmp)
                cout << "da xoa xong ";
            else
                cout << "khong tim thay gia tri can xoa ";
        }
        else
            removeTree(T);
    }
}
