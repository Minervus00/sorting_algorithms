#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_side - prints merging part elements
 * @arr: the main array
 * @side: the side's name (left or right / Done after sorting)
 * @start:starting index
 * @end: ending index
 */
void print_side(int *arr, char *side, int start, int end)
{
	int k;

	printf("[%s]: ", side);
	for (k = start; k < end; k++)
	{
		if (k != start)
			printf(", ");
		printf("%d", arr[k]);
	}
	printf("\n");
}

/**
 * top_down_merge - merge and sort two parts
 * @arr: the main array
 * @cpy: a copy of the array
 * @begin: partition's beginning
 * @mid: partition's middle
 * @end: partition's end index (excluded, i.e partition[end] doesn't exist)
 * @size: the main array size
 */
void top_down_merge(int *arr, int *cpy, int begin, int mid, int end, int size)
{
	int k, i = begin, j = mid;

	printf("Merging...\n");
	print_side(arr, "left", begin, mid);
	print_side(arr, "right", mid, end);
	for (k = begin; k < end; k++)
	{
		if (i < mid && (j >= end || arr[i] <= arr[j]))
		{
			cpy[k] = arr[i];
			i++;
		}
		else
		{
			cpy[k] = arr[j];
			j++;
		}
	}
	print_side(cpy, "Done", begin, end);
	for (k = 0; k < size; k++)
		arr[k] = cpy[k];
}

/**
 * top_down_split - split array in two halves recursively
 * @arr: the main array
 * @cpy: a copy of the array
 * @begin: the partition beginning index
 * @end: the partition end index (excluded, i.e partition[end] doesn't exist)
 * @size: the main array size
 */
void top_down_split(int *arr, int *cpy, int begin, int end, int size)
{
	int mid = end - begin;

	if (mid <= 1)
		return;
	mid = (mid + (2 * begin)) / 2;
	/* printf("Spliting right - %d to %d\n", begin, mid); */
	/* Split left until bottom is reached */
	top_down_split(arr, cpy, begin, mid, size);
	/* printf("Spliting left - %d to %d\n", mid, end);*/
	/* Split right until bottom reached */
	top_down_split(arr, cpy, mid, end, size);
	/* Sort and merge two parts */
	top_down_merge(cpy, arr, begin, mid, end, size);
}

/**
 * merge_sort -  sorts an array of integers in ascending order using
 * the top-down  Merge sort algorithm
 * @array: the array to be sorted
 * @size: array's size
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;
	size_t k;

	if (array == NULL || (int) size < 2)
		return;

	/* Create a copy of the main array */
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (k = 0; k < size; k++)
		cpy[k] = array[k];

	/* Split and merge the array recursively */
	top_down_split(array, cpy, 0, size, size);
	free(cpy);
}
