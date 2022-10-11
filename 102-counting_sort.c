#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * end_sort - ends the counting sort
 * @array: the main array
 * @new_array: the counting array
 * @size: array's size
 */
void end_sort(int *array, int *new_array, size_t size)
{
	int *arr2;
	size_t i;

	arr2 = malloc(sizeof(int) * size);
	if (arr2 == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		arr2[new_array[array[i]]] = array[i];
		new_array[array[i]]++;
	}
	/* print_array(arr2, size); */
	for (i = 0; i < size; i++)
		array[i] = arr2[i];
	free(arr2);
}

/**
 * counting_sort - orts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: the array to be sorted
 * @size: array's size
 */
void counting_sort(int *array, size_t size)
{
	int *new_arr, max = array[0];
	size_t i = 0, new_size;

	if (size < 0)
		return;
	/* Find the max and min num in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create the counting array and fill it with zeros*/
	new_size = max + 1;
	new_arr = malloc(sizeof(int) * new_size);
	if (new_arr == NULL)
		return;
	memset(new_arr, 0, sizeof(int) * new_size);

	/* Set the number of occurences*/
	for (i = 0; i < size; i++)
		new_arr[array[i]]++;

	/* Add each element to the left of it */
	for (i = 1; i < new_size; i++)
		new_arr[i] = new_arr[i] + new_arr[i - 1];
	print_array(new_arr, new_size);

	/* shift the array one step to right */
	for (i = new_size - 1; i >= 1; i--)
		new_arr[i] = new_arr[i - 1];
	new_arr[i] = 0;

	/**
	 * Create a new array with size as length, fill it with sorted value
	 * Duplicate its values into the main array
	 */
	end_sort(array, new_arr, size);
	free(new_arr);
}
