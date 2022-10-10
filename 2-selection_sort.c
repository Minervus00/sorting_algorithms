#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: the array to be sorted
 * @size: array's size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, imin;
	int swap;

	for (i = 0; i < size; i++)
	{
		imin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[imin])
				imin = j;
		}
		if (imin != i)
		{
			swap = array[i];
			array[i] = array[imin];
			array[imin] = swap;
			print_array(array, size);
		}
	}
}
