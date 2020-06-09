#pragma once
#include "Driver.h"

class DriverManager
{
public:
	DriverManager();
	void AddDriver(std::shared_ptr<Driver> driver);
	void StartDriver();
	HANDLE GetEvent();
private:
	HANDLE g_event_;
	std::vector<std::shared_ptr<Driver>> drivers_;
	std::unique_ptr<std::thread> thread_;
};

