#include <iostream>

/* 判断某个数组是不是二叉搜索树的后续遍历序列*/

bool isPostOrder(const int* sequence, int length){
	int root = sequence[length - 1];

	int left_length = 0;
	for (; left_length < length - 1; ++left_length)
		if (sequence[left_length] > root)
			break;

	int right_length = length - left_length - 1;
	for (int i = left_length; i < length - 1; ++i)
		if (sequence[i] < root)
			return false;

	bool left = true;
	if (left_length > 0)
		left = isPostOrder(sequence, left_length);

	bool right = true;
	if (right_length > 0)
		right = isPostOrder(sequence + left_length, right_length);

	return left && right;
}


int main(){

	int* post = new int[7]{5, 7, 6, 9, 11, 10, 8};

	if (isPostOrder(post, 7))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	system("pause");
	return 0;
}