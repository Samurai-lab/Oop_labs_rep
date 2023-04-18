#ifndef TASKSEVEN_LINKEDLIST_H
#define TASKSEVEN_LINKEDLIST_H

#include <iostream>
#include <algorithm>
#include "Iterator.h"


template<typename T>
class LinkedList {
private:
    size_t size = 0;
    Point<T> *head = nullptr;
    Point<T> *top = nullptr;

    void output(Point<T> *obj) const;

    void show() const;

public:

    friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list);

    friend std::istream &operator>>(std::istream &in, LinkedList<T> &list);

    LinkedList();

    LinkedList(size_t s, T k);

    ~LinkedList();

    LinkedList(const LinkedList<T> &list);

    T &operator[](int index) const;

    LinkedList &operator=(const LinkedList<T> &list);

    LinkedList operator*(LinkedList<T> &list);

    int operator()();

    void push(T k);

    T pop();

    Iterator<T> first();

    Iterator<T> last();
};

#endif
