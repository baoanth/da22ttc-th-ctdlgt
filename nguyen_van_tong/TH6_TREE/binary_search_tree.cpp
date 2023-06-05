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

int demla(tree T)
{
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right == NULL)
        return 1;

    return demla(T->left) + demla(T->right);
}
int demnutMotcon(tree T)
{
    if (T == NULL)
        return 0;
    if ((T->left != NULL && T->right == NULL) || ((T->left == NULL && T->right != NULL)))
        return 1;
    return demnutMotcon(T->left) + demnutMotcon(T->right);
}

int demnutHaicon(tree T)
{
    if (T == NULL)
        return 0;
    if (T->left != NULL && T->right != NULL)
        return 1;
    return demnutHaicon(T->left) + demnutHaicon(T->right);
}

int NodeNHK(tree T, int k)
{
    if (T == NULL || T->key >= k)
        return 0;
    else
        return 1 + NodeNHK(T->left, k) + NodeNHK(T->right, k);
}

int NodeLHK(tree T, int k)
{
    if (T == NULL)
        return 0;
    else if(k < T->key)
        return 1 + NodeLHK(T->right, k) + NodeLHK(T->left, k);
    else 
         NodeLHK(T->right,k);
}

int NodeXY(tree T, int x, int y)
{
    if (T == NULL)
        return 0;
    else if(y  < T->key || x   > T->key)
        return 1 + NodeXY(T->right, x,y) + NodeXY(T->left,x,y);
    else
    {
    	NodeXY(T->right,x,y);
    	//NodeXY(T->left ,x,y);
	}
         
}

int main()
{
    tree T = NULL;

    int lc;
    while (1)
    {
        cout << "\n-----------------MENU-----------------\n";
        cout << "\n0. Exit \n1. Them nut vao cay\n2. In theo dang NLR \n3. In theo dang LNR \n4. In theo dang LRN \n5. Xoa note trong cay \n6. Xoa toan bo cay \n7. tim kiem node \n8.Dem nut la trong cay \n9. Dem nut co 1 con \n10. Dem nut co 2 con \n11. Dem so nut nho hon K \n12. Dem so nut lon hon K \n13. Dem so nut lon hon x nho hon k";
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
        else if (lc == 6)
            removeTree(T);
        else if (lc == 7)
        {
            int x;
            cout << "nhap gia tri can tim :";
            cin >> x;
            tree tmp = searchNode(T, x);
            if (tmp)
                cout << "da tim thay";
            else
                cout << "KHONG tim thay";
        }
        else if (lc == 8)
        {
            int x = demla(T);
            cout << "co " << x << " la";
        }
        else if (lc == 9)
        {
            int tmp = demnutMotcon(T);
            cout << "co " << tmp << " nut co 1 con ";
        }
        else if (lc == 10)
        {
            int tmp = demnutHaicon(T);
            cout << "co " << tmp << " nut co 2 con ";
        }
        else if (lc == 11)
        {
            int k;
            cout << "nhap gia tri k :";
            cin >> k;

            int tmp = NodeNHK(T, k);
            cout << "co " << tmp << " nut nho hon k ";
        }
        else if (lc == 12)
        {
            int k;
            cout << "nhap gia tri k :";
            cin >> k;

            int tmp = NodeLHK(T, k);
            cout << "co " << tmp << " nut lon hon k ";
        }
        else if (lc == 13)
        {
            int x, y;
            cout << "nhap gia tri x :";
            cin >> x;
            cout << "nhap gia tri y :";
            cin >> y;
            int tmp = NodeXY(T, x, y);
            cout << "co " << tmp << " nut lon hon x nho hon k ";
        }
    }
}
