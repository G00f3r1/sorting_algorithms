#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

/**
 * quick_sort - the function that initiate the quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1);

}

/**
 * swap - function that swap two numbers
 * @a: the first number
 * @b: the second number
 */


void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * partition - function that takes last element as pivot
 * @arr: the array to be sorted
 * @low: the starting index
 * @high: the ending index
 * Return: int value
 */

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * quickSort - the function that implement the quick Sort
 * @arr: the array to be sorted
 * @low: the starting index
 * @high: the ending index
 */

void quickSort(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
