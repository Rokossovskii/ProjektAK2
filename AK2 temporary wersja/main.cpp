#include <iostream>
#include "struktura.h"

int main()
{
    unsigned char x1[3] =  {0xe1, 0x12, 0x03}; // zawartosc liczby 1
    unsigned char x2[4] = {0xff, 0x0a, 0x2b, 0x6e}; // zawartosc liczby 2
    BigNum *num1 = constructBigNum(x1, 3, 8); 
    BigNum *num2 = constructBigNum(x2, 4, 8);
    std::cout << outputString(num1) << std::endl << outputString(num2) << std::endl;
    num1 = skaluj(num1, 2); 
    std::cout << outputString(num1) << std::endl << outputString(num2) << std::endl;
}