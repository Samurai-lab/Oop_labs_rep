#include <iostream>
#include "LinkedList.h"

int main() {
    setlocale(LC_ALL, "Rus");
    LinkedList linkedList;
    for (int i = 1; i <= 12; i += 2) linkedList.push(i);

    std::cout << "LinkedList's elements: " << linkedList << std::endl;
    std::cout << "List's size: " << linkedList() << std::endl;
    std::cout << "List's element [1] : " << linkedList[1] << std::endl;

    Iterator iterator = linkedList.first();
    std::cout << "List's elements from iterator: " << linkedList[1] << std::endl;
    for (; iterator != linkedList.last(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    std::cout << std::endl;

    linkedList.pop();
    iterator = linkedList.first();

    std::cout << "Element iterator += 5" << std::endl;
    iterator = iterator + 5;
    std::cout << *iterator << std::endl;

    LinkedList linkedListTwo;
    for (int i = 4; i <= 12; i += 2) linkedListTwo.push(i);

    std::cout << "LinkedList's elements: " << linkedList << std::endl;
    std::cout << "LinkedListTwo's elements: " << linkedListTwo << std::endl;

    std::cout << "LinkedList * LinkedListTwo " << linkedListTwo << std::endl;

    LinkedList linkedListThree = linkedList * linkedListTwo;

    std::cout<< "LinkedList * LinkedListTwo = " << linkedListThree;


    return 0;
}
