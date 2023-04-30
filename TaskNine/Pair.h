#ifndef TASKSEVEN_PAIR_H
#define TASKSEVEN_PAIR_H

#include <ostream>
#include <istream>

struct Pair {
    Pair();

    Pair(int a, double b);

    int numINT = 0;
    double numDOUBLE = 0;

    Pair &operator=(const Pair &pair);

    Pair &operator=(const int &k);

    friend std::ostream &operator<<(std::ostream &out, const Pair &pair);

    friend std::istream &operator>>(std::istream &in, Pair &pair);

    Pair operator*(Pair &pair);
};


#endif
