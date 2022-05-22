#define CATCH_CONFIG_MAIN
#include "arythmeticLiblary.h"
#include "calculatingNumber.h"
#include "catch.hpp"

TEST_CASE("1.0") {

	unsigned char numTab1[2] = { 0x00,0x00 };
	unsigned char numTab2[1] = { 0xff };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 1, 0);
	REQUIRE(-1 == calculatingBigNumber(add(num1, num2)));
	REQUIRE(-1 == calculatingBigNumber(add(num2, num1)));

}

TEST_CASE("1.1") {

	unsigned char numTab1[2] = { 0x03, 0x00 };
	unsigned char numTab2[2] = { 0x02,0x00 };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 2, 0);

	REQUIRE(5 == calculatingBigNumber(add(num1, num2)));
	REQUIRE(5 == calculatingBigNumber(add(num2, num1)));

}

TEST_CASE("1.2") {

	unsigned char numTab1[2] = { 0x03, 0x00 };
	unsigned char numTab2[3] = { 0x02,0xff, 0xff};
	BigNum num1 = createBN(numTab1, 2, 4);
	BigNum num2 = createBN(numTab2, 3, 7);
	/*
	showNum(num1);
	showNum(num2);

	showNum(add(num1, num2));
	showNum(add(num2, num1));
	*/
	REQUIRE(-1.796875 == calculatingBigNumber(add(num1, num2)));
	REQUIRE(-1.796875 == calculatingBigNumber(add(num2, num1)));

}

TEST_CASE("1.3") {

	unsigned char numTab1[2] = { 0x03, 0x00 };
	unsigned char numTab2[3] = { 0x01,0x00, 0x00 };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 3, 0);

	REQUIRE(4 == calculatingBigNumber(add(num1, num2)));
	REQUIRE(4 == calculatingBigNumber(add(num1, num2)));

}

TEST_CASE("1.4") {

	unsigned char numTab1[2] = { 0xff, 0xff };
	unsigned char numTab2[3] = { 0xfd,0xff };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 2, 0);

	REQUIRE(-4 == calculatingBigNumber(add(num1, num2)));
	REQUIRE(-4 == calculatingBigNumber(add(num1, num2)));

}

TEST_CASE("2.0") {

	unsigned char numTab1[2] = { 0x03, 0x00 };
	unsigned char numTab2[3] = { 0x0ff,0xff, 0xff };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 3, 0);

	showNum(num1);
	showNum(num2);

	REQUIRE(4 == calculatingBigNumber(sub(num1, num2)));
	REQUIRE(-4 == calculatingBigNumber(sub(num2, num1)));

}

TEST_CASE("2.1") {

	unsigned char numTab1[2] = { 0x66, 0x00 };
	unsigned char numTab2[3] = { 0x0f7,0xff, 0xff };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 3, 0);

	showNum(num1);
	showNum(num2);

	REQUIRE(111 == calculatingBigNumber(sub(num1, num2)));
	REQUIRE(-111 == calculatingBigNumber(sub(num2, num1)));

}

TEST_CASE("2.2") {

	unsigned char numTab1[2] = { 0x66, 0x00 };
	unsigned char numTab2[3] = { 0x07,0x00, 0x0 };
	BigNum num1 = createBN(numTab1, 2, 0);
	BigNum num2 = createBN(numTab2, 3, 0);

	showNum(num1);
	showNum(num2);

	REQUIRE(95 == calculatingBigNumber(sub(num1, num2)));
	REQUIRE(-95 == calculatingBigNumber(sub(num2, num1)));

}
