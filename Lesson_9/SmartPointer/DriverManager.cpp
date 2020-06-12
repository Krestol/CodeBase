#include "stdafx.h"
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "DriverManager.h"

DriverManager::DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory>& factory)
    : factory_(factory)
    , nameManager_(nameManager), ManagerDrivers_(0)
    , OneDriver_(nullptr)
{
}
void DriverManager::GetOneDriver(std::unique_ptr<Driver> CurrentDriver)
{
    //OneDriver_ = std::unique_ptr<Driver>(std::move(CurrentDriver));
    OneDriver_=std::move(CurrentDriver);
}
void DriverManager::ShowOneDriver()
{
    std::cout << "OneDriver_="<< OneDriver_;
    OneDriver_->Go();
}
void DriverManager::ThreaFunctionManager()
{
    
    int i = 100;
    while (i)
    {
        OneDriver_->Go();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        i--;
    }
}
void DriverManager::startThread()
{
    std::cout << "go!           ";//it works!
    //failed to implement through functor and this line stil doesn't work:
    std::thread th_(&ThreaFunctionManager,OneDriver_);
}
