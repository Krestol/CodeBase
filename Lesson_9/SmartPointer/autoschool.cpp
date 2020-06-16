#pragma once
#include "stdafx.h"
#include "autoschool.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "DriverManager.h"



autoschool::autoschool(int numberOfManagers, std::string name, std::shared_ptr<CarFactory>& factory)
    :factory_(factory), name_(name), numbersOfDrivers_(numberOfManagers*2), numberOfManagers_(numberOfManagers)
{
    DriversInAutoschool_.clear();
}
    const void autoschool::getName(const int& i)
    {
        if (i == 3)
            name_ = "Brandon Lee";
        else if (i == 2)
            name_ = "Bruce Lee";
        else if (i == 1)
            name_ = "Jackie Chan";
        else name_ = "Arnold Schwarzenegger";
    }
void autoschool::threadfuct()
{
    //1) create Drivers:
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        
        //one way:
        //std::unique_ptr < Driver> currentDriver(new Driver("Ivan", factory_));
        //DriversInAutoschool_.push_back(std::move(currentDriver));
        //secondway: same but less code
        getName(i);
        DriversInAutoschool_.push_back(std::make_unique<Driver>(name_, factory_));
    }
    //2) Create Managers - inside DriverSchool(autoschool):
    for (int i = 0; i < numberOfManagers_; i++)
    {
        DriverManagers_.push_back(DriverManager("Stepan", factory_));
    }
    //3)Give Driver to Manager - one manager - two drivers:
    int j = 0;
    for (int i = 0; i < numberOfManagers_; i++)
    {        
        
            DriverManagers_[i].GetOneDriver(std::move(std::unique_ptr<Driver>(DriversInAutoschool_[j].release())));
            j++;
            DriverManagers_[i].GetOneDriver(std::move(std::unique_ptr<Driver>(DriversInAutoschool_[j].release())));
            j++;
            //можно ли было записать сразу несколько элементов типа unique_ptr? Типа вернуть их вектор. Наверное да.
    }
    //4)Everybody DriverManager start Go for his Driver (OneDriver) in thread
   for (int i = 0; i < numberOfManagers_; ++i)
    {
        DriverManagers_[i].startThread();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}
void autoschool::showDrivers()  //use before launch showDriversofManagers()
{
    for (int i = 0; i < numbersOfDrivers_; ++i)
    {
        DriversInAutoschool_[i]->Go();
    }
}
void autoschool::showDriversofManagers() // use before launch showDrivers()
{
    for (int i = 0; i < numberOfManagers_; i++)
    {
        std::cout << "Manager" << i + 1 << "has Driver: ";
        DriverManagers_[i].ShowOneDriver();
    }
}