#include "RoomReservation.h"

void RoomReservation::setTimePeriod(const Date& startDate, const Date& endDate)
{
	if(startDate > endDate)
		throw std::exception("The startDate must be before the endDate!");

	this->startDate = startDate;
	this->endDate = endDate;
}

RoomReservation::RoomReservation(): roomId("NO_ROOM"), startDate(Date()), endDate(Date()), firstName("NO_NAME"), lastName("NO_NAME"), comment("NO_COMMENT"), isActive(0)
{
}

RoomReservation::RoomReservation(const String& roomId, const Date& startDate, const Date& endDate, const String& firstName, const String& lastName, const String& comment, const bool isActive):
	roomId(roomId), firstName(firstName), lastName(lastName), isActive(isActive)
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

bool RoomReservation::operator==(const RoomReservation& other) const
{
	//Другите не трябва да се сравнят, защото програмта не допуска на две резервации с еднакви член-данни, каквито се сравняват
	return this->getRoomId() == other.getRoomId() && this->getStartDate() == other.getStartDate() &&  this->getEndDate() == other.getEndDate();
}

bool RoomReservation::operator!=(const RoomReservation& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const RoomReservation& obj)
{
	const char SEPARATOR = ' ';
	// obj.getComment() е важно да е накрая, заради четенето
	stream << obj.getRoomId() << SEPARATOR << obj.getStartDate() << SEPARATOR << obj.getEndDate() << SEPARATOR << obj.getFirstName() << SEPARATOR
		<< obj.getLastName() << SEPARATOR << obj.getIsActive() << SEPARATOR << obj.getComment();

	return stream;
}

std::istream& operator>>(std::istream& stream, RoomReservation& obj)
{
	Date startDate, endDate;
	obj.roomId.get(' ', stream);
	stream >> startDate;
	stream.ignore();
	stream >> endDate; 
	stream.ignore(); 
	obj.firstName.get(' ', stream);
	obj.lastName.get(' ', stream);
	stream >> obj.isActive;
	stream.ignore(); 
	stream >> obj.comment;

	obj.setTimePeriod(startDate, endDate);
	
	return stream;
}
