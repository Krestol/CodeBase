#pragma once
#include "Driver.h"

class DriverManager
{
public:
	DriverManager();
	void AddDriver(Driver* driver);
	void StartDriver();
	std::thread* GetThread();
	HANDLE GetEvent();
private:
	HANDLE g_event_;
	std::vector<Driver*> drivers_;
	std::unique_ptr<std::thread*> thread_;
};

