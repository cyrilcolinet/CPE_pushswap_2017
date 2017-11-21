/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** utils functions (header file)
*/

# ifndef UTILS_H
# define UTILS_H

# include "pushswap.h"

list_t 		*create_elem(int value);
list_t 		*insert_end_elem(list_t *list, int value);
list_t 		*insert_first_elem(list_t *list, int value);
list_t 		*last_elem(list_t *list);

void 		initiate_flags(flag_t *flag);

# endif