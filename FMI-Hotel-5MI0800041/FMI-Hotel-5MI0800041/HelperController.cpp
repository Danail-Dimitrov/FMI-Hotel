#include "HelperController.h"

void HelperController::resize(char* arr, unsigned& size, int multiplier)
{
	int newSize = size * multiplier;
	char* newArr = new char[newSize + 1];
	for (size_t i = 0; i < size; ++i)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
	size = size * multiplier;
}

String HelperController::convertNumToChar(long number)
{
	String result;

	if(number == 0)	
	{
		result = '0';
		return result;
	}
		
	while(number != 0)
	{
		char crrDigit = (number % 10) + '0';
		result += crrDigit;
		number /= 10;
	}

	return result;
}

