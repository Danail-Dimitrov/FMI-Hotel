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
	//TO DO :: add doxy comments
	String getRoomId() const { return roomId; }
	Date getStartDate() const { return startDate; }
	Date  getEndDate() const { return endDate; }
	String getFirstName() const { return firstName; }
	String getLastName() const { return lastName; }
	String getComment() const { return comment; }
	
	//Мутатори:
	void setIsActive(const bool isActive);
	void setComment(const String& comment);

	//Приятелски функции
	friend std::ostream& operator<<(std::ostream& stream, const RoomReservation obj);
	friend std::istream& operator>>(std::istream& stream, RoomReservation obj);
};
#endif 
