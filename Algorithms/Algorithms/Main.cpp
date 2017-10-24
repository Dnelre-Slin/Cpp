#include <iostream>
#include <time.h>
#include "Sort.h"

void rndArray(int *arr, unsigned int size, unsigned int range = 100)
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

	rndArray(arr, a_size);

	printArr(arr, a_size);

	algo::shellSort(arr, a_size);

	printArr(arr, a_size);

	system("pause");
	return 0;
}