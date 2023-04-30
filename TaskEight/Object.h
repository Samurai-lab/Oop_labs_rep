#ifndef TASKEIGHT_OBJECT_H
#define TASKEIGHT_OBJECT_H

#include <iostream>
#include "Event.h"

class Object {
public:
    Object();

    ~Object();

    virtual void Show() = 0;

    virtual void HandleEvent(const TEvent &e) = 0;

    virtual int AvgAge() = 0;
};


#endif
