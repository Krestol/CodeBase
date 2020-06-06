#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void ThreadFunction()
{
    while (true)
    {
        std::cout << "ThreadFunction" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void ThreadFunctionWithArguments(int a, std::string str)
{
    while (true)
    {
        std::string outMsg = "ThreadFunctionWithArguments " + str;
        std::cout << outMsg << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

class SomeClass
{
public:
    void ClassMethod()
    {
        while (true)
        {
            std::cout << "SomeClass:::ClassMethod" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

class Functor
{
public:
    void operator()()
    {
        while (true)
        {
            std::cout << "Functor::operator()" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int main()
{
    std::thread thread1(ThreadFunction);
    std::thread thread2(ThreadFunctionWithArguments, 0, "some string");
    SomeClass obj;
    std::thread thread3(&SomeClass::ClassMethod, &obj);

    Functor functor;
    std::thread thread4(functor);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
}