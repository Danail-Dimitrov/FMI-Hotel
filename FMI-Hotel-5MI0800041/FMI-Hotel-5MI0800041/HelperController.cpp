#include "HelperController.h"

HelperController& HelperController::getHelperController()
{
	static HelperController helperController;
	return helperController;
}

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

	reverse(result.getData());

	return result;
}

Date HelperController::getLaterDate(const Date& date1, const Date& date2)
{
	return date1 >= date2 ? date1 : date2;
}

Date HelperController::getEarlierDate(const Date& date1, const Date& date2)
{
	return date1 <= date2 ? date1 : date2;
}

bool HelperController::doTimePeriodsCross(const Date& date1Start, const Date& date1End, const Date& date2Start, const Date& date2End)
{
	return date1Start <= date2End && date1End >= date2Start;
}

void HelperController::reverse(char* arr)
{
	unsigned arrLen = strlen(arr);
	for (size_t i = 0; i < arrLen / 2; i++)
	{
		char temp = arr[i];
		unsigned swapIndex = arrLen - i - 1;
		arr[i] = arr[swapIndex];
		arr[swapIndex] = temp;
	}
}

