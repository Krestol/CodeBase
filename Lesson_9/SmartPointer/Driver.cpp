#include "stdafx.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"

Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
        : factory_(factory)
        , name_(name)
    {
    }

void Driver::BuyCar(const std::string& color)
    {
        car_ = factory_->BuildCar(color);
    }

    // SellCar
    // BuyUsedCar

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


