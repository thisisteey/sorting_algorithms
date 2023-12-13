#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmpvar;
	size_t pass, x;

	if (array == NULL || size == 0)
		return;
	pass = 0;
	while (pass < size)
	{
		for (x = 0 ; x < size - 1 ; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmpvar = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmpvar;
				print_array(array, size);
			}
		}
		pass++;
	}
}
