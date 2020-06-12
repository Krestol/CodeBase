#include "stdafx.h"
#include "Driver.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "DriverManager.h"
#include "autoschool.h"
//-----
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>

int main()
{
   
    std::shared_ptr<CarFactory> factory(new CarFactory());
    autoschool mySchool(10, "Ivan",factory);
    std::thread th(&autoschool::threadfuct, &mySchool);
    th.join();
    //mySchool.showDrivers();
    mySchool.showDriversofManagers();
 
    /*
    Driver driver1("Bob", factory);
    driver1.Go();
    driver1.BuyCar("red");
    driver1.Go();
    driver1.SellCar();
    driver1.Go();
    driver1.BuyCar("green");
    Driver driver2("Jim", factory);
    driver2.Go();
    driver2.BuyUsedCar(&driver1);
    driver2.Go();
    /*
    driver1.BuyCar("red");
    driver1.Go();

    driver1.BuyCar("blue");
    driver1.Go();
    

    Driver driver2("Sam", factory);
    driver2.Go();

    driver2.BuyCar("red");
    driver2.Go();

    driver2.BuyCar("blue");
    driver2.Go();*/
    return 0;
}