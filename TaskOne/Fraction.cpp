#include <cmath>
#include <iostream>
#include "Fraction.h"

void Fraction::Init(double f, int s) {
    first = f;
    second = s;
}

void Fraction::Read() {
    std::cout << "First is ";
    std::cin >> first;
    std::cout << "Second is ";
    std::cin >> second;
}

void Fraction::Show() const {
    std::cout << "\nFirst = " << first;
    std::cout << "\nSecond = " << second << std::endl;
}

double Fraction::Power() const {
    return pow(first, second);
}