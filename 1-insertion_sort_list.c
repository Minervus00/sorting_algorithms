#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list's head
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buff = *list, *prev, *next, *next_cmp;

	if (buff == NULL || buff->next == NULL)
		return;

	next_cmp = buff->next;
	while (next_cmp)
	{
		buff = next_cmp;
		next_cmp = buff->next;
		prev = buff->prev;
		/*printf("current: %d | next_cmp: %d\n", buff->n);*/
		while (prev)
		{
			if (buff->n >= prev->n)
				break;
			/* Swapping buff and prev */
			/*printf("swapping  with %d -> ", prev->n);*/
			next = buff->next;
			buff->prev = prev->prev;
			if (buff->next)
				(buff->next)->prev = prev;
			buff->next = prev;
			prev->next = next;
			if (prev->prev)
				(prev->prev)->next = buff;
			else
				*list = buff;
			prev->prev = buff;
			print_list(*list);
			prev = buff->prev;
		}
	}
}
