#include <iostream>

/* 字符串的排列*/
void permutation(char* pStr, char* pBegin){
	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else{
		for (char* pChar = pBegin; *pChar != '\0'; ++pChar){
			char tmp = *pChar;
			*pChar = *pBegin;
			*pBegin = tmp;

			permutation(pStr, pBegin + 1);

			// 交换下一个位置前，复原上一次交换
			tmp = *pChar;
			*pChar = *pBegin;
			*pBegin = tmp;
		}
	}
}

void permutation(char* pStr){
	if (pStr == NULL)
		return;
	permutation(pStr, pStr);
}

int main(){

	char pStr[100] = "abc";
	permutation(pStr);

	system("pause");
	return 0;
}
