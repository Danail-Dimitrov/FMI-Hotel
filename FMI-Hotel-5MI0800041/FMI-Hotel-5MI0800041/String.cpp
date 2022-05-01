 #include "String.h"
#include "HelperController.h"
#pragma warning(disable:4996)

void String::copy(const String& other)
{
	deleteMemory();
	setData(other.data);
}

void String::deleteMemory()
{
	delete[] this->data;
	this->data = nullptr;
}

std::istream& String::read(const char separator, std::istream& stream, int capacity)
{
	int size = 0;
	char* arr = new char[capacity];
	char crr;
	stream.get(crr);
	while (crr != separator && !stream.eof())
	{
		//+1 зада имам накрая място за \0
		if (size + 1 == capacity)
			HelperController::Resize(arr, capacity);

		arr[size] = crr;
		size++;
		stream.get(crr);
	}

	arr[size] = '\0';

	this->deleteMemory();
	this->setData(arr);

	return stream;
}

String::String()
{
	this->data = new char[1];
	this->data[0] = '\0';
}

String::String(const char* data): data(nullptr)
{
	setData(data);
}

String::String(const String& other): data(nullptr)
{
	copy(other);
}

void String::setData(const char* data)
{
	delete[] this->data;
	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
}

String& String::operator=(const String& other)
{
	//Ако двата обекта са един и същи и извикаме copy, хем ще се хабят време и ресурси, хем като изтрием паметта от сегашният, ще я изтрием и от обекта, от които искаме да копираме
	if (this == &other)
		return *this;

	copy(other);
	return *this;
}

void String::get(const char separator, std::istream& stream)
{
	read(separator, stream);
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

std::istream& operator>>(std::istream& stream, String& obj)
{	
	return obj.read('\n', stream, 500);
}