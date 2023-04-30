#ifndef TASKTEN_LINKEDLIST_H
#define TASKTEN_LINKEDLIST_H

#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Pair.h"
#include "Iterator.h"
#include "FileIO.h"

template<typename T>
class LinkedList {
private:
    size_t size = 0;
    Point<T> *head = nullptr;
    Point<T> *top = nullptr;

    void output(Point<T> *obj) const;

    void show() const;

public:
    friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list) {
        list.show();
        return out;
    }

    friend std::istream &operator>>(std::istream &in, LinkedList<T> &list) {
        T k;
        in >> k;
        list.push(k);
        return in;
    }

    LinkedList();

    LinkedList(size_t s, T k);

    ~LinkedList();

    LinkedList(const LinkedList<T> &list);

    T &operator[](int index) const;

    LinkedList &operator=(const LinkedList<T> &list);

    LinkedList operator*(LinkedList<T> &list);

    int operator()() { return size; };

    void push(T k);

    T pop();

    Iterator<T> first() { return Iterator<T>(head); }

    Iterator<T> last() { return Iterator<T>(nullptr); }

    size_t give_size() { return size; }
};

#endif
