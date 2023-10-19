#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        prev_node = current->prev;
        next_node = current->next;

        while (prev_node && prev_node->n > current->n)
        {
            if (prev_node->prev)
                prev_node->prev->next = current;
            else
                *list = current;

            if (next_node)
                next_node->prev = prev_node;

            prev_node->next = next_node;
            current->prev = prev_node->prev;
            current->next = prev_node;
            prev_node->prev = current;

            if (current->prev)
                current->prev->next = current;

            print_list(*list);
            prev_node = current->prev;
        }

        current = next_node;
    }
}
