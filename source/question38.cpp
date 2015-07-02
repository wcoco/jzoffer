#include <iostream>


int getFirstK(int* data, int length, int k, int start, int end){
	if (start > end)
		return -1;

	int midIndex = (start + end) / 2;

	if (data[midIndex] > k)
		return getFirstK(data, length, k, start, midIndex - 1);
	else if (data[midIndex] < k)
		return getFirstK(data, length, k, midIndex + 1, end);
	else{
		if ((midIndex > 0 && data[midIndex - 1] != k) || midIndex == 0)
			return midIndex;
		else
			return getFirstK(data, length, k, start, midIndex - 1);
	}
}

int getLastK(int* data, int length, int k, int start, int end){
	if (start > end)
		return -1;

	int midIndex = (start + end) / 2;

	if (data[midIndex] > k)
		return getLastK(data, length, k, start, midIndex - 1);
	else if (data[midIndex] < k)
		return getLastK(data, length, k, midIndex + 1, end);
	else{
		if ((midIndex < length - 1 && data[midIndex + 1] != k) || midIndex == length - 1)
			return midIndex;
		else
			return getLastK(data, length, k, midIndex + 1, end);
	}
}

int getNumOfK(int* data, int length, int k){
	int num = 0;
	int first = getFirstK(data, length, k, 0, length - 1);
	int last = getLastK(data, length, k, 0, length - 1);
	if (first > -1 && last > -1)
		num = last - first + 1;

	return num;
}


int main(){
	int* data = new int[9]{1, 2, 3, 3, 3, 3, 3, 4, 5};
	std::cout << getNumOfK(data, 9, 3) << std::endl;

	system("pause");
	return 0;
}