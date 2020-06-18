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
    , name_(name),
    myManager_(nullptr)
{}
void Driver::BuyCar(const std::string& color)
{
    car_ = factory_->BuildCar(color);
}
void Driver::Go()
{
    //mtx.lock();   //it was like this before the cleverGo();
    if (car_ != nullptr)
    {
            std::cout << name_ << " I have a car ";
            car_->Drive();
    }
    else
    {
            std::cout << name_ << ": I'll go on foot\n";
    }
    ///mtx.unlock();    //it was like this before the cleverGo();
}
void Driver::BuyUsedCar(Driver* d)
{
     car_ = d->SellCar();
}
std::unique_ptr<Car> Driver::SellCar()
{
    return std::make_unique<Car> (car_.release());
}
void Driver::ShowDriverInfo()
{
    std::cout<< name_<<std::endl;// << "car adress: " << this->car_ << std::endl;
}
bool Driver::HaveCar()
{
    if (car_ == nullptr)
    {
        return false; // no car
    }
    else
    {
        return true; //have car
    }
}
std::vector<int> Driver::canIbuyUsedCar()
{
    std::vector <int> temp = myManager_->isDriverToBuyCarFromAllManagers_m(mySchool_);
    return temp;
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
void Driver::cleverGo()
{
    int i = 100;
    while (i)
    {
        mtx.lock();
        //std::lock_guard<std::mutex>lock(mtx);
        this->Go();
        bool probaPera = this->HaveCar();
        if (!this->HaveCar())
        {
            std::vector<int > temp = this->canIbuyUsedCar();
            int y = temp.empty();
            if (temp.empty())//If temp.empty==1 than meens temp is empty 
                this->BuyCar("red");//if haven't drivers with car buy new car from factory
            else
            {
                //car_ = std::move(mySchool_->giveUsedCarFromDriversOwnedManagers(temp));
                std::cout << std::endl << "Get Ready!" << std::endl;
                //this->BuyUsedCar();
                //line below doesn't work
                //car_ = mySchool_->giveUsedCarFromDriversOwnedManagers(temp);//you should work with metods not fields
                std::cout << "It works! - to buy car!";
            }
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        i--;
    }
}