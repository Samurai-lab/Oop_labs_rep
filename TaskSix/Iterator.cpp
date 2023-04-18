#include "Iterator.h"

Iterator::Iterator() {
    elem = nullptr;
}

Iterator::Iterator(const Iterator &it) {
    elem = it.elem;
}

bool Iterator::operator==(const Iterator &it) {
    return elem == it.elem;
}

bool Iterator::operator!=(const Iterator &it) {
    return elem != it.elem;
}

void Iterator::operator++() {
    elem = elem->next;
}

void Iterator::operator++(int) {
    elem = elem->next;
}

Iterator &Iterator::operator+(int n) {
    for (int i = 0; i < n && elem->next != nullptr; i++)
        elem = elem->next;
    return *this;
}

int Iterator::operator*() const {
    return elem->num;
}
