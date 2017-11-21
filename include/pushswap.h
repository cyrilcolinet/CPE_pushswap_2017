/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap functions (header files)
*/

# ifndef PUSHSWAP_H
# define PUSHSWAP_H

struct list {
	int 	num;
	list 	*next;
};

typedef struct list list_t;

void pushswap(list_t *one, list_t *two);

# endif