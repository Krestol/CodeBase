#pragma once
#include "stdafx.h"
#include "DriverManager.h"
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "autoschool.h"


DriverManager::DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory)
    : factory_(factory)
    , nameManager_(nameManager)
    , OneDriver_(nullptr)
{
  
}
void DriverManager::GetOneDriver(std::unique_ptr<Driver> CurrentDriver)
{
    //OneDriver_ = std::unique_ptr<Driver>(std::move(CurrentDriver));
    DriversOwnedByManagers_.push_back(std::move(CurrentDriver));
    //OneDriver_=std::move(CurrentDriver);
}
void DriverManager::ShowOneDriver()
{
    //OneDriver_->Go();
}
void DriverManager::ThreaFunctionManager()
{
       //OneDriver_->Go();
        DriversOwnedByManagers_[0]->Go();
        DriversOwnedByManagers_[1]->Go();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void DriverManager::startThread()
{
    //failed to implement through functor and this line stil doesn't work:
    //std::thread th_(&DriverManager::ThreaFunctionManager,this->OneDriver_.get());
    
    std::thread th(&DriverManager::ThreaFunctionManager, this);
    
    //do not use "th.join()", otherwise we will stop the main thread...
    //..and there will be no parallel execution of threads
    //th.join();
    std::cout << "bye!"<<std::endl;
    th.detach();
    //th.join();
}




