#include "stdafx.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "DriverManager.h"
#include "autoschool.h"

int main()
{
    
    std::shared_ptr<CarFactory> factory(new CarFactory());
    autoschool mySchool(5, 2, "Ivan",factory);
    std::thread thp(&autoschool::threadfuct, &mySchool);
    thp.join();
    return 0;
}