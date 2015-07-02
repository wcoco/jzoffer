#include <iostream>

int Min(int n1, int n2, int n3){
	int min = n1 < n2 ? n1 : n2;
	return min < n3 ? min : n3;
}

int getUglyNumber(int index){
	if (index <= 0)
		return 0;

	int* pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;

	int nextUglyIndex = 1;
	int* p2 = pUglyNumbers;
	int* p3 = pUglyNumbers;
	int* p5 = pUglyNumbers;

	while (nextUglyIndex < index){
		int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
		pUglyNumbers[nextUglyIndex++] = min;

		while (*p2 * 2 <= min)
			p2++;
		while (*p3 * 3 <= min)
			p3++;
		while (*p5 * 5 <= min)
			p5++;
	}

	int result = pUglyNumbers[index - 1];
	delete[] pUglyNumbers;

	return result;
}


int main(){
	std::cout << getUglyNumber(10) << std::endl;

	system("pause");
	return 0;
}