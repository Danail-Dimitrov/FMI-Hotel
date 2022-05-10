#include "Room.h"

Room::Room(): id("NO_ID"), numberOfBed(0), isOpen(0)
{
}

Room::Room(const String& id, const unsigned short numberOfBed, const bool isOpen): id(id), numberOfBed(numberOfBed), isOpen(isOpen)
{
}

std::ostream& operator<<(std::ostream& stream, const Room& obj)
{
	stream << obj.getId() << " " << obj.getNumberOfBed() << " " << obj.getIsOpen();
	return stream;
}

std::istream& operator>>(std::istream& stream, Room& obj)
{
	obj.id.get(' ', stream);
	stream >> obj.numberOfBed;
	stream.ignore();
	stream >> obj.isOpen;

	return stream;
}
