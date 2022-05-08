#ifndef _ENGINE_H
#define _ENGINE_H
#include <iostream>
#include <fstream>
#include "IOController.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"
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

	static void createReservationsFile(String fileName);

	static String buildReservationFileName(String roomId);

	static RoomReservation getReservationForDate(String fileName, Date date);

public:
	//Методи:
	static void Run();
};
#endif
