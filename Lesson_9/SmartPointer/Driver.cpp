#pragma once
#include "stdafx.h"
#include "Driver.h"
#include "Car.h"
#include "CarFactory.h"

#include "autoschool.h"


std::mutex mtx;

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
    mtx.lock();
    if (car_ != nullptr)
        {
            std::cout << name_ << " I have a car ";
            car_->Drive();
        }
        else
        {
            std::cout << name_ << ": I'll go on foot\n";
        }
    mtx.unlock();

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
bool Driver::HaveCar()
{
    if (car_ != nullptr)
    {
        return false; // no car
    }
    else
    {
        return true; //have car
    }
}
int Driver::isDriverToBuy(autoschool& currentSchool)
{
    currentSchool; // функция для поиска драйвера с машиной
    return 1;
}


