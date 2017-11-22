/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** sorting functions
*/

# include "utils.h"
# include "pushswap.h"

bool sort_asc(list_t *one)
{
	if (one == NULL)
		return (true);

	while (one->value < one->next->value) {
		one = one->next;

		if (one->next == NULL)
			return (true);
	}

	return (false);
}

bool sort_desc(list_t *two)
{
	if (two == NULL)
		return (true);

	while (two->value > two->next->value) {
		two = two->next;

		if (two->next == NULL)
			return (true);
	}

	return (false);
}

void sort_two(list_t *one, list_t **two, flag_t *flag)
{
	if ((*two)->next != NULL) {
		if ((*two)->value < last_elem(*two)->value)
			*two = rotate_two(one, *two, *flag);
		if ((*two)->value < (*two)->next->value)
			*two = swap_two(one, *two, *flag);
		flag->two = sort_desc(*two);
	}

	if ((*two)->next == NULL)
		flag->two = true;
}