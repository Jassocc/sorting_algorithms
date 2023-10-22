#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @list: Pointer to head
 * @left: 1st node
 * @right: 2nd node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{

	if (left->prev)
	{
		left->prev->next = right;
	}
	else
	{
		*list = right;
	}
	if (right->next)
	{
		right->next->prev = left;
	}
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - sorts a doubly linked
 * list of integers in ascending
 * @list: head of list
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *st, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	st = (*list);
	do {
		swap = 0;
		while (st->next)
		{
			end = st->next;
			if (end && st->n > end->n)
			{
				swap_nodes(list, st, end);
				swap = 1;
				print_list((*list));
			}
			else
			{
				st = st->next;
			}
		}
		st = st->prev;
		while (st->prev)
		{
			end = st->prev;
			if (end && st->n < end->n)
			{
				swap_nodes(list, end, st);
				swap = 1;
				print_list((*list));
			}
			else
			{
				st = st->prev;
			}
		}
		st = st->next;
	} while (swap);
}
