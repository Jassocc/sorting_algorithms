#include "sort.h"

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
    for (i = 0; (size_t)i < mid; i++)
    {
        printf("%d", left[i]);
        if ((size_t)i < mid - 1)
            printf(", ");
    }
    printf("\n");

    printf("[right]: ");
    for (i = 0; (size_t)i < size - mid; i++)
    {
        printf("%d", right[i]);
        if ((size_t)i < size - mid - 1)
            printf(", ");
    }
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
    for (i = 0; (size_t)i < size; i++)
    {
        printf("%d", array[i]);
        if ((size_t)i < size - 1)
            printf(", ");
    }
    printf("\n");

    free(left);
    free(right);
}
