#ifndef TASKTHREE_PAIR_H
#define TASKTHREE_PAIR_H

#include <iostream>

class Pair {
    int first;
    double second;
public:
    Pair();

    Pair(int, int);

    Pair(const Pair &pair);

    [[nodiscard]] int getFirst() const;

    [[nodiscard]] double getSecond() const;

    void setFirst(int f);

    void setSecond(double s);


    friend std::ostream &operator<<(std::ostream &out, const Pair &pair);

    friend std::istream &operator>>(std::istream &in, Pair &pair);

    void pairSubtraction(int f, double s);

    template<class T>
    friend Pair &operator+(Pair &pair, T num);
};


#endif
