#include "example.h"
#include <iostream>


int main()
{
    std::cout << "ver6" << std::endl;
    Example ex;


    while(true) 
    {
        std::cout << "please input number: " << std::endl;
        int a;
        std::cin >> a;
        if (a < -100) 
        {
            break;
        }

        if(ex.getNumber() == -1)
        {
            ex.setNumber(a);
        }

    }

    return 0;
}