#include "ArythmeticLiblary.h"
#include <iostream>
#include <bitset>

BigNum createBN(unsigned char* num, int numSize, int numPos)
{
	BigNum bigNum;
	bigNum.number = num;
	bigNum.numberSize = numSize;
	bigNum.numberPosition = numPos;
	return bigNum;
}

BigNum add(BigNum num1, BigNum num2) {
	if (num1.numberSize < num2.numberSize) {
		BigNum temp = num1;
		num1 = num2;
		num2 = temp;
	}
	
	

	if (num2.numberSize * 8 + num1.numberPosition > num1.numberSize * 8) {
		for (int i = num1.numberSize-1, j = num2.numberSize-1 ; i >= 0; i--,j--) {
			unsigned char temp;
			temp = num1.number[i];
			if (j >= 0) {
				num1.number[i] = num2.number[j];
				num2.number[j] = temp;
			}
			else {
				num1.number[i] = 0;
			}
		}
	}

	int slide = (num1.numberPosition - num2.numberPosition);
	unsigned int size = num1.numberSize;
	unsigned int num2Var;
	unsigned int sum = 0;

	if (slide < 0) {
		slide = slide * (-1);
		int temp = num2.number[0 + slide / 8];
		for (int i = 1; i < num2.numberSize; i++) {
			if (i + slide / 8 < num2.numberSize) {
				temp = temp + num2.number[i + slide / 8]*256;
				/*
				std::cout << temp << std::endl;
				std::cout << std::bitset<16>(temp) << std::endl;
				std::cout << std::bitset<8>(num2.number[i]) << " ";
				std::cout << std::bitset<8>(num2.number[i -1]) << std::endl << std::endl;
				*/
				temp = temp >> (slide % 8);
				num2.number[i - 1 + slide / 8] = temp;
				num2.number[i] = temp/256;
				/*
				std::cout << temp << std::endl;
				std::cout << std::bitset<16>(temp) << std::endl;
				std::cout << std::bitset<8>(num2.number[i]) << " ";
				std::cout << std::bitset<8>(num2.number[i - 1]) << std::endl << std::endl;
			*/
			}
			else {
				num2.number[i] = 0;
			}
		}
		num2.numberPosition = num1.numberPosition;
	}

	/*
	double number = 0;
	for (int i = num2.numberSize; i > 0; i--) {
		std::cout << std::bitset<8>(num2.number[i - 1]) << " ";
		number = number + (int(num2.number[i - 1]) * pow(256, i - 1));
	}
	number = number / pow(2, num2.numberPosition);
	std::cout << num2.numberPosition << std::endl << number << std::endl << std::endl;
	*/
	for (int i = 0; i < num1.numberSize; i++) {
		num2Var = 0;
		if ((i < num2.numberSize + slide / 8) && (i >= slide / 8)) num2Var = num2.number[i - slide / 8];

		sum = sum + num1.number[i] + (num2Var << slide % 8);

		num1.number[i] = sum;
		sum = sum >> 8;
	}
	
	return num1;
}

BigNum sub(BigNum num1, BigNum num2) {
	unsigned int size = num1.numberSize;
	for (int i = 0; i < size; i++) {
		num1.number[i] = num1.number[i] - num2.number[i];
	}
	return num1;
}

BigNum mul(BigNum num1, BigNum num2) {
	num1.numberPosition = num1.numberPosition + num2.numberPosition;

	return num1;
}

BigNum div(BigNum num1, BigNum num2) {
	num1.numberPosition = num1.numberPosition - num2.numberPosition;

	return num1;
}