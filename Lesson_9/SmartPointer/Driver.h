#pragma once
#include "CarFactory.h"

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);

    Car* GetCar();
    std::string GetName();
    std::thread* GetThread();
    void BuyCar(const std::string& color);

    // SellCar
    // BuyUsedCar

    void Start();

private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    std::unique_ptr<std::thread*> thread_;
    bool work_;
};