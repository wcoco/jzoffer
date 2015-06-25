#include <iostream>


/* 合并两个排序的链表*/

struct ListNode{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* merge(ListNode* pListHead1, ListNode* pListHead2){
	if (pListHead1 == NULL) return pListHead2;
	if (pListHead2 == NULL) return pListHead1;
	ListNode* pResult = NULL;
	if (pListHead1->m_nValue < pListHead2->m_nValue){
		pResult = pListHead1;
		pResult->m_pNext = merge(pListHead1->m_pNext, pListHead2);
	}
	else{
		pResult = pListHead2;
		pResult->m_pNext = merge(pListHead1, pListHead2->m_pNext);
	}

	return pResult;
}

ListNode* merge_loop(ListNode* pListHead1, ListNode* pListHead2){
	if (pListHead1 == NULL) return pListHead2;
	if (pListHead2 == NULL) return pListHead1;
	ListNode* pResult = NULL;
	ListNode* pNode1 = pListHead1;
	ListNode* pNode2 = pListHead2;
	ListNode* pNodeR = NULL;
	if (pNode1->m_nValue < pNode2->m_nValue){
		pResult = pNode1;
		pNodeR = pResult;
		pNode1 = pNode1->m_pNext;
	}
	else{
		pResult = pNode2;
		pNodeR = pResult;
		pNode2 = pNode2->m_pNext;
	}
	while (pNode1 && pNode2){
		if (pNode1->m_nValue < pNode2->m_nValue){
			pNodeR->m_pNext = pNode1;
			pNodeR = pNodeR->m_pNext;
			pNode1 = pNode1->m_pNext;
		}
		else
		{
			pNodeR->m_pNext = pNode2;
			pNodeR = pNodeR->m_pNext;
			pNode2 = pNode2->m_pNext;
		}
	}

	if (pNode1 == NULL && pNode2 != NULL)
		pNodeR->m_pNext = pNode2;
	else if (pNode1 != NULL && pNode2 == NULL)
		pNodeR->m_pNext = pNode1;
	else
		pNodeR->m_pNext = NULL;

	return pResult;
}

void print(ListNode* pListHead){
	if (pListHead == NULL) return;
	ListNode* pNode = pListHead;
	while (pNode != NULL){
		std::cout << pNode->m_nValue;
		pNode = pNode->m_pNext;
	}
	std::cout << std::endl;
}


int main(){

	ListNode* n7 = new ListNode{ 7, NULL };
	ListNode* n5 = new ListNode{ 5, n7 };
	ListNode* n3 = new ListNode{ 3, n5 };
	ListNode* n1 = new ListNode{ 1, n3 };

	ListNode* n8 = new ListNode{ 10, NULL };
	ListNode* n6 = new ListNode{ 9, n8 };
	ListNode* n4 = new ListNode{ 8, n6 };
	ListNode* n2 = new ListNode{ 2, n4 };

	print(n1);
	print(n2);
	//print(merge_loop(n1, n2));
	print(merge(n1, n2));
	system("pause");

	return 0;
}