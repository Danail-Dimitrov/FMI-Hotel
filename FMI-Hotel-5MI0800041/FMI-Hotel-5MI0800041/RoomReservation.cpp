#include "RoomReservation.h"

void RoomReservation::setTimePeriod(const Date& startDate, const Date& endDate)
{
	if(startDate > endDate)
		throw "The startDate must be before the endDate!";

	this->startDate = startDate;
	this->endDate = endDate;
}

RoomReservation::RoomReservation()
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
