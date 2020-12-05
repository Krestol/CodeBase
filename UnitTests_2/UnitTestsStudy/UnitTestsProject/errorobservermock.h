#ifndef ERROROBSERVERMOCK_H
#define ERROROBSERVERMOCK_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/ierrorobserver.h"
#include <string>
class ErrorObserverMock : public IErrorObserver
{
public:
    MOCK_CONST_METHOD1(OnError, void(const std::string&));
};
#endif // ERROROBSERVERMOCK_H
