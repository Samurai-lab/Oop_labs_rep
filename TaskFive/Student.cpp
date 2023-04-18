#include "Student.h"

Student::~Student() {}

std::string Student::getSubject() const {
    return subject;
}

int Student::getGrade() const {
    return grade;
}

void Student::setSubject(std::string newSubject) {
    subject = std::move(newSubject);
}

void Student::setGrade(int newGrade) {
    grade = newGrade;
}

std::istream &operator>>(std::istream &in, Student &student) {
    std::string newName;
    int newAge;
    std::cout << "-___________________- \nName: ";
    in >> newName;
    student.setName(newName);
    std::cout << "\nAge: ";
    in >> newAge;
    student.setAge(newAge);
    std::cout << "\nSubject: ";
    in >> student.subject;
    std::cout << "\nGrade: ";
    in >> student.grade;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "Person " << student.getName() << ":"
        << "\nAge - " << student.getAge()
        << "\nSubject - " << student.subject
        << "\nGrade - " << student.grade << std::endl;
    return out;
}

Student &Student::operator=(const Student &student) {
    if (&student == this) return *this;
    setName(student.getName());
    setAge(student.getAge());
    subject = student.subject;
    grade = student.grade;
    return *this;
}

void Student::Show() {
    Person::Show();
    std::cout << "Subject - " << subject
              << "\nGrade - " << grade << std::endl;
}

