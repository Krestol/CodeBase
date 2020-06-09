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
    std::string GetName();
    void BuyCar(const std::string& color);
    WhatCar* GetWhatCar();
    bool GetWorkStatus();
    bool IfReady();
    void ReadyToSell();
    std::unique_ptr<Car> SellCar();
    void BuyUsedCar(std::shared_ptr<Driver> driver);
    void Start();
private:
    std::unique_ptr<Car> car_;
    std::unique_ptr<Car> carToSale_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    WhatCar whatCar_;
    bool work_;
    bool readyToSale_;
};