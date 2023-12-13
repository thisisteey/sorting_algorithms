#include "sort.h"

/**
 * swpnd - swap two nodes in a doubly linked list
 * @fst: pointer to the first node
 * @scd: pointer to the second node
 * Return: void
 */
void swpnd(listint_t *fst, listint_t *scd)
{
	if (fst->prev)
		fst->prev->next = scd;
	if (scd->next)
		scd->next->prev = fst;
	fst->next = scd->next;
	scd->prev = fst->prev;
	fst->prev = scd;
	scd->next = fst;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion
 * @list: double pointer to the head of the node in the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *currnd, *innernd;

	if (!list || !*list || !(*list)->next)
		return;
	currnd = (*list)->next;
	while (currnd != NULL)
	{
		innernd = currnd;
		currnd = currnd->next;
		while (innernd != NULL && innernd->prev != NULL)
		{
			if (innernd->prev->n > innernd->n)
			{
				swpnd(innernd->prev, innernd);
				if (!innernd->prev)
					*list = innernd;
				print_list((const listint_t *)*list);
			}
			else
				innernd = innernd->prev;
		}
	}
}
