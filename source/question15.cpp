#include <iostream>

/* �����е�����k���ڵ�*/

struct ListNode{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* findKthToTail(ListNode* pListHead, unsigned int k){

	if (!pListHead || k == 0) return NULL;

	ListNode* pNode = pListHead;
	while ((k--) > 1){
		if (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		else
			return NULL;
	}

	ListNode* pResult = pListHead;
	while (pNode->m_pNext != NULL){
		pNode = pNode->m_pNext;
		pResult = pResult->m_pNext;
	}

	return pResult;
}


int main(){



	return 0;
}