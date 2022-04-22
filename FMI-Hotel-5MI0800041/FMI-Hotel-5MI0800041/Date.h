#ifndef DATE_H
#define DATE_H

class Date
{
private:
	//Size ranges from 0 to around 66k; Still very big but better than int
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;

	//We need to validated that the date is valid so it is better to 
	//have seter methods. For now there is no need to change values
	//of the properties outside of the class so they are private	
	void setDay(unsigned short int day);	
	void setMonth(unsigned short int month);
	void setYear(unsigned short int year);

public:
	Date();
	Date(unsigned short int day, unsigned short int month, unsigned short int year);

	bool operator< (const Date& other) const;
	bool operator> (const Date& other) const;
	bool operator== (const Date& other) const;
	bool operator!= (const Date& other) const;
};
#endif 