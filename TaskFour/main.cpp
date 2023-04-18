#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {

    std::string name = "Egor";

    Person personOne(name, 14);


    Person personTwo(personOne);

    Student student



    std::cout << "Person one name is " << personOne << std::endl;

    std::cout << "Person one name is " << personTwo << std::endl;


    return 0;
}
