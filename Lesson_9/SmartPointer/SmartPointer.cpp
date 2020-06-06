#include <iostream>
#include <string>
#include <memory>

class Car
{
public:
    Car(const std::string& color)
    : color_(color)
    {
        std::cout << color_ << " car has been created\n";
    }
    ~Car() { std::cout << color_ << " car has been destroied\n"; }

    void Drive()
    {
        std::cout << color_ << " car in move\n";
    }

private:
    std::string color_;
};

class CarFactory
{
public:
    std::unique_ptr<Car> BuildCar(const std::string& color)
    {
        return std::unique_ptr<Car>(new Car(color));
    }
};

class Driver
{
public:
    Driver(const std::string& name, std::shared_ptr<CarFactory> factory)
        : factory_(factory)
        , name_(name)
    {
    }

    void BuyCar(const std::string& color)
    {
        car_ = factory_->BuildCar(color);
    }

    // SellCar
    // BuyUsedCar

    void Go()
    {
        if (car_ != nullptr)
        {
            std::cout << name_ << " I have a car ";
            car_->Drive();
        }
        else
        {
            std::cout << name_ << ": I'll go on foot\n";
        }
    }

private:
    std::unique_ptr<Car> car_;
    std::shared_ptr<CarFactory> factory_;
    std::string name_;
};

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