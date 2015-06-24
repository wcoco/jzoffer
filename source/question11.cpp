#include <iostream>

/* ��ֵ�������η�*/

bool equal(double d1, double d2){
	if (d1 - d2 > -0.0000001 &&
		d1 - d2 < 0.0000001)
		return true;
	else
		return false;
}

double powerWithUnsignedExp(double base, unsigned int exp){
	if (exp == 0) return 1;
	if (exp == 1) return base;

	double result = powerWithUnsignedExp(base, exp >> 1);
	result *= result;
	if (exp & 0x1 == 1)
		result *= base;
	
	return result;
}

double powp(double base, int exp){
	if (equal(base, 0.0) && exp < 0) return -1; // ��ʾ���������,��ֵ�������η�һ������0
	else if (exp == 0) return 0;   // 0^0 û�����壬����Ҳ���0

	unsigned int absexp = exp > 0 ? exp : -exp;
	double result = powerWithUnsignedExp(base, absexp);
	if (exp < 0) result = 1.0 / result;
	return result;
}


int main(){

	std::cout << powp(3, 5) << std::endl;

	system("pause");
	return 0;
}