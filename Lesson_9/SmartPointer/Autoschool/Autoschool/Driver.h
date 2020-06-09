#pragma once
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "stdafx.h"


class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    void BuyCar(const std::string& color);
    // SellCar
    // BuyUsedCar
    void Go();
private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
};