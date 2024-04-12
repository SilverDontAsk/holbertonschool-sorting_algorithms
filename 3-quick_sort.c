#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * swap - Swaps two integers in an array and prints the array after swap
 * @array: The array containing the integers to swap
 * @size: The size of the array
 * @a: Index of the first integer to swap
 * @b: second integer to swap
 * Return: nothing
 */
void swap(int *array, size_t size, int a, int b)
{
int temp = array[a];
array[a] = array[b];
array[b] = temp;
print_array(array, size);
}
/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;
for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
swap(array, size, i, j);
}
}
if (array[i + 1] != array[high])
{
swap(array, size, i + 1, high);
}
return (i + 1);
}
/**
 * quicksort_recursive - Recursive function to perform quicksort
 * @array: The array to sort
 * @low: Starting index of the array or partition
 * @high: Ending index of the array or partition
 * @size: Size of the array
 * Return: nothing
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
int pivot_index;
if (low < high)
{
pivot_index = lomuto_partition(array, low, high, size);
quicksort_recursive(array, low, pivot_index - 1, size);
quicksort_recursive(array, pivot_index + 1, high, size);
}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 * @array: The array to sort
 * @size: Size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort_recursive(array, 0, size - 1, size);
}
