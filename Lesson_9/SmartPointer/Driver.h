#pragma once
#include "stdafx.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    void BuyCar(const std::string& color);
    void BuyUsedCar(Driver* d);
    std::unique_ptr<Car> CellCar();
    void Go();
private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
};

