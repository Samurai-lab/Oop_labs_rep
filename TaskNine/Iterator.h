#ifndef TASKSEVEN_ITERATOR_H
#define TASKSEVEN_ITERATOR_H

#include "Error.h"

template<typename T>
struct Point {
    T num;
    Point *next = nullptr;
};

template<typename T>
class Iterator {
private:
    Point<T> *elem = nullptr;
public:
    Iterator();

    Iterator(const Iterator &it);

    bool operator==(const Iterator &it);

    bool operator!=(const Iterator &it);

    void operator++();

    void operator++(int);

    [[noreturn]] Iterator &operator+(int n) {
        for (int i = 0; i < n && elem->next != nullptr; i++)
            elem = elem->next;
        return *this;
    }

    T operator*() const;
};


#endif
