#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
	int key;
	TNode *pLeft, *pRight;
}TNode;

TNode *createNewNode(int x)
{
	TNode * node = new TNode;
	node->key = x;
	
	node->pLeft = NULL;
	node->pRight = NULL;
}



int insertNode(TNode &t, int x)
{
	if(&t)
	{
		if(t->key == x)
			return 0; //d� c�
		if(t->key > x)
		{
			printf("Them %d ben trai %d\n",data, Root->key);
			return insertNode(t->pLeft,x);
		}
		else
		{
			printf("Them %d ben phai %d\n",data, Root->key);
			return insertNode(t->pRight,x);
		}
		printf("Re nhanh\n");
	}

	printf("t == NULL\n");
	t = new TNode;
	if(t == NULL)
	{
		printf("Thieu bo nho\n");
		return -1; 
	}
	t->key = x;
	printf("Them %d vao nut goc\n",x);
	t->pLeft =t->pRight = NULL;
	return 1; //th�m v�o th�nh c�ng

}

void NLR(TNode* Root)// in truoc
{
	if (Root != NULL)
	{
		printf ("%d\n", Root->key);
		NLR(Root->pLeft);
		NLR(Root->pRight);
	}
}

void LNR(Tnode* Root)//in giua
{
	if (Root != NULL)
	{
		LNR(Root->Left);
		printf ("%d\n", root->key);
		LNR(Root->Right);
	}
}

void LRN(TNode* Root)//in sau
{
	if (Root != NULL)
		{
			LRN(Root->Left);
			LRN(Root->Right);
			printf ("%d\n", root->key);
		}
}

int countNode(TNode * Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		count ++;
		count += countNode (Root ->pLeft);
		count += countNode (Root ->pRight);
	}
	return 0;
}
int countLeafNode(TNode * Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		if ((Root->pLeft == NULL)&&(Root->pRight==NULL))
			count ++;
		count += countNode (Root ->pLeft);
		count += countNode (Root ->pRight);
	}
	return 0;
}

int getTreeHeight(TNode *Root)
{
	if (Root== NULL)
		return 0;
	int maxLeft = getTreeHeight(Root->pLeft);
	int maxRight = getTreeHeight(Root->pRight);
	
	if (maxLeft>maxRight)
		return maxLeft+1;
	else
		return maxRight+1;
}

int main()
{
	TNode * myTree =NULL;
	
	myTree = insertNode(myTree,10);
	myTree = insertNode(myTree,7);
	myTree = insertNode(myTree,8);
	myTree = insertNode(myTree,9);
	myTree = insertNode(myTree,15);
	myTree = insertNode(myTree,12);
	myTree = insertNode(myTree,4);
	myTree = insertNode(myTree,16);
	printf("Duyet cay theo thu tu truoc:\n");
	NLR(myTree);	
	printf("Duyet cay theo thu tu giua:\n");
	LNR(myTree);
	printf("Duyet cay theo thu tu sau:\n");
	LRN(myTree);
	
}
