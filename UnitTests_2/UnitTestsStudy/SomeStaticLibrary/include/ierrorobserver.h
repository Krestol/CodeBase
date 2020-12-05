#ifndef IERROROBSERVER_H
#define IERROROBSERVER_H
#include <string>

class IErrorObserver
{
public:
    virtual ~IErrorObserver() {}
    virtual void OnError(const std::string& error) const = 0;
};

#endif // IERROROBSERVER_H
