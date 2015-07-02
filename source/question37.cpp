#include <iostream>
#include <stack>

/* 两个链表的第一个公共节点*/
struct ListNode{
	int       m_nKey;
	ListNode* m_pNext;
};

// 需要两个辅助栈
ListNode* firstCommonNode(ListNode* pHead1, ListNode* pHead2){
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;

	std::stack<ListNode*> pStack1;
	std::stack<ListNode*> pStack2;
	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;

	while (pNode1 != NULL){
		pStack1.push(pNode1);
		pNode1 = pNode1->m_pNext;
	}

	while (pNode2 != NULL){
		pStack2.push(pNode2);
		pNode2 = pNode2->m_pNext;
	}
	ListNode* lastNode = NULL;
	while (!pStack1.empty() && !pStack2.empty()){
		ListNode* tmp1 = pStack1.top();
		ListNode* tmp2 = pStack2.top();

		if (tmp1 == tmp2){
			pStack1.pop();
			pStack2.pop();
			lastNode = tmp1;
		}
		else{
			break;
		}
	}

	return lastNode;
}

size_t getLength(ListNode* pHead);

// 不需要辅助栈
ListNode* firstCommonNode_2(ListNode* pHead1, ListNode* pHead2){
	size_t length1 = getLength(pHead1);
	size_t length2 = getLength(pHead2);

	if (length1 == 0 || length2 == 0)
		return NULL;

	ListNode* pNode_long  = NULL;
	ListNode* pNode_short = NULL;
	size_t more = 0;
	if (length1 > length2){
		pNode_long  = pHead1;
		pNode_short = pHead2;
		more = length1 - length2;
	}
	else{
		pNode_long  = pHead2;
		pNode_short = pHead1;
		more = length2 - length1;
	}

	while (more--){
		pNode_long = pNode_long->m_pNext;
	}

	while (pNode_long !=NULL && 
		pNode_short != NULL && 
		pNode_long != pNode_short){
		pNode_long = pNode_long->m_pNext;
		pNode_short = pNode_short->m_pNext;
	}

	return pNode_long;
}

size_t getLength(ListNode* pHead){
	size_t length = 0;
	ListNode* pNode = pHead;
	while (pNode != NULL){
		length++;
		pNode = pNode->m_pNext;
	}
	return length;
}


int main(){
	ListNode* n7 = new ListNode{ 7, NULL };
	ListNode* n6 = new ListNode{ 6, n7 };
	ListNode* n3 = new ListNode{ 3, n6 };
	ListNode* n5 = new ListNode{ 5, n6 };
	ListNode* n2 = new ListNode{ 2, n3 };
	ListNode* n1 = new ListNode{ 1, n2 };
	ListNode* n4 = new ListNode{ 4, n5 };

	std::cout << firstCommonNode(n1, n4)->m_nKey << std::endl;
	std::cout << firstCommonNode_2(n1, n4)->m_nKey << std::endl;

	system("pause");
	return 0;
}