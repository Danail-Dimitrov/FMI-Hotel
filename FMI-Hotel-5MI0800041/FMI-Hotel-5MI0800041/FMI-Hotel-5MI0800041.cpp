#include <iostream>
#include <fstream>
#include "Date.h"
#include "String.h"
#include "Room.h"

int main()
{
	Room str = Room("A125", 5, 1);

    std::ofstream ofs("test.txt");

	if(!ofs.is_open())
		return 1;

	ofs << str;

	ofs.close();

	Room str1;

	std::ifstream ifs("test.txt");

	if(!ifs.is_open())
		return 1;

	ifs >> str1;

	ifs.close();

	std::cout << str1;
}
