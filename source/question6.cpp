#include <iostream>

/* 根据二叉树的前序和中序遍历序列重建二叉树，两个遍历序列中不包含重复的数字*/

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* rebuildBinaryTree(int* preorder, int* inorder, int length);

BinaryTreeNode* construct(int* preorder, int* inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return rebuildBinaryTree(preorder, inorder, length);
}

BinaryTreeNode* rebuildBinaryTree(int* preorder, int* inorder, int length){

	int root_value = preorder[0];
	int left_length = 0, right_length = 0;
	bool root_flag = false;
	for (int i = 0; i < length; ++i){
		if (inorder[i] == root_value){
			root_flag = true;
			continue;
		}
		if (root_flag) right_length++;
		else left_length++;
	}

	BinaryTreeNode* root = new BinaryTreeNode;
	root->m_nValue = root_value;

	if (left_length == 0)
		root->m_pLeft = NULL;
	else
		root->m_pLeft = rebuildBinaryTree(preorder + 1, inorder, left_length);

	if (right_length == 0)
		root->m_pRight = NULL;
	else
		root->m_pRight = rebuildBinaryTree(preorder + left_length + 1, inorder + left_length + 1, right_length);
	
	return root;

}

void preOrderTree(BinaryTreeNode* root){
	std::cout << root->m_nValue << " ";
	if (root->m_pLeft != NULL)
		preOrderTree(root->m_pLeft);
	if (root->m_pRight != NULL)
		preOrderTree(root->m_pRight);
}

int main(){

	int* preorder = new int[8]{1, 2, 4, 7, 3, 5, 6, 8};
	int* inorder  = new int[8]{4, 7, 2, 1, 5, 3, 8, 6};

	BinaryTreeNode* tree = construct(preorder, inorder, 8);

	preOrderTree(tree);

	system("pause");

	return 0;
} 