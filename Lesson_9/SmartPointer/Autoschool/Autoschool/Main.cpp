#include "Driver.h"
#include "Driver.h"
#include "CarFactory.h"
#include "Car.h"
#include "stdafx.h"

int main()
{
    std::shared_ptr<CarFactory> factory(new CarFactory());
    Driver driver1("Bob", factory);
    driver1.Go();

    driver1.BuyCar("red");
    driver1.Go();

    driver1.BuyCar("blue");
    driver1.Go();
    

    Driver driver2("Sam", factory);
    driver2.Go();

    driver2.BuyCar("red");
    driver2.Go();

    driver2.BuyCar("blue");
    driver2.Go();


    return 0;
}