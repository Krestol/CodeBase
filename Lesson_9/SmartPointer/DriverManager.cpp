
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
{
}
void DriverManager::GetOneDriver(std::unique_ptr<Driver> CurrentDriver)
{
    DriversOwnedByManagers_.push_back(std::move(CurrentDriver));
}
void DriverManager::ThreaFunctionManager(int DriverNumber)
{
    
    int i = 4;
    while (i)
    {
        DriversOwnedByManagers_[DriverNumber]->cleverGo();
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        i--;
    }
}
void DriverManager::startThread()
{
    std::vector<std::thread> threads;
    for (unsigned currentDriverNumber = 0; currentDriverNumber < DriversOwnedByManagers_.size(); ++currentDriverNumber)
    {
        threads.push_back(std::thread(&DriverManager::ThreaFunctionManager, this, currentDriverNumber));
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    for (auto& t : threads)
    {
        t.join();
    }
}
void DriverManager::setFieldManagerToOnedDrivers(int k)
{
    DriversOwnedByManagers_[k]->rememberMyManager(this);
}
std::mutex mtx;
void DriverManager::GetPtrDriverWithCar(Driver* NewDriverWhitCar)
{
    std::lock_guard<std::mutex> locked(mtx);
    PtrDriversWithCar_.push_back(NewDriverWhitCar);
}
Driver* DriverManager::GivePtrDriverWithCar()
{
    std::lock_guard<std::mutex> locked(mtx);
    if (PtrDriversWithCar_.empty())
    {
        throw std::runtime_error ("...tried to buy a used car but they aren’t\n");
    }
    Driver* p_DriverWithCar = PtrDriversWithCar_.back();
    PtrDriversWithCar_.pop_back();
    return p_DriverWithCar;
}



