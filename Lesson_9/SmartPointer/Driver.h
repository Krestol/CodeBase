#pragma once
#include "Car.h"
#include "CarFactory.h"

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    void BuyCar(const std::string& color);
    void BuyUsedCar(Driver* d);
    std::unique_ptr<Car> SellCar();
    void Go();
    void ShowDriverInfo();
private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
};

