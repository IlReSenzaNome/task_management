#include <iostream>
#include "../lib/rlutil.h"

void taskInterfaz(const std::string &task)
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|         " << task << "                 |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|> Description:                  |" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|> Due Date:                     |" << std::endl;
    std::cout << "|> State:                        |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void error()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|            Error               |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}