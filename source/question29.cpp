#include <iostream>

/* 数组中出现次数超过一半的数字*/

int moreThanHalfNum(int* numbers, int length){
	int result = numbers[0];
	int times = 1;

	for (int i = 1; i < length; i++){
		if (times == 0){
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
			times++;
		else
			times--;
	}

	// 略去检测输入合法性

	return result;
}

int main(){

	int* numbers = new int[9]{1, 2, 3, 2, 2, 2, 5, 4, 2};
	std::cout << moreThanHalfNum(numbers, 9) << std::endl;

	system("pause");
	return 0;
}