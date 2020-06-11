#include "stdafx.h"
#include "autoschool.h"
#include "CarFactory.h"
#include "Driver.h"
#include "Car.h"
#include "DriverManager.h"

autoschool::autoschool(int numbersOfDrivers, std::string name, std::shared_ptr<CarFactory> factory)
    :factory_(factory), name_(name), numbersOfDrivers_(numbersOfDrivers)
{}

void autoschool::threadfuct()
{
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        //1) create Drivers:
        //one way:
        //std::unique_ptr < Driver> currentDriver(new Driver("Ivan", factory_));
        //DriversInAutoschool_.push_back(std::move(currentDriver));
        //secondway: same but less code
        DriversInAutoschool_.push_back(std::unique_ptr < Driver>(new Driver("Ivan", factory_)));
        //2) Create Managers:
        DriverManagers_.push_back(std::unique_ptr <DriverManager>(new DriverManager("Stepan", factory_)));
        //3)Give Driver to Manager:
        //UPS Here I have mistake:
        //DriverManagers_[i]->GetOneDriver(DriversInAutoschool_[i].release);
    }
}
void autoschool::showDrivers()
{
    for (int i = 0; i < numbersOfDrivers_; i++)
    {
        DriversInAutoschool_[i]->Go();
    }
}