#include "Date.h"

void Date::setDay(unsigned short int day)
{
	if(day == 0)
		throw "Invalid day!";
	//Year and month must be set in order to calculate 
	//how many days are in the given month. We will use 
	//zeros to indicate unset properties
	if(year == 0)
		throw "Year not set";

	if(month == 0)
		throw "Month not set";

	//Algorithm to determine if a year is leap year on line 17 is from https://www.mathsisfun.com/leap-years.html
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	if(month == 2 && day > 28 + isLeapYear)
		throw "Invalid day!";
	else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw "Invalid day!";
	else if (day > 31)
		throw "Invalid day!";

	this->day = day;
}

void Date::setMonth(unsigned short int month)
{
	if(month == 0 || month > 12)
		throw "Invalid month!";

	this->month = month;
}

void Date::setYear(unsigned short int year)
{
	const unsigned short int MIN_YEAR = 2022;
	const unsigned short int MAX_YEAR = 2050;

	if(year < MIN_YEAR || year > MAX_YEAR)
		throw "Invalid year!";

	this->year = year;
}

bool Date::operator<(const Date& other) const
{
	return year < other.year ||
		(year == other.year && month < other.month) ||
		(year == other.year && month == other.month && day < other.day);
}

bool Date::operator>(const Date& other) const
{
	return !(*this < other) && *this != other;
}

bool Date::operator==(const Date& other) const
{
	return year == other.year && month == other.month && day == other.day;
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
