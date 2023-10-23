#include "sort.h"

/**
 * find_max - Returns max amount of elems
 * @array: array
 * @size: size of array
 * Return: max elem in array
 */
int find_max(int *array, size_t size)
{
	int maximum = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	return (maximum);
}
/**
 * count_sort - sorts array using counting
 * algorithm
 * @array: array
 * @size: size of array
 * @exp: current exponent
 */
void count_sort(int *array, size_t size, int exp, int *output)
{
	int counter[10] = {0};
	int i;

	for (i = 0; i < (int)size; i++)
	{
		counter[(array[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		counter[i] += counter[i - 1];
	}
	for (i = (int)size - 1; i >= 0; i--)
	{
		output[counter[(array[i] / exp) % 10] - 1] = array[i];
		counter[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	print_array(array, size);
}
/**
 * radix_sort - sorts an array of
 * integers in ascending order
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int maximum;
	int exp;
	int *b;

	b = malloc(sizeof(int) * size);
	maximum = find_max(array, size);
	if (array == NULL || size < 2)
	{
		return;
	}
	if (b == NULL)
	{
		return;
	}
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, b);
	}
	free(b);
}
