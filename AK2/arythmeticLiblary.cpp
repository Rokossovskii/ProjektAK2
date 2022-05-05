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
	if (num1.numberSize < num2.numberSize) {
		BigNum temp = num1;
		num1 = num2;
		num2 = temp;
	}
	int slide = (num1.numberPosition - num2.numberPosition);
	unsigned int size = num1.numberSize;
	unsigned int num2Var;
	unsigned int sum = 0;

	if (slide < 0) {
		//przesownie dodajnika

		slide = slide * (-1);
	}

	if (num2.numberSize * 8 + num1.numberPosition > num1.numberSize * 8) {

	}
	else {
		for (int i = 0; i < num1.numberSize; i++) {
			num2Var = 0;
			if ((i < num2.numberSize + slide / 8) && (i >= slide / 8)) num2Var = num2.number[i - slide / 8];

			sum = sum + num1.number[i] + (num2Var << slide % 8);

			num1.number[i] = sum;
			sum = sum >> 8;
		}
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
	return num1;
}

BigNum div(BigNum num1, BigNum num2) {
	return num1;
}