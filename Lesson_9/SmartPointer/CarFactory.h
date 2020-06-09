#pragma once
class Car;

class CarFactory
{
public:
    std::unique_ptr<Car> BuildCar(const std::string& color);
};
