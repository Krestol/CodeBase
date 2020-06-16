#pragma once
#include "DriverManager.h"
#include "Driver.h"

class autoschool
{
public:
    autoschool(int numbersOfDrivers, std::string name, std::shared_ptr<CarFactory>& factory);
    void threadfuct();
    void showDrivers();
    void showDriversofManagers();
    const void getName(const int& i);
 private:
    int numbersOfDrivers_;
    int numberOfManagers_;
    std::string name_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversInAutoschool_;
    std::vector<DriverManager> DriverManagers_;
};