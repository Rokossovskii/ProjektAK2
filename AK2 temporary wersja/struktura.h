#include <iostream>


struct BigNum{
    unsigned char *number; // liczba w tablicy bajtów (jeden char = 1 bajt = 16 bitów w jednej komórce tablicy)
    unsigned int numberSize; // długość liczby w bajtach
    unsigned int numberPosition; // pozycja najmniej znaczącego bitu w bitach (pozycja cyfry przed przecinkiem)
};

BigNum* constructBigNum(unsigned char *number, unsigned int numberSize, int numberPosition); // konstruktor liczby 
char* outputString(BigNum *num); // konstruktor stringa do wypisania (możliwe że niepotrzebne ale chciałem podzielić)
char* byteToAscii(unsigned char *number, unsigned size, char *result); // zmienia liczbę zapisaną w bajtach na string (np. w celu wypisania na ekranie)
BigNum* add(BigNum *num1, BigNum *num2); // dodawanie to be done 
BigNum *skaluj(BigNum *num, unsigned int targetSize); // rozszerzanie długości liczby do prostszego dodawania

