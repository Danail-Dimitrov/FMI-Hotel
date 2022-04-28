#ifndef _ROOM_H
#define _ROOM_H
#include "String.h"
//! Основен клас, чиито обекти представляват стаи в хотела
class Room
{
private:
	//Член-данни:
	String id;/*!< Номера на стаята */  
	unsigned short int numberOfBed;/*!< Броя легла в стаята */

public:
	//Конструктори:
	//!Конструктор по бодразбиране
	Room();
	//! Конструктор с параметри
	/*! 
	*	Параметри:
	*		- unsigned short int day
	*		- unsigned short int month
	*		- unsigned short int year
	*/
	Room(String id, unsigned short int numberOfBed);

	//Селектори:
	//!	Селектор за номер
	/*!
	*	Връща:
	*		String
	*/
	String getId() const { return this->id; }
	//!	Селектор за брой легла
	/*!
	*	Връща:
	*		unsigned short int
	*/
	unsigned short int getNumberOfBed() const { return this->numberOfBed; }

	//Оператори:
	//!	Oператор <<
	/*!
	*	Приятелска функция с която извеждаме данните за стаята чрез поток
	*
	*	Параметри:
	*		- std::ostream& stream
	*		- const Room& obj
	*
	*	Връща:
	*		- std::ostream&
	*/
	friend std::ostream& operator<< (std::ostream& stream, const Room& obj);
	//!	Oператор >> 
	/*!
	*	Приятелска функция, с която четем данни за стаята от поток
	*
	*	Данните се задават на член-данните чрез мутаторите, за да могат да сеизпълнят валидациите
	*
	*	Ще се хвърли грешка ако:
	*		- входните данни не отговарят на критерийте в мутаторите (грешката се мята в мутатора)
	*
	*	Параметри:
	*		- std::istream& stream
	*		- const Room& obj
	*
	*	Връша:
	*		- std::istream&
	*/
	friend std::istream& operator>> (std::istream& stream, Room& obj);
};
#endif
