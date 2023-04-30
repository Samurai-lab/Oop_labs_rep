//
// Created by brazk on 30.04.2023.
//

#ifndef TASKEIGHT_STUDENT_H
#define TASKEIGHT_STUDENT_H


#include "Person.h"

class Student: public Person {
    std::string subject;
    int mark;
    friend std::istream& operator>>(std::istream& in, Student& s);			// ввод
    friend std::ostream& operator<<(std::ostream& out, const Student& s);		// вывод
public:
    Student();

    [[maybe_unused]] Student(std::string, int, std::string, int);
    ~Student();

    [[maybe_unused]] Student(const Student& s);
    void Show();

    [[maybe_unused]] bool is_norm() const;
    int AvgAge() { return age;  }
};


#endif