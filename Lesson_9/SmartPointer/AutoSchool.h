#pragma once
#include "DriverManager.h"

class AutoSchool
{
public:
	AutoSchool(std::shared_ptr<DriverManager> manager, std::shared_ptr<CarFactory> factory);
	std::shared_ptr<CarFactory> GetFactory();
	std::shared_ptr<DriverManager> GetManager();
	uint32_t IncrProd();
private:
	std::shared_ptr<DriverManager> manager_;
	std::shared_ptr<CarFactory> factory_;
	std::unique_ptr<std::thread> thread_;
	uint32_t produced;
};

