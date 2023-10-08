#define N 3
#include <math.h>
#include <iostream>
#include <stdio.h>

class CIntN {
public:
    int digit_[N];
    int length_ = N;

    // Стандартный конструктор
    CIntN();

    // Конструктор для ввода числа
    CIntN(const int n);

    CIntN(int array[N]);

    // Оператор сложения
    CIntN operator+(const CIntN& second);

    // Оператор вычитания
    CIntN operator-(const CIntN& second);
};
