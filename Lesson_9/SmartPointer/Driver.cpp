#include "stdafx.h"
#include "Driver.h"
#include "DriverManager.h"

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory, std::shared_ptr<class DriverManager> manager, uint32_t id, std::shared_ptr<std::mutex> mut)
    : factory_(factory)
    , name_(name)
    , manager_(manager)
    , id_(id)
    , whatCar_(WhatCar::NoCar)
    , mutex_(mut)
{
    std::unique_ptr<Car> carToSale_ = nullptr;
    std::unique_ptr<Car> car_ = nullptr;
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

std::unique_ptr<Car> Driver::SellCar()
{
    return std::unique_ptr<Car>(carToSale_.release());
}

void Driver::BuyUsedCar(std::shared_ptr<Driver> driver)
{
    if (driver != NULL)
    {
        car_ = std::move(driver->SellCar());
        car_->BecomeBY();
    }
}

void Driver::Start()
{
    uint32_t timeToByBY = 5000;
    uint32_t timeToByNew = 10000;
    uint32_t timeToByNew2 = 15000;
    uint32_t start = clock();
    COORD coordinates;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = 0;
    while (true)
    {
        uint32_t end = clock();
        uint32_t curTimeWork = end - start;
        if ((curTimeWork) > timeToByBY && (curTimeWork) < timeToByNew && whatCar_ == WhatCar::NoCar)
        {
            std::shared_ptr<Driver> driver = manager_->WhoIsReadyToSale();
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
        else if ((curTimeWork) > timeToByNew2 && whatCar_ == WhatCar::New)
        {
            this->BuyCar("green");
        }
        if (car_ != nullptr)
        {
            mutex_->lock();
            coordinates.Y = id_;
            SetConsoleCursorPosition(hConsole, coordinates);
            std::cout << name_ << " I have a car ";
            car_->Drive();
            mutex_->unlock();
        }
        else
        {
            mutex_->lock();
            coordinates.Y = id_;
            SetConsoleCursorPosition(hConsole, coordinates);
            std::cout << name_ << ": I'll go on foot\n";
            mutex_->unlock();
        }
        Sleep(1000);
    }
}
