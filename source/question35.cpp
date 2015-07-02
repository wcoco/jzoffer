#include <iostream>

char onceChar(const char* str){
	int* hash = new int[256];
	memset(hash, 0, 256 * sizeof(int));

	const char* ch = str;
	while (*ch != '\0'){
		hash[*ch]++;
		ch++;
	}

	char result = '\0';
	ch = str;
	while (*ch != '\0'){
		if (hash[*ch] == 1){
			result = *ch;
			break;
		}
		ch++;
	}

	return result;
}


int main(){
	std::cout << onceChar("abaccdeff") << std::endl;

	system("pause");
	return 0;
}