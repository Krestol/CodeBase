#pragma once
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "DriverManager.h"
class autoschool
{
public:
    autoschool(int numbersOfDrivers, std::string name, std::shared_ptr<CarFactory>& factory);
    void threadfuct();
    void showDrivers();
    void showDriversofManagers();
    void getName(const int& i);
private:
    int numbersOfDrivers_;
    std::string name_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversInAutoschool_;
    std::vector<std::unique_ptr<DriverManager>> DriverManagers_;
};