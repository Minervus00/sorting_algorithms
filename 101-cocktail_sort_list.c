#include "sort.h"

/**
 * swap_nodes - swap two nodes of a doubly linked list
 * @list: a pointer to list's head
 * @buff: the 1st node
 * @next: the 2nd node
 */
void swap_nodes(listint_t **list, listint_t *buff, listint_t *next)
{
	buff->next = next->next;
	next->prev = buff->prev;
	if (next->next)
		(next->next)->prev = buff;
	next->next = buff;
	if (buff->prev)
		(buff->prev)->next = next;
	else
		*list = next;
	buff->prev = next;
}

/**
 * sort_forward - bubble sort the list forward from lowfence to hifence
 * @list: the list to be sorted
 * @hifence: the high fence, from which sort stops
 * @lowfence: the low fence, from which sort begins
 * Return: 1 if any item has been swapped, 0 otherwise
 */
int sort_forward(listint_t **list, listint_t **hifence, listint_t **lowfence)
{
	listint_t *buff, *next;
	int swapped = 0;

	/* printf("forward\n"); */
	buff = ((*lowfence == NULL) ? *list : ((*lowfence)->next));
	while (buff->next != *hifence)
	{
		next = buff->next;
		if (buff->n > next->n)
		{
			/* Swap two nodes */
			swapped = 1;
			/* printf("swap: %d & %d -> ", buff->n, next->n); */
			swap_nodes(list, buff, next);
			print_list(*list);
		}
		buff = next;
	}
	*hifence = buff;
	/* printf("hifence: %d\n", (*hifence)->n); */
	return (swapped);
}

/**
 * sort_backward - bubble sort the list backward from hifence to lowfence
 * @list: the list to be sorted
 * @hifence: the high fence, from which sort begins
 * @lowfence: the low fence, from which sort stops
 * Return: 1 if any item has been swapped, 0 otherwise
 */
int sort_backward(listint_t **list, listint_t **hifence, listint_t **lowfence)
{
	listint_t *buff, *next = (*hifence)->prev;
	int swapped = 0;

	/* printf("backward - lowfence: %d\n", ((*lowfence) ? (*lowfence)->n : 0)); */
	while (next->prev != *lowfence)
	{
		buff = next->prev;
		if (buff->n > next->n)
		{
			/* Swap two nodes */
			swapped = 1;
			/* printf("swap: %d & %d -> ", buff->n, next->n); */
			swap_nodes(list, buff, next);
			print_list(*list);
		}
		next = buff;
	}
	*lowfence = next;
	/* printf("lowfence: %d\n", (*lowfence)->n); */
	return (swapped);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * It's a bidirectional bubble sort
 * @list: a pointer to the doubly linked list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *hifence = NULL, *lowfence = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = sort_forward(list, &hifence, &lowfence);
		if (!swapped)
			break;
		swapped = sort_backward(list, &hifence, &lowfence);
	}
}
