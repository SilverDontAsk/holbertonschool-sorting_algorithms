#include "sort.h"
#include <stdio.h>
/**
 *swap - swap
 *@a: a
 *@b: b
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 *selection_sort - function that sorts an array of integers in ascending order
 *@array: array to be sorted
 *@size: size of the array
 *
 *
*/
void selection_sort(int *array, size_t size)
{
size_t i, j, min_idx;
int swapped;

for (i = 0; i < size - 1; i++)
{
min_idx = i;
swapped = 0;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_idx])
{
	min_idx = j;
	swapped = 1;
}
}
if (swapped)
{
swap(&array[min_idx], &array[i]);
print_array(array, size);
}
}
}
