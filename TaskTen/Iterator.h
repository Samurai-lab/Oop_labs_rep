//
// Created by brazk on 30.04.2023.
//

#ifndef TASKTEN_ITERATOR_H
#define TASKTEN_ITERATOR_H

#include "LinkedList.h"

template<typename T>
class Iterator {

    Point<T> *elem = nullptr;
public:
    Iterator() { elem = nullptr; }

    Iterator(Point<T> *point) { elem = point; }

    Iterator(const Iterator &it) { elem = it.elem; };

    bool operator==(const Iterator &it) { return elem == it.elem; }

    bool operator!=(const Iterator &it) { return elem != it.elem; }

    void operator++() { elem = elem->next; };

    void operator++(int) { elem = elem->next; };

    Iterator &operator+(int n);

    T operator*() const { return elem->num; };

};




#endif //TASKTEN_ITERATOR_H
