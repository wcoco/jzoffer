#include <iostream>

/* 顺时针打印矩阵，比如

 1  2  3  4  5
 6  7  8  9  10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24 25

 则打印出 1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
*/

void printMatrixInCircle(int** numbers, int columns, int rows, int start){
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i <= endX; i++){
		std::cout << numbers[start][i] << " ";
	}

	if (start < endY){
		for (int i = start + 1; i <= endY; ++i)
		{
			std::cout << numbers[i][endX] << " ";
		}
	}

	if (start < endX && start < endY){
		for (int i = endX - 1; i >= start; --i){
			std::cout << numbers[endY][i] << " ";
		}
	}

	if (start < endX && start < endY - 1){
		for (int i = endY - 1; i > start; --i){
			std::cout << numbers[i][start] << " ";
		}
	}
}

void print(int** numbers, int columns, int rows){
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > 2 * start && rows > 2 * start){
		printMatrixInCircle(numbers, columns, rows, start);
		start++;
	}

}

int main(){

	int* row1 = new int[5]{1, 2, 3, 4, 5};
	int* row2 = new int[5]{6, 7, 8, 9, 10};
	int* row3 = new int[5]{11, 12, 13, 14, 15};
	int* row4 = new int[5]{16, 17, 18, 19, 20};
	int* row5 = new int[5]{21, 22, 23, 24, 25};

	int** numbers = new int*[5]{row1, row2, row3, row4, row5};

	print(numbers, 5, 5);

	system("pause");

	return 0;
}