#include "AutoSchool.h"

void StartSchool(AutoSchool* school)
{
	while (true)
	{
		Sleep(5000);
		std::shared_ptr<Driver> driver = std::make_shared<Driver>("Bob #" + std::to_string(school->IncrProd()), school->GetFactory());
		school->GetManager()->AddDriver(driver);
	}
}

AutoSchool::AutoSchool(std::shared_ptr<DriverManager> manager, std::shared_ptr<CarFactory> factory) :
	factory_(factory),
	manager_(manager)
{
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

uint32_t AutoSchool::IncrProd()
{
	return ++produced;
}
