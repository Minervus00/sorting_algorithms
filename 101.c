#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence 
 * sequence: U(n + 1) = U(n) * 3 + 1; U(0)=0 
 * gap = [1, 4, 13, 40, 121, 364, 1093, ...]
 * @array: the array be sorted
 * @size:array's size
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, p, j, tmp;
	size_t gap, gaps[] = {1093, 364, 121, 40, 13, 4, 1};

	for (i = 0; i < 7; i++)
	{
		gap = gaps[i];
		for (p = gap; p < (int) size; p++)
		{
			tmp = array[i];
			for (j = i; (j >= (int) gap) && (array[j - gap] > tmp); j = j - gap)
				array[j] = array[j - gap];
		}
		array[j] = tmp;
		print_array(array, size);
	}
}
