#include "AutoSchool.h"

void StartSchool(AutoSchool* school)
{
	while (true)
	{
		Sleep(5000);
		Driver* driver = new Driver("Bob #" + std::to_string(school->IncrProd()), school->GetFactory());
		DriverManager* manager = *school->GetManager();
		manager->AddDriver(driver);
	}
}

AutoSchool::AutoSchool(std::shared_ptr<DriverManager> manager, std::shared_ptr<CarFactory> factory) :
	factory_(factory)
{
	DriverManager* tmp = &*manager;
	manager_ = std::make_shared<DriverManager*>(tmp);
	thread_ = std::make_unique<std::thread*>(new std::thread(StartSchool, this));
}

std::shared_ptr<CarFactory> AutoSchool::GetFactory()
{
	return factory_;
}

std::shared_ptr<DriverManager*> AutoSchool::GetManager()
{
	return manager_;
}

uint32_t AutoSchool::IncrProd()
{
	return ++produced;
}
