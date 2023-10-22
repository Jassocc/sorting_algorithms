#include "sort.h"

/**
 * counting_sort - sorts an array of integers
 * in ascending order
 * @array: the array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *outp;
	int max, a;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (a = 1; a < (int)size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	counter = malloc((max + 1) * sizeof(int));
	if (counter == NULL)
		return;
	outp = malloc(size * sizeof(int));
	if (outp == NULL)
	{
		free(counter);
		return;
	}
	for (a = 0; a <= max; a++)
		counter[a] = 0;
	for (a = 0; a < (int)size; a++)
		counter[array[a]]++;
	for (a = 1; a <= max; a++)
		counter[a] += counter[a - 1];
	print_array(counter, max + 1);
	for (a = 0; a < (int)size; a++)
	{
		outp[counter[array[a]] - 1] = array[a];
		counter[array[a]]--;
	}
	for (a = 0; a < (int)size; a++)
		array[a] = outp[a];
	free(counter);
	free(outp);
}
