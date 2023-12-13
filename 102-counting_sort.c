#include "sort.h"

int count_int(int *array, size_t size, int target);
void counting_sort(int *array, size_t size);

/**
 * count_int - count the number of times a specific int occurs
 * @array: the array of integers to search
 * @size: the size of the array
 * @target: the integer to count occurences for
 * Return: the number of occurences of the target integer
 */
int count_int(int *array, size_t size, int target)
{
	int occurence = 0;
	size_t x;

	for (x = 0 ; x < size ; x++)
	{
		if (array[x] == target)
			occurence++;
	}
	return (occurence);
}

/**
 * counting_sort - sorts an array of ints using counting sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int maxval = 0, cmcount = 0, target = 0;
	size_t x, count;
	int *arrcount, *arrsort;

	if (array == NULL || size < 2)
		return;
	for (x = 0 ; x < size ; x++)
	{
		if (array[x] > maxval)
		{
			maxval = array[x];
		}
	}
	arrcount = malloc(sizeof(int) * (maxval + 1));
	if (arrcount == NULL)
		return;
	for (count = 0 ; count < ((size_t)maxval + 1) ; count++)
	{
		if (count == 0)
			arrcount[count] = count_int(array, size, target);
		else
		{
			cmcount = arrcount[count - 1] + count_int(array, size, target);
			arrcount[count] = cmcount;
		}
		target++;
	}
	print_array(arrcount, (maxval + 1));
	arrsort = malloc(sizeof(int) * size);
	if (arrsort == NULL)
	{
		free(arrcount);
		return;
	}
	for (x = 0 ; x < size ; x++)
		arrsort[arrcount[array[x]]-- - 1] = array[x];
	for (x = 0 ; x < size ; x++)
		array[x] = arrsort[x];
	free(arrsort);
	free(arrcount);
}
