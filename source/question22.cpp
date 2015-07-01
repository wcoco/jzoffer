#include <iostream>
#include <stack>

/* 栈的压入，弹出序列。判断某个出栈序列是否和入栈序列对应，入栈的数字不重复。
   比如4,5,3,2,1是入栈序列1,2,3,4,5的一个出栈序列
*/

bool isPopOrder(const int* pPush, const int* pPop, int pLength){
	bool result = false;
	if (pPush != NULL && pPop != NULL && pLength > 0){
		std::stack<int> pTmp;
		int popIndex = 0;
		int pushIndex = 0;
		while (popIndex < pLength){
			while (pTmp.empty() || pTmp.top() != pPop[popIndex]){
				if (pushIndex == pLength)
					break;
				pTmp.push(pPush[pushIndex]);
				pushIndex++;
			}

			if (pTmp.top() != pPop[popIndex])
				break;

			pTmp.pop();
			popIndex++;

		}

		if (pTmp.empty() && popIndex == pLength)
			result = true;
	}
	return result;
}

int main(){

	int* pPush = new int[5]{1, 2, 3, 4, 5};
	int* pPop = new int[5]{4, 3,5,1,2};

	if (isPopOrder(pPush, pPop, 5))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	system("pause");
	return 0;
}