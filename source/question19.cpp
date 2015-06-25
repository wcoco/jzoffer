#include <iostream>

/* ¶þ²æÊ÷µÄ¾µÏñ*/

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};



void mirror(BinaryTreeNode* pRoot){
	if (pRoot == NULL) return;
	if (pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL)
		return;
	BinaryTreeNode* pTmp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTmp;
	if (pRoot->m_pLeft != NULL)
		mirror(pRoot->m_pLeft);
	if (pRoot->m_pRight != NULL)
		mirror(pRoot->m_pRight);
}


int main(){


	return 0;
}