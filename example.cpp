#include "example.h"
#include <iostream>

Example::Example()
: running_{false}, number_{-1}
{
    // Lambda expression
    th_ = std::thread([this]()
    {
        running_ = true;
        thread_body();
    });
}

Example::~Example() 
{
    stop();
}

void Example::stop() 
{
    setRunning(false);
    th_.join();
}

void Example::setNumber(int number) 
{
    std::lock_guard<std::mutex> lock(mtx_);
    number_ = number;
}

int Example::getNumber()
{
    std::lock_guard<std::mutex> lock(mtx_);
    return number_;
}

void Example::setRunning(bool running) 
{
    std::lock_guard<std::mutex> lock(mtx_);
    running_ = running;
}

bool Example::getRunning() 
{
    std::lock_guard<std::mutex> lock(mtx_);
    return running_;
}

void Example::thread_body() 
{
    while(getRunning()) 
    {
        auto number = getNumber();
        if(number > 0)
        {
            {
                std::lock_guard<std::mutex> lock(mtx_);
                std::cout << "send to driver: " << number_ << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            setNumber(-1);
        }
    }
    std::cout << "thread body is finished" << std::endl;
}