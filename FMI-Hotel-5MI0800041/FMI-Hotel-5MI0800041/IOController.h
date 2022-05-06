﻿#ifndef _IOCONTROLLER_H
#define _IOCONTROLLER_H
#include "String.h"
#include "Date.h"
class IOController
{
public:
	//Методи:
	// Методи за печатане:
	//!Поздрав
	/*! Изпечатва основното поздрава за програмата */
	static void prindGreeting(std::ostream& stream = std::cout);

	//!Основно меню
	/*! Изпечатва основното меню, съдържащо командите за програмата */
	static void printMenu(std::ostream& stream = std::cout);
	
	//!Изчиства конзолата
	static void clearScreen();

	//Методи за четене:
	/*! Чете един символ, число, представляващо избраната команта
	* Връща:
	*		char -представляващо командата
	* 
	* Грешка ще се хвърли ако:
	*	- Char command not valid\n
	*	  Символът не е число или не е между 1 и 6 (има 6 команди)
	*/
	static char readMenuInput(std::istream& stream = std::cin);

	/*! Чете номер на стая от даден поток
	* Връща:
	*		String - представляващо номер на стая
	*/
	static String readRoomId(std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static Date readDate(String dateIndex, std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static String readComment(std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static String readName(String dateIndex, std::istream& istream = std::cin, std::ostream& ostream = std::cout);
};
#endif
