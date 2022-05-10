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

	static Room getRoom(String id);

	static bool isRoomAvailable(String reservationsFileName, Date startDaete, Date endDate);

	static void writeReservationToFile(String fileName, const RoomReservation& reservation);

	static void findFreeRooms();

	static void freeRoom();

	static void getReport();

	static void getReportForRoom(Room room, Date startDate, Date endDate);

	static void createReservationsFile(String fileName);

	static unsigned getReservationsInFile(std::ifstream& ifs);

	static String getReportFileName(Date date);

	static String buildReservationFileName(String roomId);

	static RoomReservation getReservationForDate(String fileName, Date date);

	static unsigned daysInUse(RoomReservation reservation, Date firstDate, Date secondDate);

public:
	//Методи:
	static void Run();
};
#endif
