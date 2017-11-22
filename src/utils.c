/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** utils function
*/

# include "my.h"
# include "pushswap.h"
# include "utils.h"

list_t *create_elem(int value)
{
	list_t *list = malloc(sizeof(list_t));

	if (list == NULL) {
		my_puterr("Malloc failed. Aborded.\n");
		exit(84);
	}

	list->value = value;
	list->prev = NULL;
	list->next = NULL;

	return (list);
}

list_t *insert_end_elem(list_t *list, int value)
{
	list_t *tmp = list;
	list_t *elem = create_elem(value);

	if (list == NULL) {
		return (elem);
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = elem;
		elem->prev = tmp;
	}

	return (list);
}

list_t *insert_first_elem(list_t *list, int value)
{
	list_t *tmp = list;
	list_t *elem = create_elem(value);

	if (list == NULL) {
		return (elem);
	} else {
		while (tmp->prev != NULL)
			tmp = tmp->prev;

		tmp->prev = elem;
		elem->next = tmp;
		list = list->prev;
	}

	return (list);
}

list_t *last_elem(list_t *list)
{
	while (list->next != NULL)
		list = list->next;

	return (list);
}

void initiate_flags(flag_t *flag, bool flaged)
{
	flag->one = false;
	flag->two = true;
	flag->passed = false;
	flag->flagged = flaged;
}