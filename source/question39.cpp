#include <iostream>

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


int depth(BinaryTreeNode* pRoot){
	if (pRoot == NULL)
		return 0;

	int left_depth = depth(pRoot->m_pLeft);
	int right_depth = depth(pRoot->m_pRight);

	return left_depth > right_depth ? (left_depth + 1) : (right_depth + 1);
}

bool isBalanced(BinaryTreeNode* pRoot, int* depth){
	if (pRoot == NULL){
		*depth = 0;
		return true;
	}
	int left, right;
	if (isBalanced(pRoot->m_pLeft, &left) &&
		isBalanced(pRoot->m_pRight, &right)){
		int diff = left - right;
		if (diff <= 1 || diff >= -1){
			*depth = (left > right) ? (left + 1) : (right + 1);
			return true;
		}
	}
	return false;
}


int main(){

	system("pause");
	return 0;
}