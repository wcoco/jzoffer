#include <iostream>

/*�ڶ�ά�����в����Ƿ����ĳ���������ö�ά�����У�ÿһ�д������ǵ��������
* ÿһ�д��ϵ���Ҳ�ǵ�������ġ�����
* 1 2 8  9
* 2 4 9  12
* 4 7 10 13
* 6 8 11 15
*/


bool findIn2DArray(int* matrix, int rows, int columns, int number){
	if (matrix == NULL || rows <= 0 || columns <= 0) return false;
	int row_index = rows - 1;
	int column_index = 0;
	while (row_index >= 0 && column_index < columns){
		int comp = matrix[row_index * columns + column_index];
		if (comp == number) return true;
		else if (comp > number) row_index--;
		else column_index++;
	}
	return false;
}

int main(){

	int* matrix = new int[16]{ 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };

	std::cout << (findIn2DArray(matrix, 4, 4, 7) ? "" : "��") << "����" << 7 << std::endl;

	std::cout << (findIn2DArray(matrix, 4, 4, 5) ? "" : "��") << "����" << 5 << std::endl;

	system("pause");

	return 0;
}