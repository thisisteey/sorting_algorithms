#include "sort.h"

size_t knuth_sq(size_t size);
void shell_sort(int *array, size_t size);

/**
 * knuth_sq - get the largest gap for the knuth sequence by size
 * @size: the size of the array to be calculated
 * Return: the calculated gap size
 */
size_t knuth_sq(size_t size)
{
	size_t n = 1;

	while (n < size)
		n = n * 3 + 1;
	return ((n - 1) / 3);
}

/**
 * shell_sort - sort an array of ints using shell sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gapsz, x, y;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (gapsz = knuth_sq(size) ; gapsz ; gapsz = (gapsz - 1) / 3)
	{
		for (x = gapsz ; x < size ; x++)
		{
			tmp = array[x];
			for (y = x ; y > gapsz - 1 && array[y - gapsz] > tmp ; y -= gapsz)
			{
				array[y] = array[y - gapsz];
			}
			array[y] = tmp;
		}
		print_array(array, size);
	}
}
