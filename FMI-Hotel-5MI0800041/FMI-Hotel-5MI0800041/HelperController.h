#ifndef _HELPER_CONTROLLER_H
#define _HELPER_CONTROLLER_H
#include <iostream>
#include "String.h"

class HelperController
{
public:
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
};
#endif
