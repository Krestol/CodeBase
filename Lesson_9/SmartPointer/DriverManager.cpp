#include "DriverManager.h"

void RunDriver(DriverManager* manager)
{
	while (true)
	{
		WaitForSingleObject(manager->GetEvent(), INFINITE);
		manager->StartDriver();
	}
}

DriverManager::DriverManager()
{
	g_event_ = CreateEvent(
		NULL,
		FALSE,
		FALSE,
		NULL
	);
	thread_ = std::make_unique<std::thread>(RunDriver, this);
}

void DriverManager::AddDriver(std::shared_ptr<Driver> driver)
{
	drivers_.push_back(driver);
	SetEvent(g_event_);
}

void DriverManager::StartDriver()
{
	drivers_.back()->Start();
}

HANDLE DriverManager::GetEvent()
{
	return g_event_;
}

