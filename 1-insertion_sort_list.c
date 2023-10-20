#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		prev_node = current;
		current = current->next;

		while (prev_node->prev != NULL && prev_node->n < prev_node->prev->n)
		{
			prev_node->prev->next = prev_node->next;

			if (prev_node->next != NULL)
			{
				prev_node->next->prev = prev_node->prev;
			}
			prev_node->next = prev_node->prev;
			prev_node->prev = prev_node->prev->prev;
			prev_node->next->prev = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = prev_node;
			else
				*list = prev_node;

			print_list(*list);
		}
	}
}
