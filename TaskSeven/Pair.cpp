#include "Pair.h"



Pair::Pair() {

}

Pair::Pair(int a, double b) {
    numINT = a;
    numDOUBLE = b;
}

Pair &Pair::operator=(const Pair &pair) {
    this->numINT = pair.numINT;
    this->numDOUBLE = pair.numDOUBLE;
    return *this;
}

Pair &Pair::operator=(const int &k) {
    this->numINT = k;
    this->numDOUBLE = k;
    return *this;
}

Pair Pair::operator*(Pair &pair) {
    Pair new_pair;
    new_pair.numINT = this->numINT * pair.numINT;
    new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
    return new_pair;
}

std::ostream &operator<<(std::ostream &out, const Pair &pair) {
    out << pair.numINT << " : " << pair.numDOUBLE << " |";
    return out;
}

std::istream &operator>>(std::istream &in, Pair &pair) {
    in >> pair.numINT >> pair.numDOUBLE;
    return in;
}
