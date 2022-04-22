#include "Date.h"

void Date::setDay(unsigned short int day)
{
	//Year and month must be set in order to calculate 
	//how many days are in the given month. We will use 
	//zeros to indicate unset properties
	if(year == 0)
		throw "Year not set";
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
