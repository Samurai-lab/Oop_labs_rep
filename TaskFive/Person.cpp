#include "Person.h"


Person::Person() {
    name = "Egor";
    age = 21;
}

Person::Person(std::string ownName, int ownAge) {
    name = std::move(ownName);
    age = ownAge;
}

Person::Person(const Person &person) {
    name = person.name;
    age = person.age;
}

Person::~Person() {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::setName(std::string newName) {
    name = std::move(newName);
}

void Person::setAge(int newAge) {
    age = newAge;
}

std::istream &operator>>(std::istream &in, Person &person) {
    std::cout << "-___________________- \nName: ";
    in >> person.name;
    std::cout << "\nAge: ";
    in >> person.age;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << "Person " << person.name << ":" << "\nAge - " << person.age << std::endl;
    return out;
}

Person &Person::operator=(const Person &person) {
    if (&person == this) return *this;
    name = person.name;
    age = person.age;
    return *this;
}

void Person::Show() {
    std::cout << "Person " << name
              << ":"
              << "\nAge - " << age << std::endl;
}
