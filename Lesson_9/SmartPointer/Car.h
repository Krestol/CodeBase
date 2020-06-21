#pragma once


class Car
{
public:
    Car(const std::string& color);
    ~Car();
    void Drive();
    void GetCarColor();
private:
    std::string color_;
};

