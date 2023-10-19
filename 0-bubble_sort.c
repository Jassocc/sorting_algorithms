#include "sorth.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: the array containing ints
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	/* iterates from start till the second last element(size - 1) */
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		/**
		 * iterates through array and compares two adjacent elements
		 * swapping them when needed
		 */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		/**
		 * if no swap detected it means its sorted and breaks
		*/
		if (!swapped)
		{
			break;
		}
	}
}
