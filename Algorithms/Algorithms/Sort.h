#pragma once

namespace algo
{
	template <class T>
	void shellSort(T *arr, unsigned int size)
	{
		for (unsigned int gap = size / 2; gap >= 1; gap /= 2)
		{
			for (unsigned int i = 1; i < size; i += gap)
			{
				unsigned int j = i;
				while (j > 0 && arr[j] < arr[j - 1])
				{
					swap(arr, j, j - 1);
					j--;
				}
			}
		}
	}

	template <class T>
	void swap(T *arr, unsigned int i1, unsigned int i2)
	{
		T temp;
		temp = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = temp;
	}
}