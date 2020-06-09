#pragma once
#include <memory>
#include <string>
#include "Car.h"

class CarFactory
{
public:
	std::unique_ptr<Car> BuildCar(const std::string& color);
};