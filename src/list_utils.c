/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** list_utils functions
*/

# include "utils.h"
# include "pushswap.h"

void free_list(list_t *list)
{
	if(list == NULL)
		return;

	if (list->prev != NULL)
		free(list->prev);

	if (list->next != NULL)
		free(list->next);

	free(list);
}