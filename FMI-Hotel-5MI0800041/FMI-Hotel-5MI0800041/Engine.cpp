#include "Engine.h"

void Engine::registerUser()
{
	String id = IOController::readRoomId();

	// Взимам стаята заради следващата проверка, ако не взимах стаята трябваше да мина
	//още веднъж през файла със стай за да видя дали е отворена освен дали съществува 
	//(което се вижда в метода getRoom())
	Room room = getRoom(id);

	if(!room.getIsOpen())
		throw "Room is closed!";

	Date startDate = IOController::readDate("first");
	Date endDate = IOController::readDate("second");

	if(startDate > endDate)
		throw "Start date must be before end date!";

	String fileName = id + "_reservations.txt";

	if(!isRoomAvailable(fileName, startDate, endDate))
		throw "Room not available!";

	String comment = IOController::readComment();	

	String firstName = IOController::readName("first");
	String lastName = IOController::readName("second");

	RoomReservation reservation = RoomReservation(id, startDate, endDate, firstName, lastName, comment, true);

	writeReservationToFile(fileName, reservation);
}

Room Engine::getRoom(String id)
{
	std::ifstream ifs("rooms.txt");

	if (!ifs.good())
		throw "File problem!";
	
	while(!ifs.eof())
	{
		Room crrRoom;
		ifs >> crrRoom;
		if (crrRoom.getId() == id)
		{
			ifs.close();
			return crrRoom;
		}
	}

	throw "Room does not exist!";
}

bool Engine::isRoomAvailable(String fileName, Date startDaete, Date endDate)
{
	std::ofstream ofs(fileName.getData());
	if (!ofs.is_open())
		throw "File problem!";
	ofs.close();

	std::ifstream ifs(fileName.getData());

	if (!ifs.is_open())
		throw "File problem!";
	ifs.peek();
	while(!ifs.eof())
	{
		RoomReservation crrReservation;
		ifs >> crrReservation;
		if (!(crrReservation.getStartDate() < endDate && crrReservation.getEndDate() > startDaete) && crrReservation.getIsActive())
			return false;
	}

	return true;
}

void Engine::writeReservationToFile(String fileName, const RoomReservation& reservation)
{
	std::ofstream ofs((reservation.getRoomId() + "_reservations.txt").getData(), std::ios::app);
	if(!ofs.good())
		throw "File problem!";

	ofs << reservation;

	ofs.close();
}

void Engine::Run()
{
	IOController::prindGreeting();
	//Задавам стойност а за да съм сигурен че няма да е нула в началото
	char command = 'a';
	while (command != '0')
	{
		IOController::printMenu();
		command = IOController::readMenuInput();

		switch(command)
		{
		case '1':
			registerUser();
		default:
			break;
		}

		IOController::clearScreen();
	}
}
