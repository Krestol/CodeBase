#pragma once
#include "Driver.h"


class DriverManager
{
public:
    DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory);
    void GetOneDriver(std::unique_ptr<Driver> CurrentDriver);
    void ShowOneDriver();
    void startThread();
    void ThreaFunctionManager();
    //void AdviceDriverToBuyCar(autoschool& CurrentSchool);
private:
    std::string nameManager_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversOwnedByManagers_;
    std::unique_ptr<Driver> OneDriver_;
};
