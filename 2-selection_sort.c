#include "sort.h"

/**
 * selection_sort - sorts an array using Selection Sort
 * @array: the array
 * @size: the size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, courier;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		courier = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[courier])
				courier = j;

			if (courier != i)
			{
				tmp = array[courier];
				array[courier] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
}
