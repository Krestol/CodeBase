#pragma once
#include "stdafx.h"
#include "autoschool.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "DriverManager.h"



autoschool::autoschool(int numberOfManagers, int numberOfDriversInOwnedByOneManager, std::string name, std::shared_ptr<CarFactory>& factory)
    :factory_(factory), name_(name), numbersOfDrivers_(numberOfManagers*2), numberOfManagers_(numberOfManagers),
    numberOfDriversInOwnedByOneManager_(numberOfDriversInOwnedByOneManager) // dont use for now...
{
    DriversInAutoschool_.clear();
}
    const void autoschool::getName(const int& i)
    {
        if (i == 0)
            name_ = "1 - one";
        else if (i == 1)
            name_ = "2 - two";
        else if (i == 2)
            name_ = "3 - three";
        else if (i == 4)
            name_ = "4 - four";
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
        DriversInAutoschool_[i]->rememberMySchool(this);
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
            DriverManagers_[i].setFiledManagerToOnedDrivers(0);
            DriverManagers_[i].GetOneDriver(std::move(std::unique_ptr<Driver>(DriversInAutoschool_[j].release())));
            DriverManagers_[i].setFiledManagerToOnedDrivers(1);
            j++;
    }
    //4)Everybody DriverManager start Go for his two Drivers in thread
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
std::vector <int> autoschool::isDriverToBuy_as()
{
    std::vector <int> tempManagerAndDriver; // first number - Manager Number, second number - Driver number in "DriversOwnedByManagers_"
    int i;
    tempManagerAndDriver.clear();
    for (i=0;i<numberOfManagers_;++i)
    {
        
        if (DriverManagers_[i].isDriverToBuyCarFromMe_m() == 1)
        {
            tempManagerAndDriver.push_back(i);//number of Manager
            tempManagerAndDriver.push_back(0);//number of Driver owned by Manager
            return tempManagerAndDriver;
        }
        if (DriverManagers_[i].isDriverToBuyCarFromMe_m() == 2)
        {
            tempManagerAndDriver.push_back(i);//number of Manager
            tempManagerAndDriver.push_back(1);//number of Driver owned by Manager
            return tempManagerAndDriver;
        }
    }
    bool h = tempManagerAndDriver.empty();//артефакт
    return tempManagerAndDriver;
}

std::unique_ptr<Car> autoschool::giveUsedCarFromDriversOwnedManagers(std::vector <int> CoordinatesOfDriverHasCar)
{
    //this->DriverManagers_[CoordinatesOfDriverHasCar[0]].tellDriverTosellCar(CoordinatesOfDriverHasCar[1]);
    //return std::move(std::make_unique<Driver>("Ivan", factory_));
    //return std::make_unique<Car>(this->DriverManagers_[CoordinatesOfDriverHasCar[0]].tellDriverTosellCar(CoordinatesOfDriverHasCar[1]).release());
    return this->DriverManagers_[CoordinatesOfDriverHasCar[0]].tellDriverTosellCar(CoordinatesOfDriverHasCar[1]);
}
