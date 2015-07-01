#include <iostream>
#include <queue>

/* 从上往下打印二叉树*/

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void print(BinaryTreeNode* pRoot){
	if (pRoot == NULL) return;
	std::queue<BinaryTreeNode*> treeNode;
	treeNode.push(pRoot);
	while (!treeNode.empty()){
		BinaryTreeNode* node = treeNode.front();
		treeNode.pop();
		std::cout << node->m_nValue << " ";
		if (node->m_pLeft != NULL)
			treeNode.push(node->m_pLeft);
		if (node->m_pRight != NULL)
			treeNode.push(node->m_pRight);
	}
	std::cout << std::endl;
}

int main(){


	return 0;
}