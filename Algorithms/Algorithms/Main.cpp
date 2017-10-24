#include <iostream>
#include <string>
#include <time.h>
#include "Sort.h"

void rndStringArray(std::string *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		unsigned int length = (rand() % 10) + 5;
		for (unsigned int j = 0; j < length; j++)
		{
			arr[i].push_back((rand() % 26) + 65);
		}
	}
}

void rndIntArray(int *arr, unsigned int size, unsigned int range = 100)
{
	for (unsigned int i = 0; i < size; i++)
	{
		arr[i] = rand() % range;
	}
}

template <class T>
void printArr(T *arr, unsigned int size)
{
	std::cout << "[   ";
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "   ";
	}
	std::cout << "]\n";
}

int main()
{
	srand(time(NULL));

	const unsigned int a_size = 20;

	int arr[a_size];

	rndIntArray(arr, a_size);

	printArr(arr, a_size);

	algo::shellSort(arr, a_size);

	printArr(arr, a_size);

	std::cout << "\n\n";

	std::string s_arr[a_size];

	rndStringArray(s_arr, a_size);

	printArr(s_arr, a_size);
	std::cout << "\n";

	algo::shellSort(s_arr, a_size);

	printArr(s_arr, a_size);

	system("pause");
	return 0;
}