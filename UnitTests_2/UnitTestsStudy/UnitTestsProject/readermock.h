#ifndef READERMOCK_H
#define READERMOCK_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "include/ireader.h"
#include <string>

class ReaderMock : public IReader
{
public:
    MOCK_CONST_METHOD0(Read, std::string());
};

#endif // READERMOCK_H
