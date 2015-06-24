#include <iostream>

/* ì³²¨ÄÇÆõÊıÁĞ*/

long long fibonacci(int n){
	if (n <= 0) return 0;
	if (n <= 2) return n;
	long long fn_1 = 1;
	long long fn = 2;
	int index = 3;
	while ((index++) <= n){
		int tmp = fn + fn_1;
		fn_1 = fn;
		fn = tmp;
	}
	return fn;
}


int main(){

	std::cout << fibonacci(10) << std::endl;

	system("pause");

	return 0;
}