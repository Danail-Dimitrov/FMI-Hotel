#include <iostream>
#include <fstream>
#include "Date.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"
#include "IOController.h"

int main()
{
	IOController ctrl = IOController::getInstance();
	ctrl.test();
}
