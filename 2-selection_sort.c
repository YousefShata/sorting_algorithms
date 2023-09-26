#include "sort.h"

/**
 * selection_sort - sorts an array using Selection Sort
 * @array: the array
 * @size: the size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, courier;

	for (i = 0; i < size - 1; i++)
	{
		courier = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[courier])
			{
				tmp = array[courier];
				array[courier] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
