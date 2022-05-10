#ifndef _ENGINE_H
#define _ENGINE_H
#include <iostream>
#include <fstream>
#include "IOController.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"
#include "HelperController.h"
class Engine
{
private:
	static Date today;

	//! Регистрация на гост
	static void registerUser();

	static Room getRoom(const String& id);

	static bool isRoomAvailable(const String& reservationsFileName, const Date& startDaete, const Date& endDate);

	static void writeReservationToFile(const String& fileName, const RoomReservation& reservation);

	static void findFreeRooms();

	static void freeRoom();

	static void getReport();

	static void getReportForRoom(const Room& room, const Date& startDate, const Date& endDate);

	static void createReservationsFile(const String& fileName);

	static unsigned getReservationsInFile(std::ifstream& ifs);

	static String getReportFileName(const Date& date);

	static String buildReservationFileName(const String& roomId);

	static RoomReservation getReservationForDate(const String& fileName, const Date& date);

	static unsigned daysInUse(const RoomReservation& reservation, const Date& firstDate, const Date& secondDate);

public:
	//Методи:
	static void Run();
};
#endif
