#pragma once
#include "stdafx.h"
#include "Car.h"

class CarFactory
{
public:
    std::unique_ptr <Car> BuildCar(const std::string& color);
};