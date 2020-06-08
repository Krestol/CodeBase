#pragma once
#include <iostream>
#include <string>
#include <memory>

class Car
{
public:
    Car(const std::string& color);
    ~Car();

    void Drive();

private:
    std::string color_;
};
