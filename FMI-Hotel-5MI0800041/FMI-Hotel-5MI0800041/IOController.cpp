#include "IOController.h"
#include <fstream>
#include <iostream>

void IOController::prindGreeting(std::ostream& stream)
{
	stream << "Hello! Thank you for using FMI-Hotel!\n";
}

void IOController::printMenu(std::ostream& stream)
{
	stream << "Menu: \nEnter the number for the command you would like to be executed!\n";
	stream << "1. Register a guest.\n";
	stream << "2. Get free rooms at a given date.\n";
	stream << "3. Free room.\n";
	stream << "4. Get report.\n";
	stream << "5. Get perfect room.\n";
	stream << "6. Close room.\n";
}

void IOController::clearScreen()
{
	//Информацията как да изчистя конзолата намерих на адрес: https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
	system("cls");
}

void IOController::printFreeRoomsStartMsg(Date date, std::ostream& stream)
{
	stream << "Free rooms at " << date << " are:\n";
}

void IOController::printNthRoom(Room room, int n, std::ostream& stream)
{
	stream << n << ". " << room << "\n";
}

void IOController::printNoRoomsFound(const String& requirements, std::ostream& stream)
{
	stream << "No room that satisfied the requirements is found. Requirements:\n" << requirements << "\n";
}

void IOController::printPerfectRooms(const Room* rooms, unsigned count, std::ostream& stream)
{
	stream << "Suitable rooms:\n";

	for(size_t i = 0; i < count; ++i)
		stream << rooms[i] << "\n";
}

void IOController::printContrinueMsg(std::ostream& stream)
{
	stream << "Enter any key to continue!\n";
}

void IOController::printFreedRoomMsg(std::ostream& stream)
{
	stream << "Freed room!\n";
}

void IOController::printClosedRoomMsg(std::ostream& stream)
{
	stream << "Closed Room!\n";
}

char IOController::readMenuInput(std::istream& stream)
{
	char input;
	input = stream.get();

	stream.ignore();

	if (input < '0' || input > '6')
		throw std::exception("Char command not valid");

	return input;
}

void IOController::readAnyKey(std::istream& stream)
{
	stream.get();
}

String IOController::readRoomId(std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter room id:\n";
	String input;
	istream >> input;

	return input;
}

Date IOController::readDate(String dateName, std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter " << dateName << " date: (In format d.m.yyyy)\n";
	Date input;
	istream >> input;
	istream.ignore(); 
	return input;
}

String IOController::readComment(std::istream& istream, std::ostream& ostream)
{
	ostream << "Do you want to add a comment to the reservation?: (if no press enter)\n";
	String input;
	istream >> input;
	if (input == "")
		input = "NO_COMMENT";

	return input;
}

String IOController::readName(String dateIndex, std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter the " << dateIndex << " name:\n";
	String input;
	istream >> input;
	return input;
}

unsigned IOController::readNumberOfBeds(std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter the desired number of beds:\n";
	unsigned beds;
	istream >> beds;
	return beds;
}
