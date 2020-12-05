#include "person.h"

namespace
{
    enum stage : int
    {
        beforeFirstNameStage = 0,
        firstNameStage,
        secondNameStage,
        patronymicStage
    };
}

Person::Person(const std::string& str)
{
    stage indecator = beforeFirstNameStage;
    for (const auto& ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            indecator = static_cast<stage>(indecator + 1);
        }

        if (!isalpha(ch))
        {
            continue;
        }

        if (indecator == firstNameStage)
        {
            firstName += ch;
        }
        else if (indecator == secondNameStage)
        {
            secondName += ch;
        }
        else if (indecator == patronymicStage)
        {
            patronymic += ch;
        }
    }
}

std::string Person::ToString()
{
    return secondName.substr(0, 1)
        + "." + patronymic.substr(0, 1)
        + ". " + firstName;
}
