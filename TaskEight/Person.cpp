#include "Person.h"

#include <utility>

Person::Person() {
    this->name = "";
    this->age = 0;
}

[[maybe_unused]] Person::Person(std::string name, int age) {
    this->name = std::move(name);
    this->age = age;
}

Person::Person(const Person &p) {
    age = p.age;
    name = p.name;
}

Person::~Person() {
    std::cout << "Called destructor of object from class Person" << std::endl;
}

std::istream &operator>>(std::istream &in, Person &p) {
    std::cout << "Write name: ";
    in >> p.name;
    std::cout << "Write age: ";
    in >> p.age;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Person &p) {

    return (out << p.name << " : " << p.age);
}

[[maybe_unused]] void Person::set_name(std::string name) {
    this->name = std::move(name);
}

[[maybe_unused]] void Person::set_age(int age) {
    this->age = age;
}

[[maybe_unused]] std::string Person::get_name() {
    return name;
}

int Person::get_age() const {
    return age;
}

void Person::Show() {
    std::cout << name << ": " << age << std::endl;
}

void Person::HandleEvent(const TEvent &e) {
    if (e.what == notEmptyEvent) {
        switch (e.command) {
            case displayAbbrnAllOjb:
                std::cout << *this;
                break;
        }
    }
}
