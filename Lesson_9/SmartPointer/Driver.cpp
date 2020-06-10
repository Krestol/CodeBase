#include "stdafx.h"
#include "Driver.h"

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{
    whatCar_ = WhatCar::NoCar;
    work_ = false;
    std::unique_ptr<Car> carToSale_ = nullptr;
    std::unique_ptr<Car> car_ = nullptr;
    Car* tmp = &*car_;
}

std::string Driver::GetName()
{
    return name_;
}

void Driver::BuyCar(const std::string& color)
{
    if (car_ != nullptr)
    {
        carToSale_ = std::move(car_);
    }
    car_ = factory_->BuildCar(color);
}

WhatCar* Driver::GetWhatCar()
{
    return &whatCar_;
}

bool Driver::GetWorkStatus()
{
    return work_;
}

std::unique_ptr<Car> Driver::SellCar()
{
    return std::unique_ptr<Car>(carToSale_.release());
}

void Driver::BuyUsedCar(std::shared_ptr<Driver> driver)
{
    if (driver != NULL)
    {
        car_ = std::move(driver->SellCar());
    }
}

void Driver::Start()
{
    uint32_t timeToByBY = 5000;
    uint32_t timeToByNew = 10000;
    work_ = true;
    uint32_t start = clock();
    while (true)
    {
        uint32_t end = clock();
        uint32_t curTimeWork = end - start;
        if ((curTimeWork) > timeToByBY && (curTimeWork) < timeToByNew && whatCar_ == WhatCar::NoCar)
        {
            std::shared_ptr<Driver> driver;
            if (driver != NULL)
            {
                this->BuyUsedCar(driver);
                whatCar_ = WhatCar::BY;
            }
        }
        else if ((curTimeWork) > timeToByNew && whatCar_ != WhatCar::New)
        {
            this->BuyCar("green");
            whatCar_ = WhatCar::New;
        }
        if (car_ != nullptr)
        {
            std::cout << name_ << " I have a car ";
            car_->Drive();
        }
        else
        {
            std::cout << name_ << ": I'll go on foot\n";
        }
        Sleep(1000);
    }
}
