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
    void cleverGo();
    std::vector<int> canIbuyUsedCar();
    void rememberMyManager(DriverManager* myM);
    DriverManager* sayNameMyManager();
    void rememberMySchool(autoschool* myS);
    autoschool* sayNameMySchool();
    Driver* giveDriverToBuyCar();
    std::string SetCarColor();
    int intRand(const int& min, const int& max);
private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
    DriverManager* myManager_;
    autoschool* mySchool_;
};

