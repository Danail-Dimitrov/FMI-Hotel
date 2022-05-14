#include <iostream>
#include <fstream>
#include "Date.h"
#include "String.h"
#include "Room.h"
#include "RoomReservation.h"
#include "IOController.h"
#include "Engine.h"

int main()
{
	Engine& engine = Engine::getEngine();

	engine.run();

	return 0;
}
