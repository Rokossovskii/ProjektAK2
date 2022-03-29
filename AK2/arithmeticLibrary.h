#pragma once

struct num{
    bool *tab;
    int length = 0;
    int przecinek = 0;
};

bool* addInU2(bool* num1, int length1, int przecinek1, bool* num2, int length2, int przecinek2);

bool* subInU2(bool* num1, int length1, int przecinek1, bool* num2, int length2, int przecinek2);

bool* mulInU2(bool* num1, int length1, int przecinek1, bool* num2, int length2, int przecinek2);

bool* divInU2(bool* num1, int length1, int przecinek1, bool* num2, int length2, int przecinek2);