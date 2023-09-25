#include "sort.h"

/**
 * insertion_sort_list - Sort a list using insertion sort
 * @list: list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *head, *previous, *inner_next, *inner_previous;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	head = *list;
	next = head->next;
	previous = head;
	while (next)
	{
		inner_next = next;
		inner_previous = previous;
		while (inner_previous && inner_previous->n > inner_next->n)
		{
			if (inner_next->prev == NULL)
				next = inner_previous;
			if (inner_previous->prev == NULL)
				head = inner_next;
			if (inner_next->next != NULL)
				inner_next->next->prev = inner_previous;
			if (inner_previous->prev != NULL)
				inner_previous->prev->next = inner_next;
			inner_next->prev = inner_previous->prev;
			inner_previous->next = inner_next->next;
			inner_next->next = inner_previous;
			inner_previous->prev = inner_next;
			inner_previous = next->prev;
			print_list(head);
		}
		previous = next;
		next = next->next;
	}
	*list = head;
}
