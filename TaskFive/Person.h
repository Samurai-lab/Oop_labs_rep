#ifndef TASKFOUR_PERSON_H
#define TASKFOUR_PERSON_H

#include <iostream>
#include <string>
#include "Organism.h"


class Person : public Organism {
    std::string name;
    int age;
public:
    Person();

    Person(std::string ownName, int ownAge);

    Person(const Person &person);

    ~Person();

    void Show() override;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] int getAge() const;

    void setName(std::string newName);

    void setAge(int newAge);

    Person &operator=(const Person &person);

    friend std::istream &operator>>(std::istream &in, Person &person);

    friend std::ostream &operator<<(std::ostream &out, const Person &person);

};


#endif
