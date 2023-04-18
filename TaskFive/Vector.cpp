#include "Vector.h"

Vector::Vector() {
    begin = 0;
    size = 0;
    current = 0;
}

Vector::Vector(int elements) {
    size = elements;
    begin = new Organism *[size]{};
    current = 0;
}

Vector::~Vector() {
    if (begin != 0) delete[] begin;
    begin = 0;
}

void Vector::add(Organism *organism) {
    if (current < size) {
        begin[current] = organism;
        current++;
    }
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
    if (vector.size == 0) out << "Vector is empty\n";
    Organism **organism = vector.begin;
    for (int i = 0; i < vector.current; i++) {
        (*organism)->Show();
        organism++;
    }
    return out;
}
