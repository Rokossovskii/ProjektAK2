#include <iostream>
#include "ArythmeticLiblary.h"
#include "TestFunctions.h"
#include <bitset>
#include <math.h>

void showNum(BigNum num) {
	int number = 0;
	for (int i = num.numberSize; i > 0; i--) {
		std::cout << std::bitset<8>(num.number[i-1]) << " ";
		number = number + (int(num.number[i - 1])*pow(256,i-1));
	}
	std::cout << std::endl << number << std::endl << std::endl;
}

void testNum() {
	unsigned char numTab[2] = { 0x00,0x0 };
	BigNum num = createBN(numTab, 2, 0);
	showNum(num);
}

void testAdd() {
	unsigned char numTab1[2] = { 0xFE,0x0 };
	unsigned char numTab2[2] = { 0x01,0x0 };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 2, 0);
	showNum(add(num1,num2));
}

void testSub()
{
	unsigned char numTab1[2] = { 0x03,0x0 };
	unsigned char numTab2[2] = { 0x01,0x0 };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 2, 0);
	showNum(sub(num1, num2));
}

void testMul()
{
}

void testDiv()
{
}

