#include "sort.h"

/**
 * selection_sort - sorts an array of ints using selection algorith
 * @array: the array of integers to be sorted
 * @size:: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, z;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (x = 0 ; x < size - 1 ; x++)
	{
		for (y = size - 1, z = x + 1 ; y > x ; y--)
		{
			if (array[y] < array[z])
			{
				z = y;
			}
		}
		if (array[x] > array[z])
		{
			tmp = array[x];
			array[x] = array[z];
			array[z] = tmp;
			print_array(array, size);
		}
	}
}
