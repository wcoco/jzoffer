#include <iostream>


/* 旋转数组中的最小值，输入是排序数组的旋转数组
*  4 5 1 2 3 是 1 2 3 4 5的一个旋转数组
*/

int status = 1;

int minInRotateArray(int* numbers, int length){

	if (numbers == NULL || length <= 0){
		status = 0;
		return 0;
	}

	int begin = 0;
	int end = length - 1;
	int mid = begin;

	while (numbers[begin] >= numbers[end]){

		if (end - begin == 1){
			mid = end;
			break;
		}

		mid = (begin + end) / 2;

		if (numbers[mid] >= numbers[begin] && numbers[mid] > numbers[end]){
			begin = mid;
		}
		else if (numbers[mid] <= numbers[end] && numbers[mid] < numbers[begin]){
			end = mid;
		} 
		else{
			int min = numbers[begin++];
			while (end >= begin){
				if (numbers[begin] < min)
					min = numbers[begin];
				begin++;
			}
			return min;
		}
	}

	return numbers[mid];
}



int main(){

	int* numbers = new int[7]{3, 4, 5, 6, 7, 1, 2};

	std::cout << minInRotateArray(numbers, 7) << std::endl;

	system("pause");

	return 0;
}
