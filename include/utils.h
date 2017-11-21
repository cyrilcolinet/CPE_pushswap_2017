/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** utils functions (header file)
*/

# ifndef UTILS_H
# define UTILS_H

# include "pushswap.h"

list_t 		*create_list(void);
int 		list_size(list_t *list);
void 		put_data_in_list(list_t **list, char *arg);
list_t 		*params_to_list(int ac, char **av);

# endif