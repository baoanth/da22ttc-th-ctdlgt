#include <stdio.h>
#include <conio.h>

typedef struct TNode
{
    int Key;
    TNode *pLeft, *pRight;
}TNode;

TNode* createNewNode(int data)
{
    TNode* node = new TNode;
    node->Key = data;

    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

TNode* insert(TNode *Root,int data)
{
    if(Root==NULL)
    {
        printf("Add %d as root ", data);
        TNode* node = createNewNode(data);

        return node;
    }
    else
    {
        if(data < Root->Key)
        {
            printf("\nAdd %d as left child of %d\n",data,Root->Key);
            Root->pLeft = insert(Root->pLeft,data);
        }
        else
        {
            printf("\nAdd %d as right child of %d\n",data,Root->Key);
            Root->pRight = insert(Root->pRight,data);
        }
    }
    return Root;
}

void NLR(TNode* Root)
{
   if (Root != NULL)
   {
    printf(" %d ", Root->Key);
    NLR (Root->pLeft);
    NLR (Root->pRight);
   } 
}

int countNode(TNode *Root)
{
    int count = 0;
    if (Root !=NULL)
    {
        count ++;

        count+= countNode(Root->pLeft);
        count+= countNode(Root->pRight);
    }
    return count;
}

int countLeafNode(TNode *Root)
{
    int count = 0;
    if(Root !=NULL)
    {
        if ((Root->pLeft==NULL)&&(Root->pRight==NULL))
        count++;
        
        count+= countNode(Root->pLeft);
        count+= countNode(Root->pRight);
    }
}

int getTreeHeight(TNode *Root)
{
    if (Root == NULL)
    return 0;

    int maxLeft = getTreeHeight(Root->pLeft);

    int maxRight = getTreeHeight(Root->pRight);

    if (maxLeft > maxRight)
        return maxLeft+1;
    else
        return maxRight+1;
}

TNode* delNode(TNode* Root, int Key)
{
    if(Root == NULL)
    {
    	int xoaNode= 12;
    	printf ("\n khong tim thay khoa x = %d \n",xoaNode);
    	return Root;
	}
    if (Key < Root->Key)
    Root->pLeft = delNode(Root->pLeft, Key);
else if (Key > Root->Key)
    Root->pRight = delNode(Root->pRight, Key);
else
{
    if (Root->pLeft == NULL)
    {
        TNode* temp = Root->pRight;
        delete Root;
        return temp;
    }
    else if (Root->pRight == NULL)
    {
        TNode* temp = Root->pLeft;
        delete Root;
        return temp;
    }

    TNode* minRight = Root->pRight;
    while (minRight->pLeft != NULL)
        minRight = minRight->pLeft;

    Root->Key = minRight->Key;

    Root->pRight = delNode(Root->pRight, minRight->Key);
}
     return Root;
}

int main()
{
    TNode* myTree = NULL;

    myTree = insert(myTree, 10);
    myTree = insert(myTree, 7);
    myTree = insert(myTree, 13);
    myTree = insert(myTree, 8);
    myTree = insert(myTree, 9);
    myTree = insert(myTree, 11);
    myTree = insert(myTree, 12);

    printf("\n\nDuyet cay theo thu tu thoi gian\n");
    NLR (myTree);


    printf("\n\nSo node tren cay la %d\n",countNode(myTree));
    printf("\n\nSo leafnode tren cay la %d",countLeafNode(myTree));
    printf("\n\nChieu cao cua cay la %d",getTreeHeight(myTree));
    
    int xoaNode= 12;
    printf("\n\nXoa cay so: %d\n", xoaNode);
    myTree = delNode(myTree, xoaNode);
    printf("\nDuyet cay sau khi xoa node\n");
    NLR(myTree);

    
    return 0;
}

