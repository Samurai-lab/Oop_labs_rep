#ifndef TASKTEN_PAIR_H
#define TASKTEN_PAIR_H

#include <fstream>

class Pair {
public:
    Pair() {}

    Pair(int a, double b);

    int numINT = 0;
    double numDOUBLE = 0;

    Pair &operator=(const Pair &pair);

    Pair &operator=(const int &k);

    friend std::fstream &operator>>(std::fstream &fin, Pair &p) {
        fin >> p.numINT;
        fin >> p.numDOUBLE;
        return fin;
    }

    friend std::fstream &operator<<(std::fstream &fout, const Pair &p) {
        fout << p.numINT << "\n" << p.numDOUBLE << "\n";
        return fout;
    }

    friend std::ostream &operator<<(std::ostream &out, const Pair &pair) {
        out << pair.numINT << " : " << pair.numDOUBLE;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Pair &pair) {
        in >> pair.numINT >> pair.numDOUBLE;
        return in;
    }

public:
    Pair operator*(Pair &pair);

    Pair operator-(const Pair &p);

    Pair &operator+(int a);

    Pair &operator+(double b);

    Pair &operator++();

    Pair operator++(int);

    bool operator<=(const Pair &p);
};

#endif
