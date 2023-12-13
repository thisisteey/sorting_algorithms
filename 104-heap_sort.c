#include "sort.h"

#define parentidx(x) (((x) - 1) / 2)
#define leftchildidx(x) (((x) * 2) + 1)

void swpinte(int *array, size_t size, int *fst, int *scd);
void sift_down(int *array, size_t strtidx, size_t endidx, size_t size);
void convarray(int *array, size_t size);
void heap_sort(int *array, size_t size);

/**
 * swpinte - swaps two integer values
 * @array: the array of integers to be swapped
 * @size: the sze of the array of integers
 * @fst: pointer to the first value to swap
 * @scd: pointer to the second value to swap
 * Return: void
 */
void swpinte(int *array, size_t size, int *fst, int *scd)
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
 * sift_down - implements the sift_down operation
 * @array: the array of integers to be implemented
 * @size: the size of the array
 * @strtidx: the starting index of the array
 * @endidx: the ending index of the array
 * Return: void
 */
void sift_down(int *array, size_t strtidx, size_t endidx, size_t size)
{
	size_t curr = strtidx, swpidx, child;

	while (leftchildidx(curr) <= endidx)
	{
		child = leftchildidx(curr);
		swpidx = curr;
		if (array[swpidx] < array[child])
			swpidx = child;
		if (child + 1 <= endidx && array[swpidx] < array[child + 1])
			swpidx = child + 1;
		if (swpidx == curr)
			return;
		swpinte(array, size, &array[curr], &array[swpidx]);
		curr = swpidx;
	}
}

/**
 * convarray - converts an array into a heap in-place
 * @array: array of integer to be sorted
 * @size: the size of the array
 * Return: void
 */
void convarray(int *array, size_t size)
{
	ssize_t strtidx;

	strtidx = parentidx(size - 1);
	while (strtidx >= 0)
	{
		sift_down(array, strtidx, size - 1, size);
		strtidx--;
	}
}

/**
 * heap_sort - sorts an array of integers using heap sort
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t endidx;

	if (array == NULL || size < 2)
		return;
	convarray(array, size);
	endidx = size - 1;
	while (endidx > 0)
	{
		swpinte(array, size, &array[endidx], &array[0]);
		endidx--;
		sift_down(array, 0, endidx, size);
	}
}
