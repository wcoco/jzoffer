#include <iostream>
#include <math.h>

/* 从1到n的整数中1出现的次数*/

int numOf1(const char* strN);

int numOf1Between1AndN(int n){
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);
	return numOf1(strN);
}

int numOf1(const char* strN){
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	size_t length = strlen(strN);

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 1)
		return 1;

	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = pow(10, length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	int numOtherDigit = first * (length - 1) * pow(10, length - 2);
	int numRecursive = numOf1(strN + 1);

	return numFirstDigit + numOtherDigit + numRecursive;
}


int main(){
	std::cout << numOf1Between1AndN(12345) << std::endl;


	system("pause");
	return 0;
}