#pragma once
class DriverManager
{
public:
    DriverManager(const std::string& nameManager, std::shared_ptr<CarFactory> factory);
    
    void GetOneDriver(std::unique_ptr<Driver> CurrentDriver);
    
private:
    std::string nameManager_;
    std::shared_ptr<CarFactory> factory_;
    std::vector<std::unique_ptr<Driver>> ManagerDrivers_;
    std::unique_ptr<Driver> OneDriver_;
};

