#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *x, int *y);
size_t partition(int array[], size_t size);
void print_sort(int array[], size_t size, int init);

/**
 * quick_sort - the function that initiate the quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	pivot = partition(array, size);

	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}

/**
 * swap - function that swaps two numbers
 * @x: fisrt numbers
 * @y: second numbers
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

/**
 * partition - Function that sets the pivot for quick_sort
 * @array: Array to partition
 * @size: Size of array
 * Return: the pivot
 */

size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i + 1);
}

/**
 * print_sort - Function that prints as it should
 * @array: Array to be printed
 * @size: Size of array
 * @init: Should initialize array
 */

void print_sort(int array[], size_t size, int init)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
