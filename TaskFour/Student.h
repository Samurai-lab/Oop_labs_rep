#ifndef TASKFOUR_STUDENT_H
#define TASKFOUR_STUDENT_H

#include <utility>

#include "Person.h"

class Student : public Person {
    std::string subject;
    int grade;
public:

    Student() : Person() {
        subject = "Informatics";
        grade = 5;
    };

    Student(std::string ownName, int ownAge, std::string ownSubject, int subjGrade) :
            Person(
                    std::move(ownName),
                    ownAge
            ) {
        subject = std::move(ownSubject);
        grade = subjGrade;
    };

    Student(Student &student) : Person(student) {
        subject = student.subject;
        grade = student.grade;
    }

    [[nodiscard]] std::string getSubject() const;

    [[nodiscard]] int getGrade() const;

    void setSubject(std::string newSubject);

    void setGrade(int newGrade);

    Student &operator=(const Student &student);

    friend std::istream &operator>>(std::istream &in, Student &student);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);


};


#endif
