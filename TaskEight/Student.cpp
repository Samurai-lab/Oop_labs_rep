#include "Student.h"

#include <utility>

Student::Student() {
    name = "";
    subject = "";
    age = 0;
    mark = 0;
}

[[maybe_unused]] Student::Student(std::string name, int age, std::string subject, int mark) {
    this->name = std::move(name);
    this->age = age;
    this->subject = std::move(subject);
    this->mark = mark;
}

Student::~Student() {
    std::cout << "Destructor of object from class Student" << std::endl;
}

[[maybe_unused]] Student::Student(const Student &s) : Person(s) {
    name = s.name;
    age = s.age;
    subject = s.subject;
    mark = s.mark;
}

std::istream &operator>>(std::istream &in, Student &s) {
    std::cout << "Write name: ";
    in >> s.name;
    std::cout << "Write age: ";
    in >> s.age;
    std::cout << "Write subject: ";
    in >> s.subject;
    std::cout << "Write mark: ";
    in >> s.mark;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Student &s) {
    return (out << s.name << " : " << s.age << " | " << s.subject << " : " << s.mark);
}

void Student::Show() {
    std::cout << name << " : " << age << " | " << subject << " : " << mark << std::endl;
}

[[maybe_unused]] bool Student::is_norm() const {
    if (mark < 4) {
        std::cout << "Bad grade" << std::endl;
        return false;
    }
    std::cout << "Good grade" << std::endl;
    return true;


}