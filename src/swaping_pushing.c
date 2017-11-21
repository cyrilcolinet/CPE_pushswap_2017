/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** swaping functions
*/

# include "my.h"
# include "utils.h"
# include "pushswap.h"

list_t *swap_one(list_t *one, list_t *two)
{
	one->prev = one->next;
	one->next->next->prev = one->next->prev;
	one->next = one->next->next;
	one->prev->next = one;
	one->prev->prev = NULL;
	one = one->prev;

	my_putstr("sa");
	my_putchar(((sort_asc(one) && two == NULL) ? '\n' : ' '));

	return (one);
}

list_t *swap_two(list_t *two)
{
	two->prev = two->next;

	if (two->next->next != NULL) {
		two->next->next->prev = two->next->prev;
		two->next = two->next->next;
		two->prev->next = two;
		two->prev->prev = NULL;
		two = two->prev;
	} else {
		two->prev = two;
		two->next = NULL;
		two->prev->prev = NULL;
		two = two->prev;
	}

	my_putstr("sb ");

	return (two);
}

void push_one(list_t **one, list_t **two, flag_t *flag)
{
	flag->one = false;
	*one = insert_first_elem(*one, (*two)->value);

	if ((*two)->next != NULL) {
		*two = (*two)->next;
		(*two)->prev->next = NULL;
		(*two)->prev = NULL;
	} else {
		*two = NULL;
		flag->two = true;
	}

	my_putstr("pa");
	my_putchar(((sort_asc(*one) && *two == NULL) ? '\n' : ' '));
}

void push_two(list_t **one, list_t **two, flag_t *flag)
{
	flag->two = false;
	*two = insert_first_elem(*two, (*one)->value);

	if ((*one)->next != NULL) {
		*one = (*one)->next;
		(*one)->prev->next = NULL;
		(*one)->prev = NULL;
	} else {
		*one = NULL;
	}

	my_putstr("pb ");
}