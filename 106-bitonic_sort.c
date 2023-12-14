#include "sort.h"

void swpint(int *fst, int *scd);
void cmpswp(int ascnd, int *array, size_t strtidx, size_t endidx);
void mergebiton(int ascnd, int *array, size_t strtidx, size_t endidx);
void recbit(int ascnd, int *array, size_t size, size_t strtidx, size_t endidx);
void bitonic_sort(int *array, size_t size);

/**
 * swpint - swaps the value of two integers
 * @fst: pointer to the first value
 * @scd: pointer to the second value
 * Return: void
 */
void swpint(int *fst, int *scd)
{
	if (*fst != *scd)
	{
		*fst = *fst + *scd;
		*scd = *fst - *scd;
		*fst = *fst - *scd;
	}
}

/**
 * cmpswp - compares and swap elements bitonically
 * @ascnd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @strtidx: the start index of the array
 * @endidx: the end index of the array
 * Return: void
 */
void cmpswp(int ascnd, int *array, size_t strtidx, size_t endidx)
{
	size_t mididx = (endidx - strtidx + 1) / 2, x;

	for (x = strtidx ; x < strtidx + mididx ; x++)
		if ((array[x] > array[x + mididx]) == ascnd)
			swpint(&array[x], &array[x + mididx]);
}

/**
 * mergebiton - bitonically merge elements
 * @ascnd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @strtidx: the start index of the array
 * @endidx: the end index of the array
 * Return: void
 */
void mergebiton(int ascnd, int *array, size_t strtidx, size_t endidx)
{
	size_t mididx = (strtidx + endidx) / 2;

	if (endidx - strtidx < 1)
		return;
	cmpswp(ascnd, array, strtidx, endidx);
	mergebiton(ascnd, array, strtidx, mididx);
	mergebiton(ascnd, array, mididx + 1, endidx);
}

/**
 * recbit - bitonically recursively sorts elementts
 * @ascnd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @size: size of the array of integers
 * @strtidx: the start index of the array
 * @endidx: the end index of the array
 * Return: void
 */
void recbit(int ascnd, int *array, size_t size, size_t strtidx, size_t endidx)
{
	size_t mididx = (strtidx + endidx) / 2;

	if (endidx - strtidx < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", endidx - strtidx + 1, size,
		ascnd ? "UP" : "DOWN");
	print_array(array + strtidx, endidx - strtidx + 1);
	recbit(1, array, size, strtidx, mididx);
	recbit(0, array, size, mididx + 1, endidx);
	mergebiton(ascnd, array, strtidx, endidx);
	printf("Result [%lu/%lu] (%s):\n", endidx - strtidx + 1, size,
		ascnd ? "UP" : "DOWN");
	print_array(array + strtidx, endidx - strtidx + 1);
}

/**
 * bitonic_sort - sorts an array of integers using bitonic sort
 * @array: pointer to the array of integers
 * @size: the size of the array of integers
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recbit(1, array, size, 0, size - 1);
}
