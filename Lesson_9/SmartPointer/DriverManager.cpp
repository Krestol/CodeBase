#pragma once
#include "stdafx.h"
#include "DriverManager.h"
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "autoschool.h"

int DriverManager::NumberOfManagers = 0;

DriverManager::DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory)
    : factory_(factory)
    , nameManager_(nameManager)
    , OneDriver_(nullptr)
{
}
void DriverManager::GetOneDriver(std::unique_ptr<Driver> CurrentDriver)
{
    //OneDriver_ = std::unique_ptr<Driver>(std::move(CurrentDriver));
    DriversOwnedByManagers_.push_back(std::move(CurrentDriver));//
    //CurrentDriver->rememberMyManager(this);
    //OneDriver_=std::move(CurrentDriver);
}
void DriverManager::ShowOneDriver()
{
    //OneDriver_->Go();
}
void DriverManager::ThreaFunctionManager()//previous version
{
       //OneDriver_->Go();
        DriversOwnedByManagers_[0]->cleverGo();
        DriversOwnedByManagers_[1]->cleverGo();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void DriverManager::startThread()
{
    std::thread th(&DriverManager::ThreaFunctionManager, this);
     
    //do not use "th.join()", otherwise we will stop the main thread...
    //..and there will be no parallel execution of threads
    //th.join();
    std::cout << "now we here!"<<std::endl;
    th.detach();
    
}
std::vector <int> DriverManager::isDriverToBuyCarFromAllManagers_m(autoschool* currentSchool)
{
    std::vector <int> temp = currentSchool->isDriverToBuy_as();
    bool r=temp.empty();
    return temp;
}
int DriverManager::isDriverToBuyCarFromMe_m()
{
    bool g0 = DriversOwnedByManagers_[0]->HaveCar();
    bool g1 = DriversOwnedByManagers_[0]->HaveCar();
    if (DriversOwnedByManagers_[0]->HaveCar())
    {
        return 1;//first Driver
    }
    else if (DriversOwnedByManagers_[1]->HaveCar())
    {
        return 2;//second Driver 
    }
    else 
        return 0;//if drivers of Manager haven't car
}
void DriverManager::setFiledManagerToOnedDrivers(int k)
{
    DriversOwnedByManagers_[k]->rememberMyManager(this);
}
std::unique_ptr<Car> DriverManager::tellDriverTosellCar(int index)
{
    //return std::make_unique<Car>(DriversOwnedByManagers_[index]->SellCar());
    std::cout << "In DriverManager";
    //return std::make_unique<Car>(DriversOwnedByManagers_[index]->SellCar().release());
    return DriversOwnedByManagers_[index]->SellCar();
}




