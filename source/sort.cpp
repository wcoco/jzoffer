#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertSort(vector<T> &data){
	int j = 1;
	for (; j < data.size(); ++j){
		T tmp = data[j];
		int i = j - 1;
		for (; i >= 0; --i){
			if (data[i] > tmp)
				data[i + 1] = data[i];
			else
				break;
		}
		data[i + 1] = tmp;
	}
}

template <typename T>
void print(const vector<T> &data){
	if (data.size() == 0) return;
	cout << data[0];
	for (int i = 1; i < data.size(); i++){
		cout << " " << data[i];
	}
	cout << endl;
}

int main(){

	vector<int> a{ 34, 8, 64, 51, 32, 21 };

	insertSort(a);

	print(a);

	system("pause");

	return 0;
}