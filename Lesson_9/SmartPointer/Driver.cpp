#include "stdafx.h"

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{
}
void Driver::BuyCar(const std::string& color)
{
    car_ = factory_->BuildCar(color);
}
void Driver::Go()
{
    if (car_ != nullptr)
    {
        std::cout << name_ << " I have a car ";
        car_->Drive();
    }
    else
    {
        std::cout << name_ << ": I'll go on foot\n";
    }
}
void Driver::BuyUsedCar(Driver* d)
{
     car_ = d->CellCar();
}
std::unique_ptr<Car> Driver::CellCar()
{
    return std::unique_ptr<Car> (car_.release());
}