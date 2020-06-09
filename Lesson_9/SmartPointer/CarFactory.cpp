#include "stdafx.h"



std::unique_ptr<Car> CarFactory::BuildCar(const std::string& color)
{
    return std::unique_ptr<Car>(new Car(color));
}