#include <iostream>
#include "Vector.h"


Vector::Vector() {
    beg = nullptr;
    size = 0;
    cur = 0;
}

Vector::~Vector() {
    if (beg != nullptr) delete[] beg;
    beg = nullptr;
}

[[maybe_unused]] Vector::Vector(int n) {
    beg = new Object *[n];
    cur = 0;
    size = n;
}

void Vector::Add(Object *p) {
    if (cur < size) {
        beg[cur] = p;
        cur++;
    }
}

std::ostream &operator<<(std::ostream &out, const Vector &v) {
    if (v.size == 0) out << "Is empty" << std::endl;
    Object **p = v.beg;
    for (int i = 0; i < v.cur; i++) {
        (*p)->Show();
        p++;
    }
    return out;
}

void Vector::Add() {
    if (cur == size) return;
    Object *o;
    std::cout << "Who's add in list?"
                 "\n1. Person"
                 "\n2. Student\n";
    int n;
    std::cin >> n;
    switch (n) {
        case 1: {
            auto *p = new Person();
            std::cin >> *p;
            o = p;
            Add(o);
            break;
        }
        case 2: {
            auto *s = new Student();
            std::cin >> *s;
            o = s;
            Add(o);
            break;
        }
        default: {
            std::cout << "Error!";
            break;
        }
    }
}

void Vector::Show() const {
    std::cout << *this;
}

void Vector::Del() {
    if (cur == 0)
        return;
    cur--;
}

int Vector::operator()() const {
    return size;
}

void Vector::HandleEvent(const TEvent &e) {
    if (e.what == notEmptyEvent) {
        Object **p = beg;
        for (int i = 0; i < cur; i++) {
            (*p)->HandleEvent(e);
            p++;
        }
    }
}

void Vector::AvgAge() {
    int a = 0;
    if (cur == 0) {
        std::cout << "Vector is empty";
        return;
    }
    Object **p = beg;
    for (int i = 0; i < cur; i++) {
        a += (*p)->AvgAge();
        p++;
    }
    std::cout << "Middle age of people in list: " << a / cur << '\n';
}