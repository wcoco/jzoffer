#include <iostream>


/* 二叉搜索树与双向链表，要求将一个二叉搜索树转换成排序的双向链表
*  要求不能创建新的节点，只能通过调整指针
*/

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void convertNode(BinaryTreeNode* pRoot, BinaryTreeNode** pLastNode){
	if (pRoot == NULL) return;

	BinaryTreeNode* pCurrent = pRoot;

	if (pCurrent->m_pLeft != NULL)
		convertNode(pCurrent->m_pLeft, pLastNode);

	pCurrent->m_pLeft = *pLastNode;
	if (*pLastNode != NULL)
		(*pLastNode)->m_pRight = pCurrent;

	*pLastNode = pCurrent;

	if (pCurrent->m_pRight != NULL)
		convertNode(pCurrent->m_pRight, pLastNode);

}

BinaryTreeNode* convert(BinaryTreeNode* pRoot){

	if (pRoot == NULL) return NULL;
	
	BinaryTreeNode* pLastNode = NULL;
	convertNode(pRoot, &pLastNode);

	BinaryTreeNode* pHead = pLastNode;
	while (pHead != NULL && pHead->m_pLeft != NULL){
		pHead = pHead->m_pLeft;
	}

	return pHead;
}


int main(){
	


	return 0;
}