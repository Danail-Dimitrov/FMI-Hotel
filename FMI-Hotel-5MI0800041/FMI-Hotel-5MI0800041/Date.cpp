#include "Date.h"

void Date::setDay(const unsigned short int day)
{
	if(day == 0)
		throw std::exception("Invalid day!");
	
	//Трябва да има зададена стойност на член-данните month(месец) и year(година), за да може да се провери коректността на стойността, която искаме да зададем на член-данната day (ден)
	//Конструкторите използват стойността 0, за да маркират, че на дадена член-данна няма зададена стойност
	if(this->year == 0)
		throw std::exception("Year not set");

	if(this->month == 0)
		throw std::exception("Month not set");

	//Израза на ред 17, които проверя дали една година е високосна, е направен на база информацията от страницата: https://www.mathsisfun.com/leap-years.html
	bool isLeapYear = (this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0;

	if(this->month == 2 && day > 28 + isLeapYear)
		throw std::exception("Invalid day!");
	else if((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && day > 30)
		throw std::exception("Invalid day!");
	else if (day > 31)
		throw std::exception("Invalid day!");

	this->day = day;
}

void Date::setMonth(const unsigned short int month)
{
	if(month == 0 || month > 12)
		throw std::exception("Invalid month!");

	this->month = month;
}

void Date::setYear(const unsigned short int year)
{
	const unsigned short int MIN_YEAR = 2022;
	const unsigned short int MAX_YEAR = 2050;

	if(year < MIN_YEAR || year > MAX_YEAR)
		throw std::exception("Invalid year!");

	this->year = year;
}

bool Date::operator<(const Date& other) const
{
	return this->getYear() < other.getYear() ||
		(this->getYear() == other.getYear() && this->getMonth() < other.getMonth()) ||
		(this->getYear() == other.getYear() && this->getMonth() == other.getMonth() && this->getDay() < other.getDay());
}

bool Date::operator>(const Date& other) const
{
	return !(*this < other) && *this != other;
}

bool Date::operator==(const Date& other) const
{
	return this->getYear() == other.getYear() && this->getMonth() == other.getMonth() && this->getDay() == other.getDay();
}

bool Date::operator<=(const Date& other) const
{
	return *this < other || *this == other;
}

bool Date::operator>=(const Date& other) const
{
	return *this > other || *this == other;
}

bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}

Date::Date(): day(0), month(0), year(0)
{
}

Date::Date(const unsigned short int day, const unsigned short int month, const unsigned short int year) : day(0), month(0), year(0)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

std::ostream& operator<<(std::ostream& stream, const Date& obj)
{
	const char SEPARATOR = '/';
	stream << obj.getDay() << SEPARATOR << obj.getMonth() << SEPARATOR << obj.getYear();
	return stream;
}

std::istream& operator>>(std::istream& stream, Date& obj)
{
	unsigned short int day, month, year;
	stream >> day; 
	stream.ignore();
	stream >> month; 
	stream.ignore();
	stream >> year;

	obj.setYear(year);
	obj.setMonth(month);
	obj.setDay(day);

	return stream;
}