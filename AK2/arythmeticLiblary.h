#pragma once

struct BigNum {
	unsigned char* number;        // liczba w tablicy bajtow (jeden char = 1 bajt = 8 bitow w jednej komorce tablicy)
	unsigned int numberSize;      // dlugosc liczby w bajtach
	unsigned int numberPosition;  // pozycja najmniej znaczacego bitu w bitach (pozycja cyfry przed przecinkiem)
};

BigNum createBN(unsigned char*, int, int);

BigNum add(BigNum, BigNum);

BigNum sub(BigNum, BigNum);

BigNum mul(BigNum, BigNum);

BigNum div(BigNum, BigNum);