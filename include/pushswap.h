/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap functions (header files)
*/

# include <stdlib.h>
# include <stdbool.h>

# ifndef PUSHSWAP_H
# define PUSHSWAP_H

struct list {
	int 			value;
	struct list 	*prev;
	struct list 	*next;
};

struct flag {
	bool 			one;
	bool 			two;
	bool 			passed;
};

typedef struct list list_t;
typedef struct flag flag_t;

void 		pushswap(list_t *one);
bool 		check_parameter(char *arg);
int			pushswap_main(int ac, char **av);

bool 		sort_asc(list_t *one);
bool 		sort_desc(list_t *two);
void 		sort_two(list_t **two, flag_t *flag);

list_t		*rotate_one(list_t *one, list_t *two);
list_t		*rotate_two(list_t *two);

list_t 		*swap_one(list_t *one, list_t *two);
list_t 		*swap_two(list_t *two);
void 		push_one(list_t **one, list_t **two, flag_t *flag);
void 		push_two(list_t **one, list_t **two, flag_t *flag);

void 		free_list(list_t *list);
void 		show_list(list_t *list);

# endif