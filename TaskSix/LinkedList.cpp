#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
    top = nullptr;
}

LinkedList::LinkedList(size_t s, int k) {
    size = s;
    if (size != 0) {

        Point *obj = new Point;
        obj->num = k;
        head = obj;

        Point *temp = head;
        for (int i = size - 1; i != 0; i--) {
            obj = new Point;
            temp->next = obj;
            obj->num = k;
            temp = obj;
        }

        top = obj;
        beg.elem = head;
        end.elem = top;
    }
}

LinkedList::LinkedList(const LinkedList &list) {
    for (int i = 0; i < list.size; i++) {
        this->push(list[i]);
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        pop();
    }
}

void LinkedList::output(Point *obj) const {
    std::cout << obj->num << " ";
    if (obj == top) return;
    output(obj->next);
}

void LinkedList::show() const {
    if (size == 0) std::cout << "Ваш лист пуст!" << std::endl;
    else output(head);
}

int &LinkedList::operator[](int index) const {
    if (index < size && index >= 0) {
        Point *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index)
                return temp->num;
            temp = temp->next;
            ++count;
        }
    }
    std::cout << std::endl << std::endl;
    perror("Ошибка");
    std::cout << std::endl;
    exit(1);
}

LinkedList &LinkedList::operator=(const LinkedList &list) {
    int size_temp = size;

    for (int i = 0; i < size_temp; i++) {
        this->pop();
    }

    for (int i = 0; i < list.size; i++) {
        this->push(list[i]);
    }
    return *this;
}

LinkedList LinkedList::operator*(LinkedList &list) {
    LinkedList new_list(std::max((int) size, list()),
                        0);

    for (int i = 0; i < std::min((int) size, list()); i++) {
        new_list[i] = (*this)[i] * list[i];
    }
    return new_list;
}

void LinkedList::push(int k) {
    if (size == 0) {
        head = new Point;
        head->num = k;
        top = head;
        beg.elem = head;
    } else {
        Point *obj = new Point;
        top->next = obj;
        obj->num = k;
        top = obj;
    }

    end.elem = top;
    size++;
}

int LinkedList::pop() {
    int k = head->num;
    Point *temp = head;
    head = head->next;
    size--;
    delete temp;
    beg.elem = head;
    return k;
}

std::istream &operator>>(std::istream &in, LinkedList &list) {
    int k;
    in >> k;
    list.push(k);
    return in;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
    list.show();
    return out;
}

int LinkedList::operator()() {
    return size;
}

Iterator LinkedList::first() {
    return beg;
}

Iterator LinkedList::last() {
    return end;
}
