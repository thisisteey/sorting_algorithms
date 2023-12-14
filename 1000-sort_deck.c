#include "deck.h"

void swpnd(deck_node_t *fst, deck_node_t *scd);
int cmporder(const card_t *fst, const card_t *scd);
void insertion_sort_list(deck_node_t **list);
void sort_deck(deck_node_t **deck);

/**
 * swpnd - swap two nodes in a doubly linked list
 * @fst: pointer to the first node
 * @scd: pointer to the second node
 * Return: void
 */
void swpnd(deck_node_t *fst, deck_node_t *scd)
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
 * cmporder - compares two playing cards for their order
 * @fst: pointer to the frist card
 * @scd: pointer to the second card
 * Return: 1 if fstcrd < scdcrd and 0 otherwise
 */
int cmporder(const card_t *fst, const card_t *scd)
{
	char *st1, *st2;
	char *rankval[] = {"King", "Queen", "Jack", "10", "9", "8", "7", "6",
		"5", "4", "3", "2", "Ace"};
	int fstv = 0, scdv = 0, x = 0;

	for (x = 0 ; x < 13 ; x++)
	{
		for (st1 = (char *)fst->value, st2 = rankval[x] ; *st1 &&
				*st1 == *st2 ; ++st1, ++st2)
			;
		if (*st1 == 0 && *st2 == 0)
		{
			fstv = x;
			break;
		}
	}
	for (x = 0 ; x < 13 ; x++)
	{
		for (st1 = (char *)scd->value, st2 = rankval[x] ; *st1 &&
				*st1 == *st2 ; ++st1, ++st2)
			;
		if (*st1 == 0 && *st2 == 0)
		{
			scdv = x;
			break;
		}
	}
	if (fst->kind == scd->kind)
		return (fstv < scdv);
	return (fst->kind > scd->kind);
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion
 * @list: double pointer to the head of the node in the list
 * Return: void
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *currnd, *innernd;

	if (!list || !*list || !(*list)->next)
		return;
	currnd = (*list)->next;
	while (currnd != NULL)
	{
		innernd = currnd;
		currnd = currnd->next;
		while (innernd != NULL && innernd->prev != NULL)
		{
			if (cmporder(innernd->prev->card, innernd->card))
			{
				swpnd(innernd->prev, innernd);
				if (!innernd->prev)
					*list = innernd;
			}
			else
				innernd = innernd->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards using insert sort
 * @deck: double pointer to the head of the head of the deck
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}
