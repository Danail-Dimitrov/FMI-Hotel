#include <iostream>
#include <fstream>
#include "Date.h"

int main()
{
    Date date;
    std::ifstream is("test.txt");

    if(!is.is_open())
        return 1;

    is >> date;

    is.close();

    std::cout << date;
}
