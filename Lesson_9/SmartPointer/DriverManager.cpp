#include "DriverManager.h"

void DriverManager::AddDriver(std::shared_ptr<Driver> driver, std::shared_ptr<std::thread> thread)
{
	drivers_.push_back(driver);
	driversthreads_.push_back(thread);
}

std::shared_ptr<Driver> DriverManager::WhoIsReadyToSale()
{
	for (auto& driver : drivers_)
	{
		if (driver->IfReady())
		{
			return driver;
		}
	}
	return nullptr;
}
