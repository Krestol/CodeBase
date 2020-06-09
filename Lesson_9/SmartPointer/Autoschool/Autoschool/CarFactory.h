#pragma once
#include "Car.h"
#include "stdafx.h"

class CarFactory
{
public:
    std::unique_ptr <Car> BuildCar(const std::string& color);
};