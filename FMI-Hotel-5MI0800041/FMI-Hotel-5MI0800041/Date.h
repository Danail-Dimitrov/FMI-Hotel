#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>

//! Помощен клас, които представлява дата
class Date
{
private:
	//Член-данни:
	unsigned short int day;/*!< Деня на датата */  
	unsigned short int month;/*!< Месеца на датата */  
	unsigned short int year;/*!< Годината на датата */  

public:
	//Конструктори:
	//!	Конструктор по подразбиране
	/*! Задава стойност нула на всички член-данни, по този начин маркира, че те нямат валидна стойност*/
	Date();
	/*! Първоначално използва инициализиращ лист, за да зададе стойности нула на всички член-данни.
	*	По този начин ако в констуктора се извика мутатора за ден преди тези за друготе член-данни ще има начин този мутатор да разбере, че месецът и годината нямат валидни стойности и не може да се валидира стойността на деня.
	*	
	*	Параметри:
	*		- unsigned short int day	  
	*		- unsigned short int month
	*		- unsigned short int year
	*/
	Date(unsigned short int day, unsigned short int month, unsigned short int year);

	//Мутатори:
	//!	Мутатор за ден
	/*!
	*	Нужно е годината и месецът вече да са инициализирани, за да може да се извърши коректна валидация на стойността за ден. Ако месецът и годината нямат зададени стойности, конструкторите ще се им задали стойност нула.
	*	
	*	Параметри:
	*		- unsigned short int day
	* 
	*	Ще се хвърли грешка ако:
	*		- другите член данни нямат зададена стойност
	*			-# годината не е зададена			   
	*			-# месеца не е зададен
	* 
	*		- стойността, която ще се присвои на член-данната ден не е валидна
	*			-# ако годината е високосна, месецът е 2 (февруари) и стоиността за ден е по висока от 29
	*			-# ако годината не е високосна, месецът е 2 (февруари) и стоиността за ден е по висока от 28
	*			-# ако даденият месец има 30 дни, но стойността за ден е по висока от 30
	*			-# ако стойността за ден е по висока от 31
	* 
	*		- деня има стойност 0
	*		  Нулата се ползва само, за да се покаже, че член-данната няма зададена стойност
	*/
	void setDay(unsigned short int day);
	//!	Мутатор за месец
	/*!
	*	Параметри:
	*		- unsigned short int month
	* 
	*	Ще се хвърли грешка ако:
	*		- месеца има стойност нула\n
	*		  Нулата се ползва само, за да се покаже, че член-данната няма зададена стойност
	* 
	*		- месеца има стойност по голяма от 12\n
	*/
	void setMonth(unsigned short int month);
	//! Мутатор за година
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

	//Селектори:
	//!	Селектор за ден
	/*!
	*	Връща:
	*		unsigned short int representing the day
	*/
	unsigned short int getDay() const { return this->day; }
	//!	Селектор за месец
	/*!
	*	Връща:
	*		unsigned short int representing the month
	*/
	unsigned short int getMonth() const { return this->month; }
	//!	Селектор за година
	/*!
	*	Връща:
	*		unsigned short int representing the year
	*/
	unsigned short int getYear() const { return this->year; }

	//Оператори:
	//!	Оператор <
	/*!
	*	Параметри:
	*		- const Date& other\n
	*		  датата, с която сравняваме сегашната
	* 
	*	Връща:
	*		- true\n
	*		  ако втората дата е след сегашната
	*		- false\n
	*		  ако втората дата е преди сегашната
	*/	
	bool operator< (const Date& other) const;
	//!	Оператор >
	/*!
	*	Параметри:
	*		- const Date& other\n
	*		  датата, с която сравняваме сегашната
	*
	*	Връща:
	*		- true\n
	*		  ако сегашната дата е след втората
	*		- false\n
	*		  ако сегашната дата е преди втората
	*/
	bool operator> (const Date& other) const;
	//!	Оператор ==
	/*!
	*	Параметри:
	*		- const Date& other\n
	*		  датата, с която сравняваме сегашната
	*
	*	Връща:
	*		- true\n
	*		  ако датите са еднакви
	*		- false\n
	*		  ако датите са различни
	*/
	bool operator== (const Date& other) const;
	//!	Оператор !=
	/*!
	*	Параметри:
	*		- const Date& other\n
	*		  датата, с която сравняваме сегашната
	*
	*	Връща:
	*		- true\n
	*		  ако датите са различни
	*		- false\n
	*		  ако датите са еднакви
	*/
	bool operator!= (const Date& other) const;

	//!	Oператор <<
	/*!
	*	Приятелска функция с която извеждаме данните за дата чрез поток
	* 
	*	Параметри:
	*		- std::ostream& stream
	*		- const Date& date
	*
	*	Връща:
	*		- std::ostream&
	*/
	friend std::ostream& operator<< (std::ostream& stream, const Date& date);

	//!	Oператор >> 
	/*!
	*	Приятелска функция, с която четем данни за датата от файл
	*
	*	Параметри:
	*		- std::istream& stream
	*		- const Date& date
	*
	*	Връша:
	*		- std::istream&
	*/
	friend std::ifstream& operator>> (std::ifstream& stream, Date& date);
};
#endif 