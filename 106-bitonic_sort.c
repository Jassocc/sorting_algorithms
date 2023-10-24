#include "sort.h"

/**
 * bitonic_merge - merge two arrays
 * @array: array
 * @size: size
 * @dir: sorting direction
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t k, i;
	int temp;

	if (size > 1)
	{
		k = size / 2;
		for (i = 0; i < k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		bitonic_merge(array, k, dir);
		bitonic_merge(array + k, k, dir);
	}
}
/**
 * bitonic_recursive - recursive function for sort
 * @array: array
 * @size: size
 * @dir: sorting direction
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
	int k;

	if (size > 1)
	{
		k = size / 2;
		printf("Merging [%ld/%ld] (%s):\n", size, size,
				dir == 1 ? "UP" : "DOWN");
		print_array(array, size);
		bitonic_recursive(array, k, 1);
		bitonic_recursive(array + k, k, 0);
		bitonic_merge(array, size, dir);
		printf("Result [%ld/%ld] (%s):\n", size, size,
				dir == 1 ? "UP" : "DOWN");
		print_array(array, size);
	}
}
/**
 * bitonic_sort - Sort an array using bitonic sort
 * @array: array
 * @size: size of aray
 */
void bitonic_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
	{
		return;
	}
	bitonic_recursive(array, size, 1);
}
