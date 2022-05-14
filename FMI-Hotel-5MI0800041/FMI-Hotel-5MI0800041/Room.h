#ifndef _ROOM_H
#define _ROOM_H
#include "String.h"
//! Основен клас, чиито обекти представляват стаи в хотела
class Room
{
private:
	//Член-данни:
	String id;/*!< Номера на стаята */  
	unsigned short numberOfBeds;/*!< Броя легла в стаята */
	bool isOpen;/*!< Флаг показващ дали стъаята в момента е затворена */
	String comment;

public:
	//Конструктори:
	//!Конструктор по бодразбиране
	Room();
	//! Конструктор с параметри
	/*! 
	*	Параметри:
	*		- String id
	*		- unsigned short numberOfBeds
	*		- bool isOpen
	*/
	Room(const String& id, const unsigned short numberOfBed, const bool isOpen, String comment);

	void setIsOpen(bool status);

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
	*		unsigned short
	*/
	unsigned short getNumberOfBeds() const { return this->numberOfBeds; }
	//! Селектор за флаг за състояние
	/*!	
	*	Връща:
	*		bool:
	*		-	истина ако стаята е отворена
	*		-	лъжа ако стаята е затворенас
	*/
	bool getIsOpen() const { return isOpen; }

	String getComment() const { return comment; }

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
	
	bool operator== (const Room& other);

	bool operator!= (const Room& other);
};
#endif
