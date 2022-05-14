#include "Engine.h"

Engine::Engine()
{

}

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

	if (startDate < today)
		throw std::exception("Start date can not be before today");

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

	IOController::printRegisteredUserMsg();
}

Room Engine::getRoom(const String& id)
{
	std::ifstream ifs("rooms.txt");

	HelperController::checkStream(ifs);
	
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

bool Engine::isRoomAvailable(const String& reservationsFileName, const Date& startDaete, const Date& endDate)
{
	//ако не съществува файла тоав ще го създаде
	createReservationsFile(reservationsFileName);

	std::ifstream ifs(reservationsFileName.getData());

	HelperController::checkStream(ifs);
	ifs.peek();
	while(!ifs.eof())
	{
		RoomReservation crrReservation;
		ifs >> crrReservation;
		if (HelperController::doTimePeriodsCross(crrReservation.getStartDate(), crrReservation.getEndDate(), startDaete, endDate) || !(crrReservation.getIsActive()))
			return false;
		
		//Има символ за нов ред
		ifs.ignore();
	}

	return true;
}

void Engine::writeReservationToFile(const String& fileName, const RoomReservation& reservation)
{
	std::ofstream ofs((buildReservationFileName(reservation.getRoomId())).getData(), std::ios::app);
	HelperController::checkStream(ofs);

	ofs << reservation << "\n";

	ofs.close();
}

void Engine::findFreeRooms()
{
	Date desieredDate = IOController::readDate("the desired");

	if (desieredDate < today)
		throw std::exception("Date must be earlier than today");

	IOController::printFreeRoomsStartMsg(desieredDate);

	std::ifstream roomsFile("rooms.txt");
	HelperController::checkStream(roomsFile);

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
	}

	if(roomsPrinted == 0)
		IOController::printNoRoomsFound("Free room");
}

void Engine::freeRoom()
{
	String id = IOController::readRoomId();
	Room room = getRoom(id);
	freeRoom(room);
}

void Engine::getPerfectRoom()
{
	unsigned desiredNumOfBeds = IOController::readNumberOfBeds();

	Date startDate = IOController::readDate("the first");

	if (startDate < today)
		throw std::exception("Start date must be earlier than today");

	Date endDate = IOController::readDate("the second");

	if(startDate > endDate)
		throw std::exception("Start day must be before end date.;");

	std::ifstream ifs("rooms.txt");
	HelperController::checkStream(ifs);

	unsigned perfectRoomsCount = 0;
	unsigned perfectRoomBedCount = 0;
	unsigned roomsInFile = getNumberRoomsInFile("rooms.txt");
	Room* perfectRooms = new Room[roomsInFile];

	while(!ifs.eof())
	{
		Room crrRoom;
		ifs >> crrRoom;

		String fileName = buildReservationFileName(crrRoom.getId());
		if(isRoomAvailable(fileName, startDate, endDate) && crrRoom.getNumberOfBeds() >= desiredNumOfBeds)
		{
			if(crrRoom.getNumberOfBeds() == perfectRoomBedCount)
			{
				perfectRooms[perfectRoomsCount++] = crrRoom;
			}
			else if(perfectRoomsCount == 0)
			{
				perfectRooms[perfectRoomsCount++] = crrRoom;
				perfectRoomBedCount = crrRoom.getNumberOfBeds();
			}
			else if(crrRoom.getNumberOfBeds() < perfectRoomBedCount)
			{
				delete[] perfectRooms;
				//Знаем, че тези които сега са в масива, както и сегашната не са най добрите стай, за това няма шанс те да са във финалния масив и не е нужно да предвидим място за тях
				perfectRooms = new Room[roomsInFile - 1 - perfectRoomsCount];
				perfectRoomsCount = 1;
				perfectRoomBedCount = crrRoom.getNumberOfBeds();
				perfectRooms[0] = crrRoom;
			}
		}
	}

	if(perfectRoomsCount == 0)
	{
		String requirements = String("Number of bdes: ") + HelperController::convertNumToStr(desiredNumOfBeds);
		IOController::printNoRoomsFound(requirements);
	}
	else
		IOController::printPerfectRooms(perfectRooms, perfectRoomsCount);

	delete[] perfectRooms;
}

void Engine::getReport()
{
	Date startDate = IOController::readDate("the first");
	Date endDate = IOController::readDate("the second");

	if (startDate > endDate)
		throw std::exception("Start date must be before end date!");

	std::ifstream ifs("rooms.txt");
	HelperController::checkStream(ifs);

	String reportFileName = getReportFileName(startDate);

	std::ofstream reportFile(reportFileName.getData(), std::ios::trunc);
	HelperController::checkStream(reportFile);

	reportFile << "Report for the period " << startDate << "to " << endDate << " :\n";
	reportFile << "(Note: if the end date for the report is before the end date of a reservation, that has started in the wanted time period, the real end date for the reservation will be printed)\n";

	while(!ifs.eof())
	{
		Room crrRoom;
		ifs >> crrRoom;		
		
		reportFile << "Room " << crrRoom.getId() << ":\n";

		getReportForRoom(crrRoom, startDate, endDate, reportFile);
	}

	reportFile.close();
	ifs.close();
}

void Engine::closeRoom()
{
	String id = IOController::readRoomId();
	Room room = getRoom(id);

	String fileName = buildReservationFileName(id);

	if(!isRoomAvailable(fileName, today, today))
		freeRoom(room);

	room.setIsOpen(0);

	std::ifstream ifs("rooms.txt");
	HelperController::checkStream(ifs);

	unsigned roomsCount = getNumberRoomsInFile("rooms.txt");
	Room* rooms = new Room[roomsCount];

	int index = 0;
	while(!ifs.eof())
	{
		Room crrRoom;
		ifs >> crrRoom;
		if(crrRoom != room)
			rooms[index++] = crrRoom;
		else
			rooms[index++] = room;
	}

	ifs.close();

	std::ofstream ofs("rooms.txt", std::ios::trunc);
	HelperController::checkStream(ofs);

	for(size_t i = 0; i < roomsCount; i++)
		ofs << rooms[i] << "\n";

	IOController::printClosedRoomMsg();

	ofs.close();

	delete[] rooms;
}

void Engine::freeRoom(const Room& room)
{
	String fileName = buildReservationFileName(room.getId());

	if(isRoomAvailable(fileName, today, today))
		throw std::exception("Room is not in use!");

	RoomReservation reservation = getReservationForDate(fileName, today);

	reservation.setIsActive(0);

	std::ifstream ifs(fileName.getData());
	HelperController::checkStream(ifs);

	unsigned reservationsCount = getNumberReservationsInFile(ifs);
	RoomReservation* reservations = new RoomReservation[reservationsCount];

	int index = 0;
	//Има нов ред накрая на файла и eof не връща истина когато трябва
	while(index < reservationsCount)
	{
		RoomReservation crrReservation;
		ifs >> crrReservation;
		if(crrReservation != reservation)
			reservations[index++] = crrReservation;
		else
			reservations[index++] = reservation;
	}

	ifs.close();

	//Не използвам функцията writeReservationToFile, защото тя отваря и затваря потока за всяка една резерваци, така хасби време излишно
	std::ofstream ofs(fileName.getData(), std::ios::trunc);
	HelperController::checkStream(ofs);

	for(size_t i = 0; i < index - 1; i++)
		ofs << reservations[i];

	IOController::printFreedRoomMsg();

	ofs.close();

	delete[] reservations;
}

void Engine::getReportForRoom(const Room& room, const Date& startDate, const Date& endDate, std::ofstream& reportFile)
{
	String fileName = buildReservationFileName(room.getId());

	createReservationsFile(fileName);

	std::ifstream ifs(fileName.getData());
	HelperController::checkStream(ifs);

	//ако не съществува файла тоав ще го създаде
	createReservationsFile(fileName);

	ifs.peek();
	unsigned counter = 0;
	unsigned daysUsed = 0;
	while(!ifs.eof())
	{
		RoomReservation reservation;
		ifs >> reservation;		
		
		unsigned crrDays = daysInUse(reservation, startDate, endDate);

		if(crrDays != 0)
		{
			reportFile << ++counter <<". " << reservation << "\n";
			daysUsed += crrDays;
		}		
	}

	reportFile << "Total days used: " << daysUsed << "\n";

	ifs.close();
}

void Engine::createReservationsFile(const String& fileName)
{
	std::ofstream ofs(fileName.getData(), std::ios::app);
	HelperController::checkStream(ofs);

	ofs.close();
}

unsigned Engine::getNumberReservationsInFile(std::ifstream& ifs)
{
	ifs.seekg(0, std::ios::end);
	unsigned reservationsCount = ifs.tellg() / sizeof(RoomReservation);
	ifs.seekg(0, std::ios::beg);
	return reservationsCount;
}

unsigned Engine::getNumberRoomsInFile(const String& fileName)
{
	std::ifstream ifs(fileName.getData());
	HelperController::checkStream(ifs);
	unsigned count = 0;
	while (!ifs.eof())
	{
		Room temp;
		ifs >> temp;
		++count;
		ifs.ignore();
	}
	return count;
}

String Engine::getReportFileName(const Date& date)
{
	String str = "report-";
	str += HelperController::convertNumToStr(date.getYear());
	str += "-";
	if(date.getMonth() < 10)
	{
		str += HelperController::convertNumToStr(0);
		str += HelperController::convertNumToStr(date.getMonth());
	}
	else
		str += HelperController::convertNumToStr(date.getMonth());

	str += "-";
	
	if (date.getDay() < 10)
	{
		str += HelperController::convertNumToStr(0);
		str += HelperController::convertNumToStr(date.getDay());
	}
	else
		str += HelperController::convertNumToStr(date.getDay());
	
	str += ".txt";
	return str;
}

String Engine::buildReservationFileName(const String& roomId)
{
	return roomId + "_reservations.txt";
}

RoomReservation Engine::getReservationForDate(const String& fileName, const Date& date)
{
	std::ifstream ifs(fileName.getData());
	HelperController::checkStream(ifs);

	RoomReservation crrReservation;
	unsigned reservationsCount = getNumberReservationsInFile(ifs);
	unsigned count = 0;
	//Има нов ред накрая на файла и eof не връща истина когато трябва
	while (count <= reservationsCount && !(crrReservation.getStartDate() <= date && date <= crrReservation.getEndDate()))
	{		
		ifs >> crrReservation;
		count++;
	}
	ifs.close();
	return crrReservation;
}

unsigned Engine::daysInUse(const RoomReservation& reservation, const Date& firstDate, const Date& secondDate)
{
	unsigned count = 0;
	if(HelperController::doTimePeriodsCross(reservation.getStartDate(), reservation.getEndDate(), firstDate, secondDate))
	{
		Date start = HelperController::getLaterDate(reservation.getStartDate(), firstDate);
		Date later = HelperController::getEarlierDate(reservation.getEndDate(), secondDate);

		count = later - start;
	}

	return count;
}

void Engine::run()
{
	IOController::prindGreeting();
	today = IOController::readDate("todays");
	//Задавам стойност а за да съм сигурен че няма да е нула в началото
	char command = '\0';
	while (command != 'e')
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
			case '4':
				getReport();
				break;
			case '5':
				getPerfectRoom();
				break;
			case '6':
				closeRoom();
				break;
			case 'e':
				IOController::printGoodbye();
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

Engine& Engine::getEngine()
{
	static Engine engine;
	return engine;
}