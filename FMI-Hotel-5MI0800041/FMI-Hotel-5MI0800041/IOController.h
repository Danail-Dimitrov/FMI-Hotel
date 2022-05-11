#ifndef _IOCONTROLLER_H
#define _IOCONTROLLER_H
#include "String.h"
#include "Date.h"
#include "Room.h"
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

	static void printFreeRoomsStartMsg(Date date, std::ostream& stream = std::cout);

	static void printNthRoom(Room room, int n, std::ostream& stream = std::cout);

	static void printNoRoomsFound(const String& requirements = "", std::ostream& stream = std::cout);

	static void printPerfectRooms(const Room* rooms, unsigned count, std::ostream& stream = std::cout);

	static void printContrinueMsg(std::ostream& stream = std::cout);

	static void printFreedRoomMsg(std::ostream& stream = std::cout);

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

	static void readAnyKey(std::istream& stream = std::cin);

	/*! Чете номер на стая от даден поток
	* Връща:
	*		String - представляващо номер на стая
	*/
	static String readRoomId(std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static Date readDate(String dateName, std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static String readComment(std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static String readName(String dateIndex, std::istream& istream = std::cin, std::ostream& ostream = std::cout);

	static unsigned readNumberOfBeds(std::istream& istream = std::cin, std::ostream& ostream = std::cout);
};
#endif
