#include "calculatingNumber.h"

void showNum(BigNum num) {
	//std::cout.precision(100);
	int temp = (int(num.number[num.numberSize - 1]));
	double number = 0;
	std::cout << std::bitset<8>(num.number[num.numberSize - 1]) << " ";
	for (int i = num.numberSize - 1; i > 0; i--) {
		std::cout << std::bitset<8>(num.number[i - 1]) << " ";
		number = number + (int(num.number[i - 1]) * pow(256, i - 1));
	}
	if (temp > 127) {
		temp -= 256;
	}
	number = number + temp * pow(256, num.numberSize - 1);
	number = number / pow(2, num.numberPosition);
	std::cout << num.numberPosition << std::endl << number << std::endl << std::endl;
}

double calculatingBigNumber(BigNum num)
{
	int temp = (int(num.number[num.numberSize - 1]));
	double number = 0;
	for (int i = num.numberSize - 1; i > 0; i--) {
		number = number + (int(num.number[i - 1]) * pow(256, i - 1));
	}
	if (temp > 127) {
		temp -= 256;
	}
	number = number + temp * pow(256, num.numberSize - 1);
	number = number / pow(2, num.numberPosition);
	return number;
}