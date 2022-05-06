#include "IOController.h"
#include <fstream>
#include <iostream>

void IOController::prindGreeting(std::ostream& stream)
{
	stream << "Hello! Thank you for using FMI-Hotel!\n";
}

void IOController::printMenu(std::ostream& stream)
{
	stream << "Menu: \nEnter the number for the command you would like to be executed!" << std::endl;
	stream << "1. Register a guest.\n";
}

void IOController::clearScreen()
{
	//Информацията как да изчистя конзолата намерих на адрес: https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
	system("cls");
}

char IOController::readMenuInput(std::istream& stream)
{
	char input;
	stream >> input;

	stream.ignore();

	if (input < '0' || input > '6')
		throw "Char command not valid";

	return input;
}

String IOController::readRoomId(std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter room id:\n";
	String input;
	istream >> input;

	return input;
}

Date IOController::readDate(String dateIndex, std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter the " << dateIndex << " date:\n";
	Date input;
	istream >> input;
	istream.ignore();
	return input;
}

String IOController::readComment(std::istream& istream, std::ostream& ostream)
{
	ostream << "Do you want to add a comment to the reservation?: (if no press enter)" << std::endl;
	String input;
	istream >> input;
	if (input == "")
		input = "NO_COMmENT";

	return input;
}

String IOController::readName(String dateIndex, std::istream& istream, std::ostream& ostream)
{
	ostream << "Enter the " << dateIndex << " name:\n";
	String input;
	istream >> input;
	return input;
}
