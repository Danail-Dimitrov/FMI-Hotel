#include "Engine.h"

Date Engine::today;

void Engine::registerUser()
{
	String id = IOController::readRoomId();

	// Взимам стаята заради следващата проверка, ако не взимах стаята трябваше да мина
	//още веднъж през файла със стай за да видя дали е отворена освен дали съществува 
	//(което се вижда в метода getRoom())
	Room room = getRoom(id);

	if(!room.getIsOpen())
		throw std::exception("Room is closed!");

	Date startDate = IOController::readDate("the first");
	Date endDate = IOController::readDate("the second");

	if(startDate > endDate)
		throw std::exception("Start date must be before end date!");

	String fileName = buildReservationFileName(id);

	if(!isRoomAvailable(fileName, startDate, endDate))
		throw std::exception("Room not available!");

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
		throw std::exception("File problem!");
	
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

	throw std::exception("Room does not exist!");
}

bool Engine::isRoomAvailable(String reservationsFileName, Date startDaete, Date endDate)
{
	//ако не съществува файла тоав ще го създаде
	createReservationsFile(reservationsFileName);

	std::ifstream ifs(reservationsFileName.getData());

	if (!ifs.good())
		throw std::exception("File problem!");
	ifs.peek();
	while(!ifs.eof())
	{
		RoomReservation crrReservation;
		ifs >> crrReservation;
		if (crrReservation.getStartDate() < endDate && crrReservation.getEndDate() > startDaete && crrReservation.getIsActive())
			return false;
		
		//Има символ за нов ред
		ifs.ignore();
	}

	return true;
}

void Engine::writeReservationToFile(String fileName, const RoomReservation& reservation)
{
	std::ofstream ofs((buildReservationFileName(reservation.getRoomId())).getData(), std::ios::app);
	if(!ofs.good())
		throw std::exception("File problem!");

	ofs << reservation << std::endl;

	ofs.close();
}

void Engine::findFreeRooms()
{
	Date desieredDate = IOController::readDate("the desired");

	IOController::printFreeRoomsStartMsg(desieredDate);

	std::ifstream roomsFile("rooms.txt");
	if(!roomsFile.good())
		throw std::exception("File problem!");

	int roomsPrinted = 0;

	while (!roomsFile.eof())
	{
		Room crrRoom;
		roomsFile >> crrRoom;
		String fileName = buildReservationFileName(crrRoom.getId());
		if(crrRoom.getIsOpen() && isRoomAvailable(fileName, desieredDate, desieredDate))
		{
				IOController::printNthRoom(crrRoom, roomsPrinted + 1);
				++roomsPrinted;			
		}		

		//Във файла има нов ред след всяка стая
		roomsFile.ignore();
	}

	if (roomsPrinted == 0)
		IOController::printNoRoomsMsg();
}

void Engine::freeRoom()
{
	String id = IOController::readRoomId();
	Room room = getRoom(id);

	String fileName = buildReservationFileName(id);

	if(isRoomAvailable(fileName, today, today))
		throw std::exception("Room is not in use!");

	RoomReservation reservation = getReservationForDate(fileName, today);

	reservation.setIsActive(0);

	std::ifstream ifs(fileName.getData());
	if (!ifs.good())
		throw std::exception("File problem!");

	ifs.seekg(0, std::ios::end);
	int reservationsCount = ifs.tellg() / sizeof(RoomReservation);
	ifs.seekg(0, std::ios::beg);
	RoomReservation* reservations = new RoomReservation[reservationsCount];

	int index = 0;
	while(!ifs.eof())
	{
		RoomReservation crrReservation;
		ifs >> crrReservation;
		if (crrReservation != reservation)
			reservations[index++] = crrReservation;
		else
			reservations[index++] = reservation;
	}

	ifs.close();

	//Не използвам функцията writeReservationToFile, защото тя отваря и затваря потока за всяка една резерваци, така хасби време излишно
	std::ofstream ofs(fileName.getData());
	if (!ofs.good())
		throw std::exception("File problem!");

	for (size_t i = 0; i < index - 1; i++)
		ofs << reservations[i];

	ofs.close();
}

void Engine::createReservationsFile(String fileName)
{
	std::ofstream ofs(fileName.getData(), std::ios::app);
	if(!ofs.good())
		throw std::exception("File problem!");
	ofs.close();
}

String Engine::buildReservationFileName(String roomId)
{
	return roomId + "_reservations.txt";
}

RoomReservation Engine::getReservationForDate(String fileName, Date date)
{
	std::ifstream ifs(fileName.getData());
	if (!ifs.good())
		throw std::exception("File problem!");
	RoomReservation crrReservation;
	while (!ifs.eof() && !(crrReservation.getStartDate() < date && date < crrReservation.getEndDate()))
	{		
		ifs >> crrReservation;
		//Има символ за нов ред
		ifs.ignore();
	}
	ifs.close();
	return RoomReservation();
}

void Engine::Run()
{
	IOController::prindGreeting();
	today = IOController::readDate("todays");
	//Задавам стойност а за да съм сигурен че няма да е нула в началото
	char command = 'a';
	while (command != '0')
	{
		try
		{
			IOController::printMenu();
			command = IOController::readMenuInput();

			switch (command)
			{
			case '1':
				registerUser();
				break;
			case '2':
				findFreeRooms();
				break;
			case '3':
				freeRoom();
				break;
			default:
				break;
			}

			IOController::printContrinueMsg();
			IOController::readAnyKey();

			IOController::clearScreen();
		}
		catch (const std::exception& ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
	}
}