#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: pointer the array
 * @size: array's size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, fence =  size;
	int tmp, swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < fence; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped)
			fence--;
	}
}
