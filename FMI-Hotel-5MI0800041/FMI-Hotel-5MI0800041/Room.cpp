#include "Room.h"

Room::Room(): id("NO_ID"), numberOfBeds(0), isOpen(0), comment("NO_COMMENT")
{
}

Room::Room(const String& id, const unsigned short numberOfBed, const bool isOpen, String comment): id(id), numberOfBeds(numberOfBed), isOpen(isOpen), comment(comment)
{
}

void Room::setIsOpen(bool status)
{
	this->isOpen = status;
}

bool Room::operator==(const Room& other)
{
	return this->getId() == other.getId();
}

bool Room::operator!=(const Room& other)
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Room& obj)
{
	const char SEPARATOR = ' ';
	stream << obj.getId() << SEPARATOR << obj.getNumberOfBeds() << SEPARATOR << obj.getIsOpen() << SEPARATOR << obj.getComment();
	return stream;
}

std::istream& operator>>(std::istream& stream, Room& obj)
{
	obj.id.get(' ', stream);
	stream >> obj.numberOfBeds;
	stream.ignore();
	stream >> obj.isOpen;
	stream.ignore();
	stream >> obj.comment;

	return stream;
}
