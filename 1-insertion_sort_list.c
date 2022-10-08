#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list's head
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buff = *list, *tmp, *prev, *next;

	if (buff == NULL || buff->next == NULL)
		return;
	while(buff)
	{
		next = buff->next;
		tmp = next;
		prev = buff->prev;
		while (prev)
		{
			if (buff->n >= prev->n)
			{
				if (prev == buff->prev)
					break;
				/* printf("swapping ", prev->n); */
				prev->next = buff;
				buff->prev = prev;
				buff->next = tmp;
				tmp->prev = buff;
				print_list(*list);
				break;
			}
			prev->next = tmp;
			if (tmp)
				tmp->prev = prev;
			tmp = prev;
			prev = prev->prev;
			if (prev == NULL)
			{
				/* printf("swap to head -> "); */
				*list = buff;
				buff->next = tmp;
				tmp->prev = buff;
				buff->prev = prev;
				print_list(*list);
			}
		}
		buff = next;
	}
}
