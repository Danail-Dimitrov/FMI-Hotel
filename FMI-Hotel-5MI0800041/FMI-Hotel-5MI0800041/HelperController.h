#ifndef _HELPER_CONTROLLER_H
#define _HELPER_CONTROLLER_H
#include <iostream>
#include "String.h"
#include "Date.h"

class HelperController
{
public:
	static HelperController& getHelperController();
	//! Преразмеряване на масив
	/*! Променя дълцината на масив от символи с даден размер 
	* Приема :
	*	- char* arr\n
	*	  Масива, които ще преразмеряваме
	*	- int& size\n
	*	  Първоначалният размер на масива
	*	- int multiplier\n
	*	  Показва колко пъти ще се увеличи размера на масива (първоначално = 2)
	*/
	static void resize(char* arr, unsigned& size, int multiplier = 2);

	static String convertNumToChar(long number);

	static Date getLaterDate(const Date& date1, const Date& date2);

	static Date getEarlierDate(const Date& date1, const Date& date2);

	static bool doTimePeriodsCross(const Date& date1Start, const Date& date1End, const Date& date2Start, const Date& date2End);

	static void reverse(char* arr);
};
#endif
