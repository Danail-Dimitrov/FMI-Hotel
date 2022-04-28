#include "Room.h"

Room::Room(): id(0), numberOfBed(0)
{
}

Room::Room(String id, unsigned short int numberOfBed): id(id), numberOfBed(numberOfBed)
{
}

std::ostream& operator<<(std::ostream& stream, const Room& obj)
{
	stream << obj.getId() << " " << obj.getNumberOfBed();
	return stream;
}

std::istream& operator>>(std::istream& stream, Room& obj)
{
	stream >> obj.id;
	stream.ignore();
	stream >> obj.numberOfBed;

	return stream;
}
