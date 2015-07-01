#include <iostream>
#include <vector>


/* 二叉树中和为某一值的路径，该路径从头结点开始到叶节点结束*/

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void print(const std::vector<BinaryTreeNode*>& path){
	std::cout << "path: ";

	std::vector<BinaryTreeNode*>::const_iterator it;
	for (it = path.begin(); it != path.end(); ++it){
		std::cout << (*it)->m_nValue << " ";
	}

	std::cout << std::endl;
}

void helperForSumOfPath(BinaryTreeNode* root, std::vector<BinaryTreeNode*>& path, int preview, int number){
	preview += root->m_nValue;
	path.push_back(root);

	if (preview == number &&
		root->m_pLeft == NULL &&
		root->m_pRight == NULL)
		print(path);

	if (root->m_pLeft != NULL){
		helperForSumOfPath(root->m_pLeft, path, preview, number);
	}
	if (root->m_pRight != NULL){
		helperForSumOfPath(root->m_pRight, path, preview, number);
	}

	path.pop_back();  // path是按引用传递的，在返回父节点时需要弹出子节点。preview是按值传递的，不需要做调整（如果也按引用传递，那么返回时要减去子节点的值 preview -= root->m_nValue）
}

void sumOfPath(BinaryTreeNode* tree, int number){
	if (tree == NULL)
		return;

	int preview = 0;
	std::vector<BinaryTreeNode*> path;
	helperForSumOfPath(tree, path, preview, number);
}


int main(){
	BinaryTreeNode* n4 = new BinaryTreeNode{ 4, NULL, NULL };
	BinaryTreeNode* n7 = new BinaryTreeNode{ 7, NULL, NULL };
	BinaryTreeNode* n5 = new BinaryTreeNode{ 5, n4, n7 };
	BinaryTreeNode* n12 = new BinaryTreeNode{ 12, NULL, NULL };
	BinaryTreeNode* n10 = new BinaryTreeNode{ 10, n5, n12 };

	sumOfPath(n10, 22);

	system("pause");
	return 0;
}