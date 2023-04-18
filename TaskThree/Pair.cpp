#include "Pair.h"

Pair::Pair() {
    first = 0;
    second = 0;
}

Pair::Pair(int f, int s) {
    first = f;
    second = s;
}

Pair::Pair(const Pair &pair) {
    first = pair.first;
    second = pair.second;
}

int Pair::getFirst() const {
    return first;
}

double Pair::getSecond() const {
    return second;
}

void Pair::setFirst(int f) {
    first = f;
}

void Pair::setSecond(double s) {
    second = s;
}

std::ostream &operator<<(std::ostream &out, const Pair &pair) {
    return (out << pair.first << " : " << pair.second << std::endl);
}

std::istream &operator>>(std::istream &in, Pair &pair) {
    std::cout << "First int number is ";
    in >> pair.first;
    std::cout << "\nSecond int number is ";
    in >> pair.first;
    return in;
}

void Pair::pairSubtraction(int f, double s) {
    first -= f;
    second -= s;
}

template<class T>
Pair &operator+(Pair &pair, T num) {
    if (typeid(num) == typeid(pair.getFirst())) {
        pair.setFirst(num + pair.getFirst());
    } else if (typeid(num) == typeid(pair.getSecond())) {
        pair.setSecond(num + pair.getSecond());
    }
    return pair;
}