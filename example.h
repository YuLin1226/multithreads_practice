#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include <thread>
#include <mutex>

class Example 
{
    public:
        Example();
        ~Example();
        void setNumber(int number);
        void stop();
        int getNumber();


    private:
        std::mutex mtx_;
        bool running_;
        int number_;
        std::thread th_;

        void thread_body();
        void setRunning(bool running);
        bool getRunning();
};


#endif // _EXAMPLE_H_