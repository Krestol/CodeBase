#ifndef IREADER_H
#define IREADER_H
#include <string>

class IReader
{
public:
    virtual ~IReader() {}

    virtual std::string Read() const = 0;
};

#endif // IREADER_H
