#include "Date.h"

void Date::setDay(const unsigned short day)
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
	

	if(day > getDaysInMonth(this->month, this->year))
		throw std::exception("Invalid day!");

	this->day = day;
}

void Date::setMonth(const unsigned short month)
{
	if(month == 0 || month > 12)
		throw std::exception("Invalid month!");

	this->month = month;
}

void Date::setYear(const unsigned short year)
{
	const unsigned short MIN_YEAR = 2022;
	const unsigned short MAX_YEAR = 2050;

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

bool Date::isLeapYear(unsigned short year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

unsigned Date::getDaysInMonth(unsigned short month, unsigned short year)
{
	if (month == 2)
		return 28 + isLeapYear(year);
	if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
		return 30;

	return 31;
}

unsigned Date::operator-(const Date& other)
{
	if (*this < other)
		throw std::exception("First date must be greater!");

	unsigned days = 0;
	
	//Чупим правилата на сетърите, позволявам си го, защото този обект реално не се ползва, за да представи дата
	Date counterDate = other;
	
	while(counterDate <= *this)
	{
		++days;

		counterDate.day = counterDate.getDay() + 1;

		//Ако сме минали в нова година
		if(counterDate.getDay() == 32 && counterDate.getMonth() == 12)
		{
			counterDate.year = counterDate.getYear() + 1;
			counterDate.day = 1;
			counterDate.month = 1;
		}
		else if(counterDate.getDay() > getDaysInMonth(counterDate.getMonth(), counterDate.getYear()))
		{
			counterDate.day = 1;
			counterDate.month = counterDate.getMonth() + 1;
		}
	}

	return days;
}

Date::Date(): day(0), month(0), year(0)
{
}

Date::Date(const unsigned short day, const unsigned short month, const unsigned short year) : day(0), month(0), year(0)
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
	unsigned short day, month, year;
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