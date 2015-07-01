#include <iostream>

/* �ַ���������*/
void permutation(char* pStr, char* pBegin){
	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else{
		for (char* pChar = pBegin; *pChar != '\0'; ++pChar){
			char tmp = *pChar;
			*pChar = *pBegin;
			*pBegin = tmp;

			permutation(pStr, pBegin + 1);

			// ������һ��λ��ǰ����ԭ��һ�ν���
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
