#include <iostream>
#include "ArythmeticLiblary.h"
#include "TestFunctions.h"
#include <bitset>
#include <math.h>

void showNum(BigNum num) {
	double number = 0;
	for (int i = num.numberSize; i > 0; i--) {
		std::cout << std::bitset<8>(num.number[i-1]) << " ";
		number = number + (int(num.number[i - 1])*pow(256,i-1));
	}
	number = number / pow(2, num.numberPosition);
	std::cout << num.numberPosition << std::endl << number << std::endl << std::endl;
}

void testNum() {
	//std::cout << (3 - 13)%8<< std::endl;
	unsigned char numTab[2] = { 0x4,0x0 };
	BigNum num = createBN(numTab, 2, 0);
	showNum(num);

}

void testAdd() {
	unsigned char numTab1[4] = { 0x00, 0x00,0x0,0x1 };
	unsigned char numTab2[2] = { 0x2,0x1 };
	BigNum num1 = createBN(numTab1, 4, 13);
	BigNum num2 = createBN(numTab2, 2, 3);
	showNum(num1);
	showNum(num2);
	showNum(add(num1,num2));

	unsigned char numTab3[3] = { 0x00, 0x00, 0x0 };
	unsigned char numTab4[2] = { 0x2, 0x1 };
	num1 = createBN(numTab3, 3, 3);
	num2 = createBN(numTab4, 2, 5);
	showNum(num1);
	showNum(num2);
	showNum(add(num1, num2));
}

void testSub()
{
	unsigned char numTab1[1] = { 0x00 };
	unsigned char numTab2[2] = { 0x04,0x0 };
	BigNum num1 = createBN(numTab1, 1, 0);
	BigNum num2 = createBN(numTab2, 2, 0);
	showNum(num1);
	showNum(num2);
	showNum(sub(num1, num2));
}

void testMul()
{
}

void testDiv()
{
}

