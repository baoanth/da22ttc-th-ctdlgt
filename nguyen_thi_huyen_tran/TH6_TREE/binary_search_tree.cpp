#include <stdio.h>
#include <stdio.h>
#include <string.h>


typedef struct  TNode
{
    int  Key;
    struct tagTNode* pLeft;
    struct tagTNode* pRight;
}TNode;


TNode* createNewNode(int data)
{
    TNode* node = new TNode*
    node -> pLeft = NULL;
    node -> pRight =NULL;

    return node;

}


TNode* insert (TNode *Root, int data)
{
    if(Root==NULL) 
    {
       printf("Add %d as root \n", data);
       TNode* node = createNewNode (data)
            return node;  
    }     
    else
    {
        if (data < root-> key)
        {
            printf("Add %d as left child of %d \n", data, Root-> key);
            Root -> pLeft = insert(Root -> pLeft, data);
        }
        else
        {
            printf("Add %d as right child of %d \n", data, Root-> key);
            Root -> pRight= insert(Root -> pRight, data);
        }
    }
     return Root;

     
 void NLR(TNode* Root)    
 {
    
 }
 
 int getTreeHeight (TNode *Root)
 {
    if (Root == NULL)
        return 0;

    int maxLeft = getTreeHeight(Root->pLeft);

    int maxRight = getTreeHeight(Root->pRight);   

    if (maxLeft> maxRight) 
       return maxLeft +1;
    else
       return maxRight +1;

 }

 int main()
 {
    TNode* myTree = NULL;

    myTree = insert (myTree, 10);
    myTree = insert (myTree, 7);
    myTree = insert (myTree, 12);
    myTree = insert (myTree, 8);
    myTree = insert (myTree, 9);
    myTree = insert (myTree, 11);
    myTree = insert (myTree, 14);

    printf ("Duyet cay theo thu tu truoc\n")
    NLR(myTree);
    printf("\n\nSo node tren cay la %d\n", countNode(myTree));
    printf("\n\nSo leafnode tren cay la %d", countleafNode(myTree));
    printf("\n\nChieu cao cua cay la %d", getTreeHeight(myTree));

    return 0;
 }