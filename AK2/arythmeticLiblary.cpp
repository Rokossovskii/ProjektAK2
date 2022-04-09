#include "ArythmeticLiblary.h"

BigNum createBN(unsigned char* num, int numSize, int numPos)
{
	BigNum bigNum;
	bigNum.number = num;
	bigNum.numberSize = numSize;
	bigNum.numberPosition = numPos;
	return bigNum;
}

BigNum add(BigNum num1, BigNum num2) {
	unsigned int size = num1.numberSize;
	for (unsigned int i = 0; i < size; i++) {
		num1.number[i] = num1.number[i] + num2.number[i];
	}
	return num1;
}

BigNum sub(BigNum num1, BigNum num2) {
	unsigned int size = num1.numberSize;
	for (unsigned int i = 0; i < size; i++) {
		num1.number[i] = num1.number[i] - num2.number[i];
	}
	return num1;
}

BigNum mul(BigNum num1, BigNum num2) {
	return num1;
}

BigNum div(BigNum num1, BigNum num2) {
	return num1;
}