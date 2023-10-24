#include "sort.h"

/**
 * bitonic_merge - merge two arrays
 * @array: array
 * @size: size
 * @st: start of array
 * @sq: sequence of array
 * @dir: sorting direction
 */
void bitonic_merge(int *array, size_t size, size_t st, size_t sq, int dir)
{
	size_t k = sq / 2, i;
	int temp;

	if (sq > 1)
	{
		for (i = st; i < st + k; i++)
		{
			if ((dir == 1 && array[i] > array[i + k]) ||
				(dir == 0 && array[i] < array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		bitonic_merge(array, size, st, k, dir);
		bitonic_merge(array, size, st + k, k, dir);
	}
}
/**
 * bitonic_recursive - recursive function for sort
 * @array: array
 * @size: size
 * @dir: sorting direction
 * @st: start of array
 * @sq: sequence of array
 */
void bitonic_recursive(int *array, size_t size, size_t st, size_t sq, int dir)
{
	int k = sq / 2;

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size,
				dir == 1 ? "UP" : "DOWN");
		print_array(array + st, sq);
		bitonic_recursive(array, size, st, k, 1);
		bitonic_recursive(array, size, st + k, k, 0);
		bitonic_merge(array, size, st, sq, dir);
		printf("Result [%lu/%lu] (%s):\n", sq, size,
				dir == 1 ? "UP" : "DOWN");
		print_array(array + st, sq);
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
	bitonic_recursive(array, size, 0, size, 1);
}
