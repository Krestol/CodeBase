#pragma once

#include "CarFactory.h"
#include "Car.h"
class DriverManager;
class autoschool;

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    void BuyCar(const std::string& color);
    void BuyUsedCar(Driver* d);
    std::unique_ptr<Car> SellCar();
    void Go();
    void ShowDriverInfo();
    bool HaveCar();
    void cleverGo();
    std::vector<int> canIbuyUsedCar();
    std::vector<int> AdviseDriverFromManagerToBuyCar();
    void rememberMyManager(DriverManager* myM);
    DriverManager* sayNameMyManager();
    void rememberMySchool(autoschool* myS);
    autoschool* sayNameMySchool();
 private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    DriverManager* myManager_;
    autoschool* mySchool_;
    
};

