#include <iostream>

/* 数组中的逆序对*/

int inversePair(int* numbers, int length){
	int num = 0;

	for (int i = 0; i < length; ++i){
		for (int j = i; j < length; ++j){
			if (numbers[i] > numbers[j])
				num++;
		}
	}

	return num;
}

int main(){
	int* numbers = new int[4]{7, 5, 6, 4};
	std::cout << inversePair(numbers, 4) << std::endl;

	system("pause");
	return 0;
}