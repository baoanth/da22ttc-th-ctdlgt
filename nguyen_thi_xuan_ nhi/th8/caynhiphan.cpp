#include <stdio.h>
#include <string.h>

tnode * searchnode(tress t,int x)
{
    if(t)
    if(t->key)
}
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->p_left = nullptr;
	p->p_right = nullptr;
	p->height = 1;
	return p;
}

int findMaxHeight(NODE* pLeft, NODE* pRight) {
	if (pLeft == nullptr) return pRight->height;
	else if (pRight == nullptr) return pLeft->height;
	return pLeft->height > pRight->height ? pLeft->height : pRight->height;
}


int isBalanceTree(NODE* pRoot) {
	int left = 0, right = 0;
	if (pRoot->pLeft == nullptr && pRoot->pRight != nullptr) left = pRoot->pRight->height;// ton tai 1 node con ben trai
	else if (pRoot->pRight == nullptr && pRoot->pLeft != nullptr) right = pRoot->pLeft->height;// ton tai 1 node con ben phai
	else if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr) {// 2 node con deu la nullptr
		left = pRoot->pLeft->height;
		right = pRoot->pRight->height;
	}

	int index = right - left;
	if (index > 1) return 1;
	else if (index < -1) return -1;
	else return 0;
}

//Xoay trai
void rotateLeftLeft(NODE* &pRoot) {
	NODE* temp = pRoot->p_left; // giu P1
	pRoot->p_left = pRoot->p_left->p_right; // bán con
	temp->p_right = pRoot; // Xoay
	pRoot = temp;// P1 lên làm cha

	//Cap nhat height. Cần xác định là những node lá sẽ không thay đổi height nên ta chỉ cập nhật các node không phải lá 
	NODE* pNow = pRoot->p_right;
	pNow->height = findMaxHeight(pNow->p_left, pNow->p_right) + 1;
	pRoot->height = findMaxHeight(pRoot->p_left, pRoot->p_right) + 1;
}

void rotateLeftRight(NODE*& pRoot) {
	NODE* pCur = pRoot->p_left; // pCur giữ vị trí P1 để thực hiện quay trái trước, pCur lúc này đóng vai trò là pRoot của cây con nhỏ  pRoot->left
	pRoot->p_left = pCur->p_right;
	pCur->p_right = nullptr;
	pRoot->p_left->p_left = pCur;

	//Cập nhật height cho cây sau khi xoay .
	NODE* pNow = pRoot->p_left;
	NODE* pNow1 = pNow->p_left;
	pNow1->height = findMaxHeight(pNow1->p_left, pNow1->p_right) + 1;
	pNow->height = findMaxHeight(pNow->p_left, pNow->p_right) + 1;


	//Thực h

	rotateLeftLeft(pRoot);
}


bool BalanceTree(NODE* &pRoot) {
	if (pRoot == nullptr) {
		return 0;
	}
	BalanceTree(pRoot->p_left);
	BalanceTree(pRoot->p_right);
	if (isBalanceTree(pRoot) == -1) { // lech trai
		NODE* p1 = pRoot->p_left;
		int index = p1->p_right->height - p1->p_left->height;
		if (index <= 0) {
			rotateLeftLeft(pRoot);
		}
		else {
			rotateLeftRight(pRoot);
		}
	}
	else if ( isBalanceTree(pRoot) == 1 ) {  // lech phai
		NODE* p1 = pRoot->p_right;
		int index = p1->p_right->height - p1->p_left->height;
		if (index >= 0) {
			rotateRightRight(pRoot);
		}
		else {
			rotateRightLeft(pRoot);
		}
	}
}