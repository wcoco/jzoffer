#include <iostream>

/* ��������˳��ʹ����λ��ż��ǰ��*/

void adjust(int* array, int size){
	int begin = 0;
	int end = size - 1;
	while (begin < end){
		while (array[begin] & 0x1 == 1) begin++;
		while (array[end] & 0x1 == 0) end--;
		if (begin < end){
			int tmp = array[begin];
			array[begin] = array[end];
			array[end] = tmp;
		}
	}
}

int main(){

	int* array = new int[7]{1, 2, 3, 5, 7, 9, 11};

	adjust(array, 7);

	system("pause");

	return 0;
}