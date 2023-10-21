#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (n < size / 3)
	{
		n = n * 3 + 1;
	}
	while (n >= 1)
	{
		for (i = n; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		n /= 3;
	}
}
