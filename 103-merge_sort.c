#include "sort.h"

void cmpmerge(int *array, size_t strtidx, size_t stpidx, int *output);
void rec_top_down(int *array, size_t strtidx, size_t stpidx, int *output);
void merge_sort(int *array, size_t size);

/**
 * cmpmerge - compare and merges two halves of an array
 * @array: the array of integer to compare
 * @strtidx: the start index of the array
 * @stpidx: the stop index of the array
 * @output: the output array
 * Return: void
 */
void cmpmerge(int *array, size_t strtidx, size_t stpidx, int *output)
{
	size_t x = strtidx, y, z, mididx;

	y = mididx = (strtidx + stpidx) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + strtidx, mididx - strtidx);
	printf("[right]: ");
	print_array(array + mididx, stpidx - mididx);
	for (z = strtidx ; z < stpidx ; z++)
	{
		if (x < mididx && (y >= stpidx || array[x] <= array[y]))
		{
			output[z] = array[x++];
		}
		else
		{
			output[z] = array[y++];
		}
	}
	printf("[Done]: ");
	print_array(output + strtidx, stpidx - strtidx);
}

/**
 * rec_top_down - sorts an array of ints using top-down recursive approach
 * @array: the array of integers to sort
 * @strtidx: the start index of the array
 * @stpidx: the stop index of the array
 * @output: the output array
 * Return: void
 */
void rec_top_down(int *array, size_t strtidx, size_t stpidx, int *output)
{
	size_t mididx;

	mididx = (strtidx + stpidx) / 2;
	if (stpidx - strtidx < 2)
	{
		return;
	}
	rec_top_down(output, strtidx, mididx, array);
	rec_top_down(output, mididx, stpidx, array);
	cmpmerge(output, strtidx, stpidx, array);
}

/**
 * merge_sort - sorts an array of ints using merge sort
 * @array: the array of intgers to sort
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *newarr;
	size_t x;

	if (array == NULL || size < 2)
		return;
	newarr = malloc(sizeof(int) * size);
	if (newarr == NULL)
		return;
	for (x = 0 ; x < size ; x++)
		newarr[x] = array[x];
	rec_top_down(array, 0, size, newarr);
	free(newarr);
}
