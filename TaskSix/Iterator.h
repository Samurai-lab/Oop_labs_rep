
#ifndef TASKSIX_ITERATOR_H
#define TASKSIX_ITERATOR_H

#include <iostream>
#include <algorithm>

struct Point {
    int num = 0;
    Point *next = nullptr;
};

class Iterator {

    friend class LinkedList;

    Point *elem = nullptr;
public:
    Iterator();

    Iterator(const Iterator &it);

    bool operator==(const Iterator &it);

    bool operator!=(const Iterator &it);

    void operator++();

    void operator++(int);

    Iterator &operator+(int n);

    int operator*() const;
};


#endif
