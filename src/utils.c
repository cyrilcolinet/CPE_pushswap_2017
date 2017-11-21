/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** utils function
*/

# include <stdlib.h>

# include "pushswap.h"
# include "utils.h"

list_t *create_list(void)
{
	list_t *list = malloc(sizeof(list_t*));

	if (list == NULL)
		return NULL;

	return (list);
}

int list_size(list_t *list)
{
	list_t *temp = list;
	int size = 0;

	while (temp != NULL) {
		size++;
		temp = temp->next;
	}

	return (size);
}

void put_data_in_list(list_t **list, char *arg)
{
	list_t *elem = malloc(sizeof(*elem));
	elem->num = arg;
	elem->next = *list;
	*list = elem;
	free(elem);
}

list_t *params_to_list(int ac, char **av)
{
	list_t *list = NULL;

	for (int i = 0; i < ac; i++) {
		put_data_in_list(&list, av[i]);
	}

	return (list);
}