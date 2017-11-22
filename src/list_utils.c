/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** list_utils functions
*/

# include "my.h"
# include "utils.h"
# include "pushswap.h"

void free_list(list_t *list)
{
	if (list == NULL)
		return;

	if (list->prev != NULL)
		free(list->prev);

	if (list->next != NULL)
		free(list->next);

	free(list);
}

void show_list(list_t *list)
{
	list_t *tmp = list;

	my_putstr("List sorted: ");
	while (tmp != NULL) {
		my_put_nbr(tmp->value);
		my_putchar(' ');
		tmp = tmp->next;
	}
}