#ifndef PERSON_H
#define PERSON_H
#include <string>

struct Person
{
    std::string firstName;
    std::string secondName;
    std::string patronymic;

    Person(const std::string& str);
    std::string ToString();
};

#endif // PERSON_H
