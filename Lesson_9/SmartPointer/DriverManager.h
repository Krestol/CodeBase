#pragma once
#include "Driver.h"
class autoschool;

class DriverManager
{
public:
    DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory);
    void GetOneDriver(std::unique_ptr<Driver> CurrentDriver);
    void startThread();
    void ThreaFunctionManager(int DriverNumber);
    void setFieldManagerToOnedDrivers(int k);
    void GetPtrDriverWithCar(Driver* NewDriverWhitCar);
    Driver* GivePtrDriverWithCar();

private:
    std::string nameManager_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversOwnedByManagers_;
    static int NumberOfManagers;//TODO подумать что с этим решить
    std::vector<Driver*> PtrDriversWithCar_;
};
