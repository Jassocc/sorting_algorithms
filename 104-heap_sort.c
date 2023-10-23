#include "sort.h"

/**
 * heapify - Perform heapify operation on subtree
 * @array: array
 * @size: size of array
 * @index: index to start heapify
 * @max: max size of array
 */
void heapify(int *array, size_t size, int index, size_t max)
{
	int greatest = index, temp;
	int left_node = 2 * index + 1;
	int right_node = 2 * index + 2;

	if (left_node < (int)size &&
		array[left_node] > array[greatest])
	{
		greatest = left_node;
	}
	if (right_node < (int)size &&
		array[right_node] > array[greatest])
	{
		greatest = right_node;
	}
	if (greatest != index)
	{
		temp = array[index];
		array[index] = array[greatest];
		array[greatest] = temp;
		print_array(array, max);
		heapify(array, size, greatest, max);
	}
}
/**
 * heap_sort - sorts an array of
 * integers in ascending order
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int a, temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (a = (size / 2) - 1; a >= 0; a--)
	{
		heapify(array, size, a, size);
	}
	for (a = size - 1; a > 0; a--)
	{
		temp = array[0];
		array[0] = array[a];
		array[a] = temp;
		print_array(array, size);
		heapify(array, a, 0, size);
	}
}
