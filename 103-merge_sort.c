#include "sort.h"
#include <stdio.h>



void merge_sort(int *array, size_t size)
{
    size_t mid = size / 2;
    int *left;
    int *right;
    int i, j, k;

    if (size < 2)
    {
        return;
    }

    left = malloc(mid * sizeof(int));
    right = malloc((size - mid) * sizeof(int));
    for (i = 0; (size_t)i < mid; i++)
    {
        left[i] = array[i];
    }
    for (i = mid; (size_t)i < size; i++)
    {
        right[i - mid] = array[i];
    }

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, mid);
    printf("\n");

    printf("[right]: ");
    print_array(right, size - mid);
    printf("\n");

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    i = 0;
    j = 0;
    k = 0;
    while ((size_t)i < mid && (size_t)j < size - mid)
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while ((size_t)i < mid)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while ((size_t)j < size - mid)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array, size);
    printf("\n");

    free(left);
    free(right);
}
