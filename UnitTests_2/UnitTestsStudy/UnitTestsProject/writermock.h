#ifndef WRITERMOCK_H
#define WRITERMOCK_H
#include <gtest/gtest.h>
#include "include/iwriter.h"
#include <gmock/gmock.h>
#include <vector>
#include <string>

class WriterMock : public IWriter
{
public:
    MOCK_CONST_METHOD1(Write, void(const std::vector<std::string>&));
};
#endif // WRITERMOCK_H
