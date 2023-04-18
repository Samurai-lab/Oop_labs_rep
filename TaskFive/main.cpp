#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include "Organism.h"

int main() {

    Vector vector(4);
    Person personOne;
    std::cin >> personOne;

    Student studentOne;
    std::cin >> studentOne;

    Organism *organism = &personOne;

    vector.add(organism);

   organism = &studentOne;

    vector.add(organism);

    std::cout << vector;

    return 0;
}