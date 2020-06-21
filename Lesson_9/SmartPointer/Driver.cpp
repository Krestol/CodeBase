#pragma once
#include "stdafx.h"
#include "Driver.h"
#include "DriverManager.h"
#include "Car.h"
#include "CarFactory.h"
#include "autoschool.h"

std::mutex mtx;
Driver::Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , name_(name)
{}
void Driver::BuyCar(const std::string& color)
{
    car_ = factory_->BuildCar(color);
    std::cout << "I bought a new car\n";
    myManager_->GetPtrDriverWithCar(this);
}

void Driver::cleverGo()
{
    //int whatToDo = rand() % 3 + 1;//dont work with threads
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 2);
    int random_number = distrib(gen);
    std::lock_guard<std::mutex> locked(mtx);
    if (car_ != nullptr)    //if driver has car - drive
    {
        std::cout << name_ << " have a car";
        car_->Drive();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    else
    {
        std::cout << name_ << "'ll go on foot.... BUT....";
        switch (random_number)
        {
            case 1: //buy a new car
            {
                this->BuyCar(this->SetCarColor());
                this->Go();
                break;
            }
            case 2://try to buy used car
            {
                try
                {
                    Driver* p_driverWithCar = myManager_->GivePtrDriverWithCar();
                    this->BuyUsedCar(p_driverWithCar);
                    //this->BuyUsedCar(myManager_->GivePtrDriverWithCar()); //same as the two lines above
                }
                catch (const std::runtime_error& e)
                {
                    std::cout << e.what();
                }
                break;
            }

        }
    }
}
void Driver::Go()//already dont use in prog
{
    //std::lock_guard<std::mutex> locked(mtx);
    if (car_ != nullptr)
    {
            std::cout << name_ << " have a car";
            car_->Drive();
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    else
    {
            std::cout << name_ << " : I'll go on foot\n";
    }
}
void Driver::BuyUsedCar(Driver* d)
{
     car_ = d->SellCar();
     std::cout << "I bought a used car\n";
     myManager_->GetPtrDriverWithCar(this);
}
std::unique_ptr<Car> Driver::SellCar()
{
    return std::unique_ptr<Car> (car_.release());
}
void Driver::rememberMyManager(DriverManager* myM)
{
   this->myManager_ = myM;
}
DriverManager* Driver::sayNameMyManager()
{
    return this->myManager_;
}
void Driver::rememberMySchool(autoschool* myS)
{
    this->mySchool_ = myS;
}
autoschool* Driver::sayNameMySchool()
{
    return this->mySchool_;
}
Driver* Driver::giveDriverToBuyCar()
{
    return myManager_->GivePtrDriverWithCar();
}
std::string Driver::SetCarColor()
{
    if (name_ == "Sergey")
        return "green";
    else if (name_ == "Ivan")
        return "blue";
    else if (name_ == "Sasha")
        return "black";
    else if (name_ == "Masha")
        return "red";
    else return "silver";
}