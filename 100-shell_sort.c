#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence.
 * sequence: U(n + 1) = U(n) * 3 + 1; U(0)=0
 * gap = [1, 4, 13, 40, 121, 364, 1093, ...]
 * @array: the array be sorted
 * @size:array's size
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, p, hi, lo, tmp;
	size_t k, gap[] = {1093, 364, 121, 40, 13, 4, 1};

	for (i = 0; i < 7; i++)
	{
		if (gap[i] >= size)
			continue;
		/*For each gap, k makes the sequence starting point move forward*/
		for (k = 0; k < size - gap[i]; k++)
		{
			for (p = 1; (p * gap[i]) + k < size; p++)
			{
				lo = ((p - 1) * gap[i]) + k;
				/*Sort the sequence with insertion sort*/
				while (lo >= 0)
				{
					hi = lo + gap[i];
					if (array[hi] < array[lo])
					{
						tmp = array[hi];
						array[hi] = array[lo];
						array[lo] = tmp;
					}
					lo = lo - gap[i];
				}
			}
			/**
			 * Avoid useless operations when gap == 1.
			 * Otherwise it will make (size - 1) times the final
			 * insertion sort, which must be done once
			 */
			if (gap[i] == 1)
				break;
		}
		print_array(array, size);
	}
}
