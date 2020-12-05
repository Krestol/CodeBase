#include "utils.h"
#include <sstream>
#include <string>
#include <vector>
#include "person.h"

std::vector<std::string> Parse(const std::string& input)
{
    std::istringstream ss(input);
    std::string token;

    std::vector<std::string> result;
    while(std::getline(ss, token, ';')) {
        result.push_back(Format(token));
    }
    return result;
}

std::string Format(const std::string& str)
{
    if (str.empty())
    {
        return "";
    }
    return Person(str).ToString();
}
