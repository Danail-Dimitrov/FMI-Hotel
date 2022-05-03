#include "IOController.h"
#include <iostream>

IOController::IOController()
{
}

IOController& IOController::getInstance()
{
	static IOController instance;
	return instance;
}

void IOController::test()
{
	std::cout << "yes";
}
