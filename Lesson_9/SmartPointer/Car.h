#pragma once
class Car
{
public:
    Car(const std::string& color);
    ~Car();

    void Drive();

private:
    std::string color_;
};