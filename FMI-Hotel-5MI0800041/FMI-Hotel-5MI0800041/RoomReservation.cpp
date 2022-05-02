#include "RoomReservation.h"

void RoomReservation::setTimePeriod(const Date& startDate, const Date& endDate)
{
	if(startDate > endDate)
		throw "The startDate must be before the endDate!";

	this->startDate = startDate;
	this->endDate = endDate;
}

RoomReservation::RoomReservation(): roomId("NO_ROOM"), startDate(Date()), endDate(Date()), firstName("NO_NAME"), lastName("NO_NAME"), comment("NO_COMMENT"), isActive(0)
{
}

RoomReservation::RoomReservation(const String& roomId, const Date& startDate, const Date& endDate, const String& firstName, const String& lastName, const String& comment, const bool isActive):
	roomId(roomId), firstName(firstName), lastName(lastName)
{
	setTimePeriod(startDate, endDate);
	setComment(comment);
}

void RoomReservation::setIsActive(const bool isActive)
{
	this->isActive = isActive;
}

void RoomReservation::setComment(const String& comment)
{
	this->comment = comment;
}

std::ostream& operator<<(std::ostream& stream, const RoomReservation obj)
{
	const char SEPARATOR = ' ';
	// obj.getComment() е важно да е накрая, заради четенето
	stream << obj.getRoomId() << SEPARATOR << obj.getStartDate() << SEPARATOR << obj.getEndDate() << SEPARATOR << obj.getFirstName() << SEPARATOR
		<< obj.getLastName() << SEPARATOR << obj.getIsActive() << SEPARATOR << obj.getComment();

	return stream;
}

std::istream& operator>>(std::istream& stream, RoomReservation obj)
{
	//направи всички стрингове така
	Date startDate, endDate;
	obj.roomId.get(' ', stream);
	stream.ignore(); 
	stream >> startDate;
	stream.ignore();
	stream >> endDate; 
	stream.ignore(); 
	stream >> obj.firstName;
	stream.ignore();
	stream >> obj.lastName;
	stream.ignore(); 
	stream >> obj.isActive;
	stream.ignore(); 
	stream >> obj.comment;
	
	return stream;
}
