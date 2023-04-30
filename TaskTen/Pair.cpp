#include "Pair.h"

bool Pair::operator<=(const Pair &p) {
    return this->numINT <= p.numINT && this->numDOUBLE <= p.numDOUBLE;
}

Pair Pair::operator*(Pair &pair) {
    Pair new_pair;
    new_pair.numINT = this->numINT * pair.numINT;
    new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
    return new_pair;
}

Pair &Pair::operator=(const Pair &pair) {
    this->numINT = pair.numINT;
    this->numDOUBLE = pair.numDOUBLE;
    return *this;
};

Pair &Pair::operator=(const int &k) {
    this->numINT = k;
    this->numDOUBLE = k;
    return *this;
}

Pair::Pair(int a, double b) {
    numINT = a;
    numDOUBLE = b;
}

Pair Pair::operator-(const Pair &p) {
    Pair res(numINT - p.numINT, numDOUBLE - p.numDOUBLE);
    return res;

}

Pair &Pair::operator+(int a) {
    this->numINT += a;
    return *this;
}

Pair &Pair::operator+(double b) {
    this->numDOUBLE += b;
    return *this;
}

Pair &Pair::operator++() {
    ++numINT;
    ++numDOUBLE;
    return *this;
}

Pair Pair::operator++(int) {
    Pair temp = *this;
    this->numINT++;
    this->numDOUBLE++;
    return temp;
}