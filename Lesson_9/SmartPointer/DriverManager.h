#pragma once
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
class DriverManager
{
public:
    DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory);
    void GetOneDriver(std::unique_ptr<Driver> CurrentDriver);
    void ShowOneDriver();
    void startThread();
    void ThreaFunctionManager();
private:
    std::string nameManager_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> ManagerDrivers_;
    std::unique_ptr<Driver> OneDriver_;
};

