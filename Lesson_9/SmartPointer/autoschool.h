#pragma once
#include "DriverManager.h"
#include "Driver.h"

class autoschool
{
public:
    autoschool(int numbersOfDrivers, int numberOfDriversInOwnedByOneManager, std::string name, std::shared_ptr<CarFactory>& factory);
    void threadfuct();
    const void getName(const int& i);
private:
    std::string name_;
    int numbersOfDrivers_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversInAutoschool_;
    DriverManager Manager_;
};