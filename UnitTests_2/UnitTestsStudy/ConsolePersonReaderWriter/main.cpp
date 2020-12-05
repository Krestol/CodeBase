#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include "include/personsdatamanager.h"

class ConsoleReader : public IReader
{
public:
    std::string Read() const override;
};

class ConsoleWriter : public IWriter
{
public:
    void Write(const std::vector<std::string>& data) const override;
};

class ErrorObserver : public IErrorObserver
{
public:
    void OnError(const std::string& error) const override;
};

void ErrorObserver::OnError(const std::string& error) const
{
    std::cout << "[ERROR] " << error << std::endl;
}


std::string ConsoleReader::Read() const
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}

void ConsoleWriter::Write(const std::vector<std::string>& data) const
{
    for (const auto& str : data)
    {
        std::cout << str << std::endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ManagePersonsData(ConsoleReader(), ConsoleWriter(), ErrorObserver());

    return a.exec();
}
