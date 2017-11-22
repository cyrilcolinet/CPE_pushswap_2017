/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** rotating functions
*/

# include "my.h"
# include "utils.h"
# include "pushswap.h"

list_t *rotate_one(list_t *one, list_t *two, flag_t flag)
{
	list_t *last = last_elem(one);
	last->next = one;
	one->next->prev = NULL;
	one->next = NULL;
	one->prev = last;

	while (one->prev != NULL)
		one = one->prev;

	if (!flag.flagged) {
		my_putstr("ra");
		my_putchar(((sort_asc(one) && two == NULL) ? '\n' : ' '));
	} else {
		display_lists(one, two, "ra", flag);
	}

	return (one);
}

list_t *rotate_two(list_t *one, list_t *two, flag_t flag)
{
	list_t *last = last_elem(two);
	last->next = two;
	two->next->prev = NULL;
	two->prev = last;
	two->next = NULL;

	while (two->prev != NULL)
		two = two->prev;

	if (!flag.flagged) {
		my_putstr("rb ");
	} else {
		display_lists(one, two, "rb", flag);
	}

	return (two);
}