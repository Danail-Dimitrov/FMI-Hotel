#include <iostream>
#include <fstream>
#include "Date.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"
#include "IOController.h"
#include "Engine.h"

int main()
{
	Date date1 = Date(1, 1, 2023);
	Date date2 = Date(31, 12, 2023);
	std::cout << date2 - date1;
	//Engine::Run();
}
