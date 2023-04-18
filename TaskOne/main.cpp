#include <iostream>
#include "Fraction.h"

Fraction makeFraction(double first, int second) {
    Fraction fract{};
    fract.Init(first, second);
    return fract;
}

int main() {
    Fraction A{};
    Fraction B{};
    A.Init(3.0, 2);//инициализация переменной
    B.Read();//ввод полей переменных
    A.Show();//вывод значений полей переменной
    B.Show();//вывод значений полей переменной
//вывод значения степени, вычисленного с помощью функции
    std::cout << "A.Power(" << A.first << "," << A.second << ")=" << A.Power() << std::endl;
    std::cout << "B.Power(" << B.first << "," << B.second << ")=" << B.Power() << std::endl;
//указатели
    auto *X = new Fraction;//выделение памяти под динамическую переменную
    X->Init(2.0, 5);//инициализация
    X->Show();//вывод значений полей
    X->Power();//вычисление степени

    std::cout << "X.Power(" << X->first << "," << X->second << ")=" << X->Power() << std::endl;
//массивы
    Fraction mas[3];//определение массива
    for (auto &ma: mas)
        ma.Read();//чтение значений полей
    for (auto ma: mas)
        ma.Show(); //вывод значений полей
    for (int i = 0; i < 3; i++) {
        mas[i].Power(); //вычисление степени
        std::cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
        std::cout << mas[i].Power() << std::endl;
    }
//динамические масивы
    auto *p_mas = new Fraction[3];//выделение памяти
    for (int i = 0; i < 3; i++)
        p_mas[i].Read();//чтение значений полей
    for (int i = 0; i < 3; i++) p_mas[i].Show();//вывод значений полей

    for (int i = 0; i < 3; i++) {
        p_mas[i].Power();//вычисление степени
        std::cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second;
        std::cout << ")=" << p_mas[i].Power() << std::endl;
    }
//вызов функции makeFraction();
    double y;
    int z;
    std::cout << "first: ";
    std::cin >> y;
    std::cout << "second: ";
    std::cin >> z;
//переменная F формируется с помощью функции makeFraction()
    Fraction F = makeFraction(y, z);
    F.Show();
    return 0;
}
