#include <iostream>


/* ¸´ÔÓÁ´±íµÄ¸´ÖÆ*/

struct ComplexListNode{
	int              m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

ComplexListNode* clone(ComplexListNode* pHead){
	ComplexListNode* node = pHead;

	while (node != NULL){
		ComplexListNode* tmp = new ComplexListNode;
		tmp->m_nValue = node->m_nValue;
		tmp->m_pNext = node->m_pNext;
		tmp->m_pSibling = NULL;

		node->m_pNext = tmp;
		node = tmp->m_pNext;
	}

	node = pHead;
	while (node != NULL){
		ComplexListNode* nodeCloned = node->m_pNext;
		if (node->m_pSibling != NULL)
			nodeCloned->m_pSibling = node->m_pSibling->m_pNext;

		node = nodeCloned->m_pNext;
	}

	node = pHead;
	ComplexListNode* clonedNode = pHead->m_pNext;
	ComplexListNode* clonedHead = clonedNode;
	while (clonedNode->m_pNext != NULL){
		node->m_pNext = clonedNode->m_pNext;
		node = node->m_pNext;
		clonedNode->m_pNext = node->m_pNext;
		clonedNode = clonedNode->m_pNext;
	}

	node->m_pNext = NULL;

	return clonedHead;
}



int main(){


	return 0;
}