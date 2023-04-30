#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator() {
    elem = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const Iterator &it) {
    elem = it.elem;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator &it) {
    return elem == it.elem;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator &it) {
    return elem != it.elem;
}

template<typename T>
void Iterator<T>::operator++() {
    if (elem == nullptr) throw IndexError2();
    elem = elem->next;
    return *this;
}

template<typename T>
void Iterator<T>::operator++(int) {
    if (elem == nullptr) throw IndexError2();
    Iterator<T> temp(elem);
    ++(*this);
    return temp;
}

template<typename T>
T Iterator<T>::operator*() const {
    if (elem)
        return elem->num;
    else
        throw IndexError2();
}