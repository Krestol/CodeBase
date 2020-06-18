#pragma once
#include "Driver.h"
class autoschool;

class DriverManager
{
public:
    DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory);
    void GetOneDriver(std::unique_ptr<Driver> CurrentDriver);
    void ShowOneDriver();
    void startThread();
    void ThreaFunctionManager();
    std::vector <int> isDriverToBuyCarFromAllManagers_m(autoschool* currentSchool);
    int isDriverToBuyCarFromMe_m();
    void setFiledManagerToOnedDrivers(int k);
    std::unique_ptr<Car> tellDriverTosellCar(int index);
private:
    std::string nameManager_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversOwnedByManagers_;
    std::unique_ptr<Driver> OneDriver_;//artefact
    static int NumberOfManagers;
};
