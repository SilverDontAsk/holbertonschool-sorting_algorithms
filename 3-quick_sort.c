#include "sort.h"
#include <stdlib.h>
/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
print_array(array, size);
quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function to perform quicksort
 * @array: The array to sort
 * @low: The lower index of the subarray
 * @high: The higher index of the subarray
 */
void quicksort_recursive(int *array, int low, int high)
{
int pi;
if (low < high)
{
pi = partition(array, low, high);
print_array(array, high - low + 1);
quicksort_recursive(array, low, pi - 1);
quicksort_recursive(array, pi + 1, high);
}
}
/**
 * partition - Chooses a pivot and partitions the array around it using Lomuto's partition scheme
 * @array: The array to partition
 * @low: The lower index of the subarray
 * @high: The higher index of the subarray
 * Return: The final position of the pivot after partitioning
 */
int partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1, j;
for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
swap(&array[i], &array[j]);
}
}
swap(&array[i + 1], &array[high]);
return (i + 1);
}
/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
