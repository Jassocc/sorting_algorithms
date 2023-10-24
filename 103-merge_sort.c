#include "sort.h"

/**
 * merge - merge two sorted arrays
 * @array: original array
 * @left: left subarray
 * @right: right subarray
 * @size_l: size of left subarray
 * @size_r: size of right subarray
 */
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_l + size_r) * sizeof(int));

	if (!temp)
	{
		free(temp);
		return;
	}
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);
	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < size_l)
		temp[k++] = left[i++];
	while (j < size_r)
		temp[k++] = right[j++];
	for (i = 0; i < size_l + size_r; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, size_l + size_r);
	free(temp);
}
/**
 * merge_sort - perform merge sort
 * @array: original array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i;
	int *left, *right;

	if (size < 2 || array == NULL)
	{
		return;
	}
	left = malloc(mid * sizeof(int));
	right = malloc((size - mid) * sizeof(int));
	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}
	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, mid, size - mid);
	free(left);
	free(right);
}
