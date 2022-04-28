#include "HelperController.h"

void HelperController::Resize(char* arr, int& size, int multiplier)
{
	int newSize = size * multiplier;
	char* newArr = new char[newSize + 1];
	for (size_t i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
	size = size * multiplier;
}
