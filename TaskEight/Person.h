#ifndef TASKEIGHT_PERSON_H
#define TASKEIGHT_PERSON_H

#include "Object.h"

class Person : public Object {
protected:
    std::string name;
    int age;

    friend std::istream &operator>>(std::istream &in, Person &p);

    friend std::ostream &operator<<(std::ostream &out, const Person &p);

public:
    [[maybe_unused]] void set_name([[maybe_unused]] std::string name);

    [[maybe_unused]] void set_age(int age);

    [[maybe_unused]] std::string get_name();

    [[maybe_unused]] [[nodiscard]] int get_age() const;

    Person();

    [[maybe_unused]] Person(std::string name, int age);

    Person(const Person &p);

    ~Person();

    void Show() override;

    void HandleEvent(const TEvent &e) override;

    int AvgAge() override { return age; }
};


#endif
