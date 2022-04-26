#include "String.h"

void String::copy(const String& other)
{
	deleteMemory();
	unsigned size = strlen(other.data);
	this->data = new char[size + 1];
	strcpy(this->data, other.data);
}

void String::deleteMemory()
{
	delete[] this->data;
	this->data = nullptr;
}

String::String()
{
	this->data = new char[1];
	this->data[0] = '\0';
}

String::String(char* data)
{
	unsigned size = strlen(data);
	this->data = new char[size + 1];
	strcpy(this->data, data);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	//Ако двата обекта са един и същи и извикаме copy, хем ще се хабят време и ресурси, хем като изтрием паметта от сегашният, ще я изтрием и от обекта, от които искаме да копираме
	if (this == &other)
		return *this;

	copy(other);
	return *this;
}

String::~String()
{
	deleteMemory();
}

std::ostream& operator<<(std::ostream& stream, const String& obj)
{
	stream << obj.data;
	return stream;
}
