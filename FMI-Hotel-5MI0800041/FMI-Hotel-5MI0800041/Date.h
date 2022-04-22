#ifndef DATE_H
#define DATE_H
#include <iostream>

//! A class that represends a day of the year
class Date
{
private:
	//Fields:
	unsigned short int day;/*!< Represends a day of the month. */  
	unsigned short int month;/*!< Represends a mont of the year */  
	unsigned short int year;/*!< Represends a year */  

public:
	//Constructors:
	//!	Default constructor
	/*! Sets all fields to be zero, marking that they are not yet set */
	Date();
	//!	Constructor
	/*! Initialy all fields are set to be zero by initializer list.
	*	This is to ensure that if the day setter (setDay) is called before the others the day setter can throw exception about the other fields not being set.
	*	
	*	Parameters:
	*		- unsigned short int day\n
	*		  represents a day of a month
	*		- unsigned short int month\n
	*		  represents a month of a year
	*		- unsigned short int year\n
	*		  represents a year
	*/
	Date(unsigned short int day, unsigned short int month, unsigned short int year);

	//Setters:
	//!	Setter for the day field
	/*!
	*	Requires that the month and the year are set in order to properly validated that the day is valid.
	*	
	*	Parameters:
	*		- unsigned short int day
	*		  represents a day of a month
	* 
	*	Exception will be thrown if:
	*		- other fields are not set
	*			-# year not set\n
	*			   Initializer lists in constructor will mark it zero
	*			-# month not set\n
	*			   Initializer lists in constructor will mark it zero
	*		- the value for the day is invalid
	*			-# the year is a leap year and day is bigger than 29
	*			-# the year is not a leap year and day is bigger than 28
	*			-# the month has 30 days and the day is bigger than 30
	*			-# the month has 31 days and the day is bigger than 31
	*		- the day is zero\n
	*		  Zero is used by constructors to mark that the day is not set
	*/
	void setDay(unsigned short int day);
	//!	Setter for the month field
	/*!
	*	Parameters:
	*		- unsigned short int month
	*		  represents a month of a year
	* 
	*	Exception will be thrown if:
	*		- month is zero\n
	*		  Zero is used by constructors to mark that the month is not set
	*		- month is bigger than 12\n
	*		  Months can not be bigger than 12
	*/
	void setMonth(unsigned short int month);
	//!	Setter for the year field
	/*!
	*	Contains constants that determine the smallest and the biggest value that a year can have
	* 
	*	Parameters:
	*		- unsigned short int year\n
	*		  represents a year
	* 
	*	Exception will be thrown if:
	*		- year is outside of the allowed range\n
	*		  The allowed range for the years is determined by the constants in the setter
	*/
	void setYear(unsigned short int year);

	//Getters:
	//!	Getter for the day field
	/*!
	*	Returns:
	*		unsigned short int representing the day
	*/
	unsigned short int getDay() const { return day; }
	//!	Getter for the month field
	/*!
	*	Returns:
	*		unsigned short int representing the month
	*/
	unsigned short int getMonth() const { return month; }
	//!	Getter for the year field
	/*!
	*	Returns:
	*		unsigned short int representing the year
	*/
	unsigned short int getYear() const { return year; }

	//Operators:
	//!	Overwrite for the < operator
	/*!
	*	Parameters:
	*		- const Date& other\n
	*		  the date with which we compare the current date
	* 
	*	Returns:
	*		- true\n
	*		  if the other date is later than the current date (*this)
	*		- false\n
	*		  if the other date is earlier than the current date (*this)
	*/	
	bool operator< (const Date& other) const;
	//!	Overwrite for the > operator
	/*!
	*	Parameters:
	*		- const Date& other\n
	*		  the date with which we compare the current date
	*
	*	Returns:
	*		- true\n
	*		  if the current date (*this) is later than the other date
	*		- false\n
	*		  if the current date (*this) is earlier than the other date
	*/
	bool operator> (const Date& other) const;
	//!	Overwrite for the == operator
	/*!
	*	Parameters:
	*		- const Date& other\n
	*		  the date with which we compare the current date
	*
	*	Returns:
	*		- true\n
	*		  if the dates are the same
	*		- false\n
	*		  if the dates are different
	*/
	bool operator== (const Date& other) const;
	//!	Overwrite for the != operator
	/*!
	*	Parameters:
	*		- const Date& other\n
	*		  the date with which we compare the current date
	*
	*	Returns:
	*		- true\n
	*		  if the dates are different
	*		- false\n
	*		  if the dates the same
	*/
	bool operator!= (const Date& other) const;

	//!	Overwrite for the << operator
	/*!
	* A friend function that allows us to output dates 
	* 
	*	Parameters:
	*		- std::ostream& stream
	*		- const Date& date
	*
	*	Returns:
	*		- std::ostream&
	*/
	friend std::ostream& operator<< (std::ostream* stream, const Date& date);

	//!	Overwrite for the >> operator
	/*!
	* A friend function that allows us to output dates
	*
	*	Parameters:
	*		- std::istream& stream
	*		- const Date& date
	*
	*	Returns:
	*		- std::istream&
	*/
	friend std::istream& operator>> (std::istream& stream, const Date& date);
};
#endif 