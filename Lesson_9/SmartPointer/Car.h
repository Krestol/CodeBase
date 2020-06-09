#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <Windows.h>
#include <thread>
#include <ctime>

class Car
{
public:
    Car(const std::string& color);
    ~Car();

    void Drive();

private:
    std::string color_;
};
