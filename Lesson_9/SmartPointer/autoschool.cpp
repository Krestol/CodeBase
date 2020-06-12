#include "stdafx.h"
#include "autoschool.h"
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "DriverManager.h"

autoschool::autoschool(int numbersOfDrivers, std::string name, std::shared_ptr<CarFactory>& factory)
    :factory_(factory), name_(name), numbersOfDrivers_(numbersOfDrivers)
{
    DriversInAutoschool_.clear();
}
void autoschool::threadfuct()
{
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        //1) create Drivers:
        //one way:
        //std::unique_ptr < Driver> currentDriver(new Driver("Ivan", factory_));
        //DriversInAutoschool_.push_back(std::move(currentDriver));
        //secondway: same but less code
        DriversInAutoschool_.push_back(std::make_unique < Driver>(name_, factory_));
        //2) Create Managers - inside DriverSchool(autoschool):
        DriverManagers_.push_back(std::make_unique <DriverManager>("Stepan", factory_));
    }
    //3)Give Driver to Manager - one driver - one manager:
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        DriverManagers_[i]->GetOneDriver(std::move(std::unique_ptr<Driver>(DriversInAutoschool_[i].release())));
    }
    //4)Everybody DriverManager strat Go for his Driver (OneDriver) in thread
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        DriverManagers_[i]->startThread();
    }
}

void autoschool::showDrivers()  //use before launch showDriversofManagers()
{
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        DriversInAutoschool_[i]->Go();
    }
}
void autoschool::showDriversofManagers() // use before launch showDrivers()
{
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        std::cout << "Manager" << i + 1 << "has Driver: ";
        DriverManagers_[i]->ShowOneDriver();
    }
}