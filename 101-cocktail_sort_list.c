#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @list: Pointer to head
 * @node1: 1st node
 * @node2: 2nd node
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
	listint_t *st = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swap)
	{
		swap = 0;
		while (st->next != end)
		{
			if (st->n > st->next->n)
			{
				swap_nodes(list, st, st->next);
				print_list(*list);
				swap = 1;
			}
			else
			{
				st = st->next;
			}
		}
		if (!swap)
			break;
		swap = 0;
		end = st;
		while (st->prev != NULL)
		{
			if (st->n < st->prev->n)
			{
				swap_nodes(list, st->prev, st);
				print_list(*list);
				swap = 1;
			}
			else
			{
			st = st->prev;
			}
		}
	}
}
