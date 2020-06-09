#include "Driver.h"

void Go(Driver* driver)
{
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
    }
}

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{
    work_ = false;
}

Car* Driver::GetCar()
{
    return &*(car_);
}

std::string Driver::GetName()
{
    return name_;
}

std::thread* Driver::GetThread()
{
    return *thread_;
}

void Driver::BuyCar(const std::string& color)
{
    car_ = factory_->BuildCar(color);
}

void Driver::Start()
{
    if (!work_)
    {
        thread_ = std::make_unique<std::thread*>(new std::thread(Go, this));
        work_ = true;
    }
}
