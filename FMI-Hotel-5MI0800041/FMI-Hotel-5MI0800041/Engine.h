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
	//! Регистрация на гост
	static void registerUser();

	static Room getRoom(String id);

	static bool isRoomAvailable(String fileNamse, Date startDaete, Date endDate);

	static void writeReservationToFile(String fileName, const RoomReservation& reservation);

public:
	//Методи:
	static void Run();
};
#endif
