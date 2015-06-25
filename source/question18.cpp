#include <iostream>

/* 判断一个二叉树是否是另一颗二叉树的子结构*/
struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


bool doesFatherHasChild(BinaryTreeNode* father, BinaryTreeNode* child){

	if (child == NULL)
		return true;
	if (father == NULL)
		return false;
	if (father->m_nValue != child->m_nValue)
		return false;

	return doesFatherHasChild(father->m_pLeft, child->m_pLeft) &&
		doesFatherHasChild(father->m_pRight, child->m_pRight);
}

bool hasSubTree(BinaryTreeNode* father, BinaryTreeNode* child){
	bool result = false;
	if (father != NULL && child != NULL){
		if (father->m_nValue == child->m_nValue)
			result = doesFatherHasChild(father, child);

		if (!result)
			hasSubTree(father->m_pLeft, child);

		if (!result)
			hasSubTree(father->m_pRight, child);
	}

	return result;
}

int main(){


	return 0;
}