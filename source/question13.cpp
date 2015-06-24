#include <iostream>

/* ��O(1)ʱ����ɾ������ڵ�, ǰ���Ǹýڵ�һ����������*/

struct ListNode{
	int       m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToDeleteNode){
	if (!pListHead || !pToDeleteNode)
		return;
	if (pToDeleteNode->m_pNext != NULL){
		ListNode* pNode = pToDeleteNode->m_pNext;
		pToDeleteNode->m_pNext = pNode->m_pNext;
		pToDeleteNode->m_nValue = pNode->m_nValue;
		delete pNode;
		pNode = NULL;
	}
	else if(*pListHead == pToDeleteNode){
		delete pToDeleteNode;
		pToDeleteNode = NULL;
		*pListHead = NULL;
	}
	else{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToDeleteNode){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pToDeleteNode->m_pNext;
		delete pToDeleteNode;
		pToDeleteNode = NULL;
	}
}

int main(){



	return 0;
}