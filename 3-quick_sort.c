#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - sorts a partition of the array using Quick sort
 * @arr: a pointer to the array
 * @low: the lowest index in the partition
 * @hi: the highest index in the partition
 * Return: nothing
 */
void lomuto_partition(int *arr, int low, int hi, size_t size)
{
	int pivot, j, i, tmp;

	if (low >= hi)
		return;

	pivot = arr[hi];
	j = low;
	for (i = low; i < hi; i++)
	{
		if (arr[i] <= pivot)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			if (i != j)
				print_array(arr, size);
			j++;
		}
	}
	tmp = arr[hi];
	arr[hi] = arr[j];
	arr[j] = tmp;
	if (hi != j)
		print_array(arr, size);

	lomuto_partition(arr, low, j - 1, size);
	lomuto_partition(arr, j + 1, hi, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm  with the Lomuto partition scheme
 * @array: pointer the array
 * @size: array's size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto_partition(array, 0, size - 1, size);
}
