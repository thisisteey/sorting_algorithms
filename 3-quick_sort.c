#include "sort.h"

void swpint(int *array, size_t size, int *fst, int *scd);
size_t part_lomuto(int *array, size_t size, ssize_t lidx, ssize_t hidx);
void qsortlmt(int *arrat, size_t size, ssize_t lidx, ssize_t hidx);
void quick_sort(int *array, size_t size);

/**
 * swpint - function swaps to ints values in an array
 * @array: the array of integers with values to be swapped
 * @size: size of the array with values
 * @fst: pointer ot the of the first value
 * @scd: pointer to the second value
 * Return: void
 */
void swpint(int *array, size_t size, int *fst, int *scd)
{
	if (*fst != *scd)
	{
		*fst = *fst + *scd;
		*scd = *fst - *scd;
		*fst = *fst - *scd;
		print_array((const int *)array, size);
	}
}

/**
 * part_lomuto - partitions an array using the lomuto scheme
 * @array: the array of integers to be partitioned
 * @size: the size of the the array of integers
 * @lidx: low index of the partition range
 * @hidx: high index of the partition range
 * Return: index of the pivot element after partitioning
 */
size_t part_lomuto(int *array, size_t size, ssize_t lidx, ssize_t hidx)
{
	int x, y, pvt = array[hidx];

	for (x = y = lidx ; y < hidx ; y++)
		if (array[y] < pvt)
			swpint(array, size, &array[y], &array[x++]);
	swpint(array, size, &array[x], &array[hidx]);
	return (x);
}

/**
 * qsortlmt- quicksort algorithm using lomuto partition
 * @array: the array of integers to be partitioned
 * @size: the size of the the array of integers
 * @lidx: low index of the partition range
 * @hidx: high index of the partition range
 * Return: void
 */
void qsortlmt(int *array, size_t size, ssize_t lidx, ssize_t hidx)
{
	if (lidx < hidx)
	{
		size_t pvtidx = part_lomuto(array, size, lidx, hidx);

		qsortlmt(array, size, lidx, pvtidx - 1);
		qsortlmt(array, size, pvtidx + 1, hidx);
	}
}

/**
 * quick_sort - sorts an array of ints using quick sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsortlmt(array, size, 0, size - 1);
}
