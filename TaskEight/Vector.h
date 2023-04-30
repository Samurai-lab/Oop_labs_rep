#ifndef TASKEIGHT_VECTOR_H
#define TASKEIGHT_VECTOR_H

#include <ostream>
#include "Object.h"
#include "Event.h"
#include "Person.h"
#include "Student.h"

class Vector {
public:
    Vector();

    [[maybe_unused]] explicit Vector(int);

    ~Vector();

    void Add(Object *);

    void Add();

    void Del();

    void Show() const;

    int operator()() const;

    void AvgAge();

    friend std::ostream &operator<<(std::ostream &out, const Vector &v);

    virtual void HandleEvent(const TEvent &e);

protected:
    Object **beg;
    int size;
    int cur;
};


#endif