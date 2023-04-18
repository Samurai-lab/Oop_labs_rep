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
    elem = elem->next;
}

template<typename T>
void Iterator<T>::operator++(int) {
    elem = elem->next;
}

template<typename T>
T Iterator<T>::operator*() const {
    return elem->num;
}