#ifndef ROOM_RESERVATION_H
#define ROOM_RESERVATION_H
#include "String.h"
#include "Date.h"
#include <iostream>
//! Основен клас, чиито обекти представляват резервации за стаи в хотела
class RoomReservation
{
private:
	//Член-данни
	String roomId;/*!< Номера на стаята */  
	Date startDate;/*!< Начлна дата за резервацията */  
	Date endDate;/*!< Крайна дата за резервацията */  
	String firstName;/*!< Първо име на клиента, направил резервацията */  
	String lastName;/*!< Фамилно име на клиента направил резервацията */  
	String comment;/*!< Коментар към резервацията */
	bool isActive;/*!< Флаг, които показва дали резервацията е ативна*/

	//TO DO:: Finish documentation (parametes)
	//!	Мутатор за начална и крайна дата
	/*!	При нормални обстоятелства за всяка член данна бихме искали отделен мутатор, но тъй като тук трябва да сравним една с друга двете член-данни за коректност направих един мутатор
	*/
	void setTimePeriod(const Date& startDate, const Date& endDate);

public:
	//Конструктори:
	//!	Конструктор по подразбиране
	RoomReservation();
	//!	Конструктор с параметри
	/*!
	*	Параметри:
	*		- String roomId
	*		- Date startDate
	*		- Date endDate
	*		- String firstName
	*		- String lastName
	*		- String comment
	*/
	RoomReservation(const String& roomId, const Date& startDate, const Date& endDate, const String& firstName, const String& lastName, const String& comment, const bool isActive);
	
	//Селектори:
	//!	Селектор за номер
	/*!
	*	Връща:
	*		String
	*/
	String getRoomId() const { return roomId; }
	//!	Селектор за начална дата 
	/*!
	*	Връща:
	*		Date
	*/
	Date getStartDate() const { return startDate; }
	//!	Селектор за край+на дата 
	/*!
	*	Връща:
	*		Date
	*/
	Date  getEndDate() const { return endDate; }
	//!	Селектор за първо име
	/*!
	*	Връща:
	*		String
	*/
	String getFirstName() const { return firstName; }
	//!	Селектор за второ име
	/*!
	*	Връща:
	*		String
	*/
	String getLastName() const { return lastName; }
	//!	Селектор за коментар
	/*!
	*	Връща:
	*		String
	*/
	String getComment() const { return comment; }
	//!	Селектор за флаг за състояние
	/*!
	*	Връща:
	*		bool 
	*		- истина акорезервацията е активна
	*		- лужа ако не е
	*/
	bool getIsActive() const { return isActive; }
	
	//Мутатори:
	//!	Мутатор за флаг за състояние
	/*!
	*	Параметри:
	*		- const bool isActive
	*/
	void setIsActive(const bool isActive);
	//!	Мутатор за коментар
	/*!
	*	Параметри:
	*		- const String& comment
	*/
	void setComment(const String& comment);

	bool operator== (const RoomReservation& other) const;

	bool operator!= (const RoomReservation& other) const;

	//Приятелски функции
	friend std::ostream& operator<<(std::ostream& stream, const RoomReservation& obj);
	friend std::istream& operator>>(std::istream& stream, RoomReservation& obj);
};
#endif 
