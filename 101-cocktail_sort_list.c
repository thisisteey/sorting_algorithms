#include "sort.h"

void swppst(listint_t *fst, listint_t *scd);
listint_t *rev_traverse(listint_t *hptr, listint_t *tptr, listint_t *mhptr);
void cocktail_sort_list(listint_t **list);

/**
 * swppst - swap positions of two nodes in a doubly linked list
 * @fst: pointer to the first node to swap
 * @scd: pointer to the second node to swap
 * Return: void
 */
void swppst(listint_t *fst, listint_t *scd)
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
 * rev_traverse - sorts a list in reverse order
 * @hptr: pointer to the head of the list
 * @tptr: pointer to the tail of the list
 * @mhptr: pointer to the original list head
 * Return: pointer to the new head of the list
 */
listint_t *rev_traverse(listint_t *hptr, listint_t *tptr, listint_t *mhptr)
{
	while (tptr && tptr->prev)
	{
		if (tptr->n < tptr->prev->n)
		{
			swppst(tptr->prev, tptr);
			if (tptr->prev == NULL)
				mhptr = tptr;
			print_list(mhptr);
		}
		else
			tptr = tptr->prev;
		if (tptr->prev == NULL)
			hptr = tptr;
	}
	return (hptr);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: the doubly linked listto be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *currhead, *currtail, *lstlent;
	int x = 0, y = 0, swpnd = 1;

	if (list == NULL || *list == NULL)
		return;
	lstlent = *list;
	for (x = 0 ; lstlent ; x++)
	{
		lstlent = lstlent->next;
	}
	if (x < 2)
		return;
	currhead = *list;
	while (y < x)
	{
		swpnd = 0;
		while (currhead && currhead->next)
		{
			if (currhead->n > currhead->next->n)
			{
				swppst(currhead, currhead->next);
				swpnd++;
				if (!currhead->prev->prev)
					*list = currhead->prev;
				print_list(*list);
			}
			else
				currhead = currhead->next;
			if (!currhead->next)
				currtail = currhead;
		}
		currhead = rev_traverse(currhead, currtail, *list);
		*list = currhead;
		y++;
	}
}
