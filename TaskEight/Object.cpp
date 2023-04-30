#include "Object.h"

Object::~Object() {
    std::cout << "Called destructor of object from base class Object" << std::endl;
}

Object::Object() {
    std::cout << "Called constructor of object from base class Object" << std::endl;
}