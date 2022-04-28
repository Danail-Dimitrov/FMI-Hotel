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

String::~String()
{
	deleteMemory();
}

std::ostream& operator<<(std::ostream& stream, const String& obj)
{
	stream << obj.data;
	return stream;
}

//Оправи в бъдеще
std::istream& operator>>(std::istream& stream, String& obj)
{	
	int capacity = 501;
	int size = 0;
	char* arr = new char[capacity];
	char crr;
	stream.get(crr);
	while(crr != '\n' && !stream.eof())
	{
		//+1 зада имам накрая място за \0
		if (size + 1 == capacity)
			HelperController::Resize(arr, capacity);

		arr[size] = crr;
		size++;
		stream.get(crr);
	}

	arr[size] = '\0';

	obj.deleteMemory();
	obj.setData(arr);

	return stream;
}