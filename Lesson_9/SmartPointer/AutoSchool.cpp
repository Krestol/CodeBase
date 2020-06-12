#include "stdafx.h"
#include "AutoSchool.h"

void StartSchool(AutoSchool* school)
{
	while (true)
	{
		Sleep(5000);
		uint32_t tmp  = school->IncrProd();
		std::shared_ptr<Driver> driver = std::make_shared<Driver>("Bob #" + std::to_string(tmp), school->GetFactory(), school->GetManager(), tmp - 1, school->GetMutex());
		std::shared_ptr<std::thread> thread = std::make_shared<std::thread>(&Driver::Start, driver);
		school->GetManager()->AddDriver(driver, thread);
	}
}

AutoSchool::AutoSchool(std::shared_ptr<DriverManager> manager, std::shared_ptr<CarFactory> factory) :
	factory_(factory),
	manager_(manager)
{
	mutex_ = std::make_shared<std::mutex>();
	thread_ = std::make_unique<std::thread>(StartSchool, this);
}

std::shared_ptr<CarFactory> AutoSchool::GetFactory()
{
	return factory_;
}

std::shared_ptr<DriverManager> AutoSchool::GetManager()
{
	return manager_;
}

std::shared_ptr<std::mutex> AutoSchool::GetMutex()
{
	return mutex_;
}

uint32_t AutoSchool::IncrProd()
{
	return ++produced_;
}
