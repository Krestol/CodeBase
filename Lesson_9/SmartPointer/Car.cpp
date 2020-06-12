#include "stdafx.h"
#include "Car.h"

Car::Car(const std::string& color)
    : color_(color)
{
    status_ = "new";
    //std::cout << status_ << " " << color_ << " car has been created\n";
}

Car::~Car()
{
    std::cout << color_ << " car has been destroied\n";
}

void Car::BecomeBY()
{
    std::string tmp = status_;
    status_ = "BY";
}

void Car::Drive()
{
    std::cout << status_ << " " << color_ << " car in move\n";
}