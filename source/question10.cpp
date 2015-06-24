#include <iostream>

/* 整数二进制中1的数目*/

int numof1(int number){
	int count = 0;
	int base = 1;
	while (base){
		if (number & base)
			count++;
		base = base << 1;
	}

	return count;
}

int numof2(int number){
	int count = 0;
	while (number){
		number = number & (number - 1);
		count++;
	}
	return count;
}


int main(){
	int a = -1;

	std::cout << numof1(a) << " " << numof2(a) << std::endl;

	system("pause");

	return 0;
}