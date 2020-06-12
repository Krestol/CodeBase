#pragma once
#include "CarFactory.h"

class DriverManager;

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
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory, std::shared_ptr<DriverManager> manager, uint32_t id, std::shared_ptr<std::mutex> mut);
    std::string GetName();
    void BuyCar(const std::string& color);
    WhatCar* GetWhatCar();
    std::unique_ptr<Car> SellCar();
    void BuyUsedCar(std::shared_ptr<Driver> driver);
    void Start();
private:
    std::unique_ptr<Car> car_;
    std::unique_ptr<Car> carToSale_;
    std::shared_ptr<CarFactory> factory_;
    std::shared_ptr<DriverManager> manager_;
    std::shared_ptr<std::mutex> mutex_;
    std::string name_;
    uint32_t id_;
    WhatCar whatCar_;
};