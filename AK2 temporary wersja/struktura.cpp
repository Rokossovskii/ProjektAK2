
#include "struktura.h"

BigNum* constructBigNum(unsigned char *number, unsigned int numberSize, int numberPosition) // konstruktor
{
    BigNum *n = new BigNum;
    n->number = number; 
    n->numberSize = numberSize; 
    n->numberPosition = numberPosition; 
    return n;
}

char* outputString(BigNum *num) // nie wiem czy nie wystarczy tego wsadzić do byteToAscii ale myślałem czy nie rozszerzeżyć z wypisywaniem przecinka lub w dwójkowym
{
    char *stringBigNum;
    stringBigNum = (char*) calloc(num->numberSize, sizeof(char));
    byteToAscii(num->number, num->numberSize, stringBigNum);
    return stringBigNum;
}

char *byteToAscii(unsigned char *number, unsigned size, char *stringBigNum)
{
    char highHalfByte, lowHalfByte;

    for (int i = 0; i < size; i++)
    {
        highHalfByte = (number[i] >> 4) & 0x0F; // bierze 4 bardziej znaczące bity z bajtu i zapisuje jako pojedynczą liczbę szesnastkową
        lowHalfByte = number[i] & 0x0F; // bierze 4 mniej znaczące bity z bajtu i zapisuje jako pojedynczą liczbę szesnastkową
        if (highHalfByte < 10)
            stringBigNum[2 * i] = highHalfByte + '0';  // jeśli liczba jest od 0 do 9 zapisuje ją w stringu 0-9
        else
            stringBigNum[2 * i] = highHalfByte + 'A' - 10; // jeśli liczba jest od 10 do 15 zapisuję ją w stringu A-F

        if (lowHalfByte < 10) // to co powyżej ale dla mniej znaczących bitów 
            stringBigNum[2 * i + 1] = lowHalfByte + '0';
        else
            stringBigNum[2 * i + 1] = lowHalfByte + 'A' - 10;
    }
    return stringBigNum;
}

BigNum* add(BigNum *num1, BigNum *num2)
{
    
    return num1;
}

BigNum *skaluj(BigNum *num, unsigned int targetSize)
{
    unsigned char *temp = (unsigned char*) calloc(targetSize, sizeof(char)); //temporary do zwrócenia na końcu
    int poczatek = targetSize - 1 - num->numberSize; // liczba bajtów przedłużenia
    unsigned char przedluzenie = 0; // cyfra którą przedłużamy liczbę 00 lub ff (00000000/11111111)

    if (num->number[0] >= 128) // wpisujemy jedynki zamiast zer (liczba ujemna)
    {
        przedluzenie = 0xff; 
        for (int i = 0; i <= poczatek; i++)
            temp[i] = przedluzenie;
    }
    if (poczatek >= 0) // normalnie kopiujemy bo przedłużamy liczbę
        memcpy(temp + poczatek + 1, num->number, num->numberSize);
    else // zmniejszamy liczbę (może się przyda, najwyżej do usunięcia)
    {
        memcpy(temp, num->number, num->numberSize);
    }

    delete (num); // kasujemy z pamięci poprzednią liczbę

    BigNum *result = constructBigNum(temp, targetSize, num->numberPosition);  // tworzymy nową przedłużoną o zera lub jedynki na przedzie
    return result;
}
