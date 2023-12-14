#include "sort.h"

int retdigit(long num, int index);
int radpass(int *array, ssize_t ize, int index, int *arrsort);
void radix_sort(int *array, size_t size);

/**
 * retdigit - retrieves a digit from a given number at a specific index
 * @num: the number to retrieve digit from
 * @index: the index of the digit to retrieve
 * Return: the value of the digit at the given index
 */
int retdigit(long num, int index)
{
	long x = 0L, pstmul = 1L;
	long digval;

	for (x = 0 ; x < index ; x++)
		pstmul *= 10L;
	digval = ((num / pstmul) % 10);
	return (digval);
}

/**
 * radpass - executes a single pass of LSD radix sort on an array
 * @array: the array of integers to pass LSD
 * @size: the size of the array
 * @index: the index of the digit considered during the execution
 * @arrsort: target array of the same size to store sorted element
 * Return: 1 on code success
 */
int radpass(int *array, ssize_t size, int index, int *arrsort)
{
	ssize_t x;
	int digcount[10] = {0};

	for (x = 0 ; x < size ; x++)
		digcount[retdigit(array[x], index)]++;
	for (x = 1 ; x <= 9 ; x++)
		digcount[x] += digcount[x - 1];
	for (x = size - 1 ; x > -1 ; x--)
		arrsort[digcount[retdigit(array[x], index)]-- - 1] = array[x];
	return (1);
}

/**
 * radix_sort - sorts an array of integers using radix sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *orarray, *arrsort, *tmptr, *ptr;
	int maxval = 0;
	size_t idx, digcount = 1;

	if (array == NULL || size < 2)
		return;
	for (idx = 0 ; idx < size ; idx++)
		if (array[idx] > maxval)
			maxval = array[idx];
	while (maxval /= 10)
		digcount++;
	orarray = array;
	arrsort = ptr = malloc(sizeof(int) * size);
	if (arrsort == NULL)
		return;
	for (idx = 0 ; idx < digcount ; idx++)
	{
		radpass(orarray, (ssize_t)size, idx, arrsort);
		tmptr = orarray;
		orarray = arrsort;
		arrsort = tmptr;
		print_array(orarray, size);
	}
	for (idx = 0 ; idx < size ; idx++)
		array[idx] = orarray[idx];
	free(ptr);
}
