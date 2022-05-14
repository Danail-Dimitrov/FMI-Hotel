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
	Date today;

	Engine();

	//! Регистрация на гост
	void registerUser();

	Room getRoom(const String& id);

	bool isRoomAvailable(const String& reservationsFileName, const Date& startDaete, const Date& endDate);

	void writeReservationToFile(const String& fileName, const RoomReservation& reservation);

	void findFreeRooms();

	void freeRoom();

	void getPerfectRoom();

	void getReport();

	void closeRoom();

	void freeRoom(const Room& room);

	void getReportForRoom(const Room& room, const Date& startDate, const Date& endDate, std::ofstream& reportFile);

	void createReservationsFile(const String& fileName);

	unsigned getNumberReservationsInFile(std::ifstream& ifs);

	unsigned getNumberRoomsInFile(const String& fileName);

	String getReportFileName(const Date& date);

	String buildReservationFileName(const String& roomId);

	RoomReservation getReservationForDate(const String& fileName, const Date& date);

	unsigned daysInUse(const RoomReservation& reservation, const Date& firstDate, const Date& secondDate);

public:

	void operator=(const Engine& other) = delete;
	Engine(const Engine& other) = delete;

	//Методи:
	void run();

	static Engine& getEngine();
};
#endif
