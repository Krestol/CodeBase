#include "stdafx.h"
#include "CarFactory.h"
#include "Car.h"

std::unique_ptr<Car> CarFactory::BuildCar(const std::string& color)
{
        return std::make_unique<Car>(new Car(color));
}
