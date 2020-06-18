#pragma once
#include "DriverManager.h"
#include "Driver.h"

class autoschool
{
public:
    autoschool(int numbersOfDrivers, int numberOfDriversInOwnedByOneManager, std::string name, std::shared_ptr<CarFactory>& factory);
    void threadfuct();
    void showDrivers();
    void showDriversofManagers();
    const void getName(const int& i);
    std::vector <int> isDriverToBuy_as();
    std::unique_ptr<Car> giveUsedCarFromDriversOwnedManagers (std::vector <int> CoordinatesOfDriverHasCar);
 private:
    int numbersOfDrivers_;
    int numberOfManagers_;
    int numberOfDriversInOwnedByOneManager_;//пока не задействовал
    std::string name_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> DriversInAutoschool_;
    std::vector<DriverManager> DriverManagers_;
 };