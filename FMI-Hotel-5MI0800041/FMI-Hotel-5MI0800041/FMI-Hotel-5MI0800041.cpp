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
	std::ifstream ifs("rooms.txt");
	if (!ifs.good())
		throw std::exception("File problem!");
	ifs.seekg(0, std::ios::end);
	int roomsCount = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	std::cout << (roomsCount / sizeof(Room));
	//Engine::Run();
}
