#include "Room.h"

Room::Room(): id("NO_ID"), numberOfBed(0), isOpen(0), comment("NO_COMMENT")
{
}

Room::Room(const String& id, const unsigned short numberOfBed, const bool isOpen, String comment): id(id), numberOfBed(numberOfBed), isOpen(isOpen), comment(comment)
{
}

std::ostream& operator<<(std::ostream& stream, const Room& obj)
{
	const char SEPARATOR = ' ';
	stream << obj.getId() << SEPARATOR << obj.getNumberOfBed() << SEPARATOR << obj.getIsOpen() << SEPARATOR << obj.getComment();
	return stream;
}

std::istream& operator>>(std::istream& stream, Room& obj)
{
	obj.id.get(' ', stream);
	stream >> obj.numberOfBed;
	stream.ignore();
	stream >> obj.isOpen;
	stream.ignore();
	stream >> obj.comment;

	return stream;
}
