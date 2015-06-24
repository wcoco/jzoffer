#include <iostream>

/* ��ӡ1������nλ��������n=3�����ӡ1��999*/

bool increment(char* number, int n){
	int carry = 0;
	int index = n;
	do{
		if (number[index] == '9'){
			carry = 1;
			number[index--] = '0';
		}
		else{
			number[index--]++;
			carry = 0;
		}
	} while (carry && index >= 0);

	if (number[0] == '1') return false;  // �����Ѿ����ӵ�����nλ��
	return true;
}

void print(char* number, int n){
	int index = 0;
	while (number[index++] == '0');

	for (index--; index <= n; index++){
		std::cout << number[index];
	}
	std::cout << std::endl;
}

void print12n(int n){
	char* number = new char[n + 1];
	for (int i = 0; i < n + 1; i++)
		number[i] = '0';

	while (increment(number, n)){
		print(number, n);
	}
}

int main(){
	
	print12n(4);

	system("pause");
	return 0;
}