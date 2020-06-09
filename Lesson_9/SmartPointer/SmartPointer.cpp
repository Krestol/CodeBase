#include "stdafx.h"
#include "Car.h"
#include "Driver.h"
#include "CarFactory.h"
#include "DriverManager.h"
#include "AutoSchool.h"

int main()
{
    std::shared_ptr<CarFactory> factory(new CarFactory());
    std::shared_ptr<DriverManager> manager(new DriverManager());
    std::unique_ptr<AutoSchool> school(new AutoSchool(manager, factory));

    Sleep(1000000);
    return 0;
}