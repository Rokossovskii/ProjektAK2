#include "arythmeticLiblary.h"


BigNum createBN(unsigned char* num, int numSize, int numPos)
{
	BigNum bigNum;
	bigNum.number = num;
	bigNum.numberSize = numSize;
	bigNum.numberPosition = numPos;
	return bigNum;
}

/*
BigNum* add(BigNum* num1, BigNum* num2) {
	if (num1->numberSize < num2->numberSize) {
		BigNum* temp = num1;
		num1 = num2;
		num2 = temp;
	}

	if (num2->numberSize * 8 + num1->numberPosition > num1->numberSize * 8) {
		for (int i = num1->numberSize - 1, j = num2->numberSize - 1; i >= 0; i--, j--) {
			unsigned char temp;
			temp = num1->number[i];
			if (j >= 0) {
				num1->number[i] = num2->number[j];
				num2->number[j] = temp;
			}
			else {
				num1->number[i] = 0;
			}
		}
	}

	BigNum* helpNum = new BigNum();
	if (num1->numberPosition < num2->numberPosition)
		helpNum = num1;
	else
		helpNum = num2;
	int slide = (num1->numberPosition - num2->numberPosition) * (1 - 2 * (num1->numberPosition < num2->numberPosition));
	unsigned int size = helpNum->numberSize;
	unsigned int num2Var;
	unsigned int sum = 0;

	if (slide != 0)
	{
		unsigned char* tmp = new unsigned char;
		for (int i = 0; i < (slide + 7) / 8 - 1; i++)
			tmp[i] = 0x00;
		for (int i = (slide + 7) / 8 - 1; i < (slide + 7) / 8 + helpNum->numberSize - 1; i++)
			tmp[i] = helpNum->number[i - ((slide + 7) / 8 - 1)];
		tmp[(slide + 7) / 8 + helpNum->numberSize - 1] = 0x00;
		helpNum = createBN(tmp, helpNum->numberSize + (slide + 7) / 8, helpNum->numberPosition);

		unsigned char pomocy = 0x00;
		for (int i = helpNum->numberSize; i > 0; i--)
		{
			pomocy = helpNum->number[i] >> (8 - slide % 8);
			helpNum->number[i] = helpNum->number[i] << (slide % 8);
			helpNum->number[i + 1] = helpNum->number[i + 1] | pomocy;
		}
		helpNum->numberPosition = num2->numberPosition * (num2->numberPosition > num1->numberPosition) + num1->numberPosition * (num2->numberPosition <= num1->numberPosition);
	}
	if (num1->numberPosition < num2->numberPosition)
		num1 = helpNum;
	else
		num2 = helpNum;
	/*
	std::cout << "---------------------------" << std::endl;
	double number = 0;
	for (int i = num1->numberSize; i > 0; i--) {
		std::cout << std::bitset<8>(num1->number[i - 1]) << " ";
		number = number + (int(num1->number[i - 1]) * pow(256, i - 1));
	}
	number = number / pow(2, num1->numberPosition);
	std::cout << num1->numberPosition << std::endl << number << std::endl << std::endl;

	number = 0;
	for (int i = num2->numberSize; i > 0; i--) {
		std::cout << std::bitset<8>(num2->number[i - 1]) << " ";
		number = number + (int(num2->number[i - 1]) * pow(256, i - 1));
	}
	number = number / pow(2, num2->numberPosition);
	std::cout << num2->numberPosition << std::endl << number << std::endl;
	std::cout << "---------------------------" << std::endl;
	
	char carry = 0x00;
	for (int i = num2->numberSize - 1; i >= 0; i--)
	{
		num1->number[i] += carry;
		carry = 0x00 + 0x01 * (num1->number[i] + num2->number[i] > 0xff);

		num1->number[i] += num2->number[i];
	}

	return num1;
}
*/

BigNum add(BigNum num1, BigNum num2) {
	BigNum additionResoult;
	unsigned char num1temp = 0x00;
	unsigned char num2temp = 0x00;
	unsigned int carry = 0;
	int slide;

	if (num1.numberPosition < num2.numberPosition) {
		BigNum temp = num1;
		num1 = num2;
		num2 = temp;
	}

	if (num1.number[num1.numberSize - 1] > 127) num1temp = 0xff;
	if (num2.number[num2.numberSize - 1] > 127) num2temp = 0xff;

	slide = num1.numberPosition - num2.numberPosition;

	additionResoult.numberPosition = num1.numberPosition;
	
	additionResoult.numberSize = num1.numberSize;
	if (num2.numberSize * 8 + num1.numberPosition > num1.numberSize * 8) {
		additionResoult.numberSize = (num2.numberSize * 8 + num1.numberPosition) / 8 + 1;
	}

	additionResoult.number = new unsigned char[additionResoult.numberSize];

	for (int i = 0; i < additionResoult.numberSize; i++) {
		if (i < num1.numberSize) {
			//std::cout << std::bitset<8>(num1.number[i]) << std::endl;
			carry += num1.number[i];

		}
		else {
			carry += num1temp;
		}

		if (i >= slide/8 && i+ slide / 8 <num2.numberSize) {

			//std::cout << std::bitset<8>(num2.number[i - slide / 8]) << std::endl;

			carry += (num2.number[i - slide / 8]<<(slide%8));

			//std::cout << std::endl << std::bitset<8>(carry) << std::endl << std::endl;
		}
		else {
			carry += (num2temp << (slide % 8));
		}
		
		additionResoult.number[i] = carry;

		carry = carry >> 8;
	}

	return additionResoult;
}

BigNum sub(BigNum num1, BigNum num2) {
	for (int i = 0; i < num2.numberSize; i++)
	{
		num2.number[i] = ~num2.number[i];
	}
	num2.number[0] += 0x01;

	BigNum temp = add(num1,num2);

	for (int i = 0; i < num2.numberSize; i++)
	{
		num2.number[i] = ~num2.number[i];
	}
	num2.number[0] += 0x01;

	return temp;
}

BigNum mul(BigNum num1, BigNum num2) {
	num1.numberPosition = num1.numberPosition + num2.numberPosition;
	int newSize = num1.numberSize + num2.numberSize;
	unsigned int mul = 0;
	unsigned char var1 , var2;
	unsigned char* helpTab = new unsigned char[newSize];

	for (int i = 0; i < newSize; i++) {
		helpTab[i] = 0;
	}

	for (int i = 0; i < newSize; i++) {
		var1 = 0; var2 = 0;
		if (i < num1.numberSize) {
			var1 = num1.number[i];
		};
		if (i < num2.numberSize) {
			var2 = num2.number[i];
		}
		mul = mul + var1 * var2;
		helpTab[i] = mul;
		mul = mul >> 8;
		
	}
	num1.number = helpTab;
	num1.numberSize = newSize;
	return num1;
}

BigNum div(BigNum num1, BigNum num2) {
	num1.numberPosition = num1.numberPosition - num2.numberPosition;

	return num1;
}