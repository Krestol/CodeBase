#pragma once
class Car;
class CarFactory;

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory);
    ~Driver();

    void BuyCar(const std::string& color);

    std::unique_ptr<Car> SellCar();
    void BuyUsedCar(Driver* d);

    void Go();

private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
};

