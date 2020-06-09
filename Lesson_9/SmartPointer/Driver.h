#pragma once
#include "CarFactory.h"

enum class WhatCar
{
    Error = 0,
    NoCar = 1,
    BY = 2,
    New = 3
};

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);

    std::shared_ptr<Car> GetCar();
    std::string GetName();
    void BuyCar(const std::string& color);
    WhatCar* GetWhatCar();

    // SellCar
    // BuyUsedCar

    void Start();

private:
    std::shared_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    std::unique_ptr<std::thread> thread_;
    WhatCar whatCar_;
    bool work_;
};