#include "sort.h"

void qS(int *array, size_t low, size_t high, size_t size);
size_t partition(int *array, size_t low, size_t high, size_t size);

/**
 * quick_sort - sorting using Quick Sort
 * @array: array of int
 * @size: size of the array
 * Return: return nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		qS(array, 0, (size - 1), size);
}

/**
 * partition - determin pivot position
 * @array: input array
 * @low: start index
 * @high: end index
 * Return: The index of the pivot
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;
	int tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}

/**
 * qS - Acvhice the quick sorting
 * @array:input array
 * @low:start index
 * @high: last index
 * Return: Nothing
 */
void qS(int *array, size_t low, size_t high, size_t size)
{
	size_t partitionIndex;

	if (low < high)
	{
		partitionIndex = partition(array, low, high, size);
		if(partitionIndex != 0)
			qS(array, low, partitionIndex - 1, size);
		if(partitionIndex < size - 1)
			qS(array, partitionIndex + 1, high, size);
	}
}
