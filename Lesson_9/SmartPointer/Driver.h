#pragma once

#include "CarFactory.h"
#include "Car.h"
#include "autoschool.h"


class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    void BuyCar(const std::string& color);
    void BuyUsedCar(Driver* d);
    std::unique_ptr<Car> SellCar();
    void Go();
    void ShowDriverInfo();
    bool HaveCar();
    int isDriverToBuy(autoschool& currentSchool);
private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    
};

