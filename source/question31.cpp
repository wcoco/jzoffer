#include <iostream>

/* 连续字数组的最大和*/

bool isValid = true;

int greatSumOfSubArray(int* numbers, int length){
	if (numbers == NULL || length <= 0){
		isValid = false;
		return 0;
	}

	int currentSum = numbers[0];
	int greatSum = numbers[0];
	for (int i = 1; i < length; ++i){
		if (currentSum <= 0)
			currentSum = numbers[i];
		else
			currentSum += numbers[i];

		if (currentSum > greatSum)
			greatSum = currentSum;
	}

	return greatSum;
}

int main(){
	int* numbers = new int[8]{1, -2, 3, 10, -4, 7, 2, -5};
	std::cout << greatSumOfSubArray(numbers, 8) << std::endl;

	system("pause");
	return 0;
}