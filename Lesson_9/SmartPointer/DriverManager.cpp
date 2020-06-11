#include "stdafx.h"
#include "CarFactory.h"
#include "Driver.h"
#include "DriverManager.h"

DriverManager::DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory> factory)
    : factory_(factory)
    , nameManager_(nameManager), ManagerDrivers_(0)
{
}
void DriverManager::GetOneDriver(std::unique_ptr<Driver> CurrentDriver)
{
    OneDriver_ = std::move(CurrentDriver);
}
