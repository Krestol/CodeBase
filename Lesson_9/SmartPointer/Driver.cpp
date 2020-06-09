#include "Driver.h"

void Go(Driver* driver)
{
    unsigned int start = clock();
    while (true)
    {
        if (driver->GetCar() != nullptr)
        {
            std::cout << driver->GetName() << " I have a car ";
            driver->GetCar()->Drive();
        }
        else
        {
            std::cout << driver->GetName() << ": I'll go on foot\n";
        }
        Sleep(1000);
        unsigned int end = clock();
        if ((end - start) > 5000 && *driver->GetWhatCar() == WhatCar::NoCar)
        {
            driver->BuyCar("(b/y)red");
            *driver->GetWhatCar() = WhatCar::BY;
        }
        else if ((end - start) > 10000 && *driver->GetWhatCar() == WhatCar::BY)
        {
            driver->BuyCar("green");
            *driver->GetWhatCar() = WhatCar::New;
        }
    }
}

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{
    whatCar_ = WhatCar::NoCar;
    work_ = false;
}

std::shared_ptr<Car> Driver::GetCar()
{
    return car_;
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

void Driver::Start()
{
    if (!work_)
    {
        thread_ = std::make_unique<std::thread>(Go, this);
        work_ = true;
    }
}
