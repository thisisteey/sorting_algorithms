#include "sort.h"

void swpint(int *array, size_t size, int *fst, int *scd);
size_t part_hoare(int *array, ssize_t size, ssize_t lidx, ssize_t hidx);
void qsorthoare(int *array, size_t size, ssize_t lidx, ssize_t hidx);
void quick_sort_hoare(int *array, size_t size);

/**
 * swpint - swaps two integer values
 * @array: the array of integers to be swapped
 * @size: the sze of the array of integers
 * @fst: pointer to the first value to swap
 * @scd: pointer to the second value to swap
 * Return: void
 */
void swpint(int *array, size_t size, int *fst, int *scd)
{
	if (*fst != *scd)
	{
		*fst = *fst + *scd;
		*scd = *fst - *scd;
		*fst = *fst - *scd;
	}
	print_array((const int *)array, size);
}

/**
 * part_hoare - partitions an array using the hoare scheme
 * @array: the array of integers to be partitioned
 * @size: the size of the the array of integers
 * @lidx: low index of the partition range
 * @hidx: high index of the partition range
 * Return: index of the pivot element after partitioning
 */
size_t part_hoare(int *array, ssize_t size, ssize_t lidx, ssize_t hidx)
{
	ssize_t x = lidx - 1, y = hidx + 1;
	int pvt = array[hidx];

	while (x < size)
	{
		while (array[++x] < pvt)
			;
		while (array[--y] > pvt)
			;
		if (x < y)
			swpint(array, size, &array[x], &array[y]);
		else if (x >= y)
			break;
	}
	return (x);
}

/**
 * qsorthoare- quicksort algorithm using hoare partition
 * @array: the array of integers to be partitioned
 * @size: the size of the the array of integers
 * @lidx: low index of the partition range
 * @hidx: high index of the partition range
 * Return: void
 */
void qsorthoare(int *array, size_t size, ssize_t lidx, ssize_t hidx)
{
	if (lidx < hidx)
	{
		size_t pvtidx = part_hoare(array, size, lidx, hidx);

		qsorthoare(array, size, lidx, pvtidx - 1);
		qsorthoare(array, size, pvtidx, hidx);
	}
}

/**
 * quick_sort_hoare - sorts an array of ints using quick sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsorthoare(array, size, 0, size - 1);
}
