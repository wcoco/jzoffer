#include <iostream>

/*将字符串中的空格替换为%20*/ 

//char* replaceSpaceInString(char* str){
//	if (str == NULL) return NULL;
//	int space_num = 0, str_size = 0;
//	int index = 0;
//	char c;
//	while ((c = str[index++]) != '\0'){
//		str_size++;
//		if (c == ' ') space_num++;
//	}
//	if (str_size == 0 || space_num == 0) return str;
//	int r_str_size = str_size + 2 * space_num;
//	char* r_str = new char[r_str_size + 1];
//	int str_index = str_size - 1;
//	int r_str_index = r_str_size - 1;
//	while (str_index >= 0 && r_str_index >= 0){
//		if (str[str_index] == ' '){
//			r_str[r_str_index--] = '0';
//			r_str[r_str_index--] = '2';
//			r_str[r_str_index--] = '%';
//			str_index--;
//		}
//		else{
//			r_str[r_str_index--] = str[str_index--];
//		}
//	}
//	r_str[r_str_size] = '\0';
//	return r_str;
//}

/* 在原来基础上替换，str有足够的空间*/
void replaceSpaceInString(char* str){
	if (str == NULL) return;
	int space_num = 0, str_size = 0;
	int index = 0;
	char c;
	while ((c = str[index++]) != '\0'){
		str_size++;
		if (c == ' ') space_num++;
	}
	if (str_size == 0 || space_num == 0) return;
	int r_str_size = str_size + 2 * space_num;
	int str_index = str_size - 1;
	int r_str_index = r_str_size - 1;
	str[r_str_size] = '\0';
	while (str_index >= 0 && r_str_index >= 0 && space_num > 0){
		if (str[str_index] == ' '){
			str[r_str_index--] = '0';
			str[r_str_index--] = '2';
			str[r_str_index--] = '%';
			str_index--;
			space_num--;
		}
		else{
			str[r_str_index--] = str[str_index--];
		}
	}

}

void printString(char* str){
	if (str == NULL) return;
	int index = 0;
	while (str[index] != '\0'){
		std::cout << str[index++];
	}
	//std::cout << std::endl;
}

int main(){

	char* str = new char[100];
	char* str1 = "we   are  happy! ";
	strcpy(str, str1);

	replaceSpaceInString(str);

	printString(str);

	system("pause");

	return 0;
}