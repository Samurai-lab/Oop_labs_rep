#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    top = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(size_t s, T k) {
    size = s;
    if (size != 0) {

        auto *obj = new Point<T>;
        obj->num = k;
        head = obj;

        Point <T> *temp = head;
        for (int i = size - 1; i != 0; i--) {
            obj = new Point<T>;
            temp->next = obj;
            obj->num = k;
            temp = obj;
        }
        top = obj;
    }
}

template<typename T>
void LinkedList<T>::push(T k) {
    if (size == 0) {
        head = new Point<T>;
        head->num = k;
        top = head;

    } else {
        auto *obj = new Point<T>;
        top->next = obj;
        obj->num = k;
        top = obj;
    }
    size++;
}

template<typename T>
T LinkedList<T>::pop() {
    T k = head->num;
    Point <T> *temp = head;
    head = head->next;
    size--;
    delete temp;
    return k;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        pop();
    }
}

template<typename T>
void LinkedList<T>::output(Point <T> *obj) const {
    std::cout << obj->num << "\n";
    if (obj == top) return;
    output(obj->next);
}

template<typename T>
void LinkedList<T>::show() const {
    if (size == 0) std::cout << "List is empty" << std::endl;
    else output(head);
}

template<typename T>
T &LinkedList<T>::operator[](int index) const {
    if (index < size && index >= 0) {
        Point <T> *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index)
                return temp->num;
            temp = temp->next;
            ++count;
        }
    }
    std::cout << std::endl << std::endl;
    perror("Indexing error");
    std::cout << std::endl;
    exit(1);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList <T> &list) {
    for (int i = 0; i < list.size; i++) {
        this->push(list[i]);
    }
}

template<typename T>
LinkedList <T> &LinkedList<T>::operator=(const LinkedList <T> &list) {

    int size_temp = size;

    for (int i = 0; i < size_temp; i++) {
        this->pop();
    }

    for (int i = 0; i < list.size; i++) {
        this->push(list[i]);
    }
    return *this;
}

template<typename T>
LinkedList <T> LinkedList<T>::operator*(LinkedList <T> &list) {
    T nulik;
    nulik = 0;
    LinkedList <T> new_list;
    for (int i = 0; i < min((int) size, list()); i++) {
        new_list.push((*this)[i] * list[i]);
    }
    for (int i = 0; i < max((int) size, list()) - min((int) size, list()); i++) {
        new_list.push(nulik);
    }
    return new_list;
}