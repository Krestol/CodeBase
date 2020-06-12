#pragma once

class Car
{
public:
    Car(const std::string& color);
    ~Car();

    void BecomeBY();
    void Drive();

private:
    std::string color_;
    std::string status_;
};
