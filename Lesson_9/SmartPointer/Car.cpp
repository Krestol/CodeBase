#include "stdafx.h"
#include "Car.h"


Car::Car(const std::string& color)
    : color_(color)
{
    std::cout << color_ << " car has been created\n";
}
Car::~Car() 
{ std::cout << color_ << " car has been destroied\n"; }
void Car::Drive()
{
    std::cout << color_ << " car in move\n";
}
