#include <iostream>
#include <vector>


/* �������к�Ϊĳһֵ��·������·����ͷ��㿪ʼ��Ҷ�ڵ����*/

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

	path.pop_back();  // path�ǰ����ô��ݵģ��ڷ��ظ��ڵ�ʱ��Ҫ�����ӽڵ㡣preview�ǰ�ֵ���ݵģ�����Ҫ�����������Ҳ�����ô��ݣ���ô����ʱҪ��ȥ�ӽڵ��ֵ preview -= root->m_nValue��
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