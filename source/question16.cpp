#include <iostream>

/* 反转链表并返回反转后的头结点*/

struct ListNode{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* inverse(ListNode* pListHead){
	if (pListHead == NULL) return NULL;

	ListNode* preview = NULL;
	ListNode* current = pListHead;
	ListNode* next = pListHead->m_pNext;

	while (1){
		current->m_pNext = preview;
		preview = current;
		current = next;
		if (next == NULL) break;
		next = current->m_pNext;
	}

	return preview;
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
	ListNode* n1 = new ListNode{ 1, NULL };
	ListNode* n2 = new ListNode{ 2, n1 };
	ListNode* n3 = new ListNode{ 3, n2 };
	ListNode* n4 = new ListNode{ 4, n3 };
	ListNode* n5 = new ListNode{ 5, n4 };
	ListNode* n6 = new ListNode{ 6, n5 };
	print(n6);
	
	print(inverse(n6));

	system("pause");

	return 0;
}