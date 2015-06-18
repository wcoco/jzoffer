#include <iostream>
#include <stack>

using namespace std;

/* 反向输出链表每个节点的值*/

struct ListNode{
	int m_nKey;
	ListNode* m_pNext;
};

void inverseListNode(ListNode* pHead){
	if (pHead == NULL) return;
	stack<int> list_stack;
	ListNode* tmp = pHead;
	while (tmp != NULL){
		list_stack.push(tmp->m_nKey);
		tmp = tmp->m_pNext;
	}

	while (!list_stack.empty()){
		cout << list_stack.top() << " ";
		list_stack.pop();
	}

}


int main(){


	return 0;
}