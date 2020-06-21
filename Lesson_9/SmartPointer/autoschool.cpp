#pragma once
#include "stdafx.h"
#include "autoschool.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "DriverManager.h"

autoschool::autoschool(int numbersOfDrivers, int numberOfDriversInOwnedByOneManager, std::string name, std::shared_ptr<CarFactory>& factory)
    :factory_(factory), name_(name), numbersOfDrivers_(numbersOfDrivers), Manager_("stepan", factory_)
{}
    const void autoschool::getName(const int& i)
    {
        if (i == 0)
            name_ = "Sergey";
        else if (i == 1)
            name_ = "Ivan";
        else if (i == 2)
            name_ = "Sasha";
        else if (i == 4)
            name_ = "Masha";
        else name_ = "Pasha";
    }
    void autoschool::threadfuct()
    {
        for (int i = 0; i < numbersOfDrivers_; i++) //1) create Drivers:
        {
            getName(i);
            DriversInAutoschool_.push_back(std::make_unique<Driver>(name_, factory_));
            DriversInAutoschool_[i]->rememberMySchool(this);//TODO зачем ему знать школу?! скорее это не требуется
        }
        for (int i = 0; i < numbersOfDrivers_; i++) //2)Give all Drivers to one Manager:
        {
            Manager_.GetOneDriver(std::move(std::unique_ptr<Driver>(DriversInAutoschool_[i].release())));
            Manager_.setFieldManagerToOnedDrivers(i);
        }
        Manager_.startThread();//3) run manager method
    }