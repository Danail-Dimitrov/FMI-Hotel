#include "Date.h"

void Date::setDay(unsigned short int day)
{
	if(this->day == 0)
		throw "Invalid day!";
	
	//Трябва да има зададена стойност на член-данните month(месец) и year(година), за да може да се провери коректността на стойността, която искаме да зададем на член-данната day (ден)
	//Конструкторите използват стойността 0, за да маркират, че на дадена член-данна няма зададена стойност
	if(this->year == 0)
		throw "Year not set";

	if(this->month == 0)
		throw "Month not set";

	//Израза на ред 17, които проверя дали една година е високосна, е направен на база информацията от страницата: https://www.mathsisfun.com/leap-years.html
	bool isLeapYear = (this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0;

	if(this->month == 2 && this->day > 28 + isLeapYear)
		throw "Invalid day!";
	else if((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && this->day > 30)
		throw "Invalid day!";
	else if (this->day > 31)
		throw "Invalid day!";

	this->day = day;
}

void Date::setMonth(unsigned short int month)
{
	if(this->month == 0 || this->month > 12)
		throw "Invalid month!";

	this->month = month;
}

void Date::setYear(unsigned short int year)
{
	const unsigned short int MIN_YEAR = 2022;
	const unsigned short int MAX_YEAR = 2050;

	if(this->year < MIN_YEAR || this->year > MAX_YEAR)
		throw "Invalid year!";

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

bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}

Date::Date(): day(0), month(0), year(0)
{
}

//We are useing initializer lists because if setDay is called before setMonth and setYear the day
//can not be set properly but the zeros indicate that they are not set so an exception can be thrown
Date::Date(unsigned short int day, unsigned short int month, unsigned short int year) : day(0), month(0), year(0)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	stream << date.getDay() << date.getMonth() << date.getYear();
	return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Date& date)
{
	stream >> date.day >> date.month >> date.year;
	return stream;
}