#include "stdafx.h"
#include "Car.h"
#include "CarFactory.h"
#include "Driver.h"

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
     car_ = d->SellCar();
}
std::unique_ptr<Car> Driver::SellCar()
{
    return std::unique_ptr<Car> (car_.release());
}
void Driver::ShowDriverInfo()
{
    std::cout<< name_<<std::endl;// << "car adress: " << this->car_ << std::endl;
}

