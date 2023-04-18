#ifndef TASKFOUR_VECTOR_H
#define TASKFOUR_VECTOR_H

#include <iostream>
#include "Organism.h"

class Vector {

    Organism **begin;
    int size;
    int current;

public:
    Vector();

    Vector(int elements);

    ~Vector();

    void add(Organism *organism);

    friend std::ostream &operator<<(std::ostream &out, const Vector &vector);
};


#endif
