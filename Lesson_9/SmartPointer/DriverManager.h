#pragma once
#include "Driver.h"

class DriverManager
{
public:
	void AddDriver(std::shared_ptr<Driver> driver, std::shared_ptr<std::thread> thread);
	std::shared_ptr<Driver> WhoIsReadyToSale();
private:
	std::vector<std::shared_ptr<Driver>> drivers_;
	std::vector<std::shared_ptr<std::thread>> driversthreads_;
};

