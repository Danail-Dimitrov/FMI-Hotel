#include <iostream>
#include <fstream>
#include "Date.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"

int main()
{
	RoomReservation res = RoomReservation("A15", Date(1, 2, 2023), Date(2, 2, 2023), "firstName", "lastName", "comment from four words", 0);

	std::ofstream ofs("test.txt");
	if (!ofs.is_open())
		return 1;

	ofs << res;

	ofs.close();

	std::ifstream ifs("test.txt");
	if (!ifs.is_open())
		return 1;

	RoomReservation res1;
	ifs >> res1;

	ifs.close();

	std::cout << res1;
}
