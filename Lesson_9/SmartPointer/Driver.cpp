#include "Driver.h"

void Go(Driver* driver)
{
    
}

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{
    whatCar_ = WhatCar::NoCar;
    work_ = false;
    readyToSale_ = false;
}

std::string Driver::GetName()
{
    return name_;
}

void Driver::BuyCar(const std::string& color)
{
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

bool Driver::IfReady()
{
    return readyToSale_;
}

void Driver::ReadyToSell()
{
    carToSale_ = std::move(car_);

}

std::unique_ptr<Car> Driver::SellCar()
{
    return std::unique_ptr<Car>(carToSale_.release());
    BuyCar("green");
}

void Driver::BuyUsedCar(std::shared_ptr<Driver> driver)
{
    if (driver != nullptr)
    {
        car_ = std::move(driver->SellCar());
    }
}

void Driver::Start()
{
    work_ = true;
    unsigned int start = clock();
    while (true)
    {
        unsigned int end = clock();
        if ((end - start) > 5000 && whatCar_ == WhatCar::NoCar)
        {
            this->BuyCar("(b/y)red");
            whatCar_ = WhatCar::BY;
        }
        else if ((end - start) > 10000 && whatCar_ == WhatCar::BY)
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
