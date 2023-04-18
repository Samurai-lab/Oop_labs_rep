#ifndef TASKSIX_LINKEDLIST_H
#define TASKSIX_LINKEDLIST_H

#include <iostream>
#include "Iterator.h"
#include <algorithm>

class LinkedList {
    Iterator beg, end;
    size_t size = 0;
    Point *head = nullptr;
    Point *top = nullptr;

    void output(Point *obj) const;

    void show() const;

    friend std::ostream &operator<<(std::ostream &out, const LinkedList &list);

    friend std::istream &operator>>(std::istream &in, LinkedList &list);

public:
    Iterator first();

    Iterator last();

    LinkedList();

    LinkedList(size_t s, int k);

    ~LinkedList();

    LinkedList(const LinkedList &list);

    int &operator[](int index) const;

    LinkedList &operator=(const LinkedList &list);

    LinkedList operator*(LinkedList &list);

    int operator()();

    void push(int k);

    int pop();
};

#endif
