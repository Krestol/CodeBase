#ifndef IWRITER_H
#define IWRITER_H
#include <string>
#include <vector>

class IWriter
{
public:
    virtual ~IWriter() {}
    virtual void Write(const std::vector<std::string>& data) const = 0;
};


#endif // IWRITER_H
