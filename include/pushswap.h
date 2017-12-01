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
	bool 			flagged;
	int 			iterations;
};

typedef struct list list_t;
typedef struct flag flag_t;

void 		pushswap(list_t *one, bool flagged);
bool 		check_parameter(char *arg);
bool		check_flags(char *str);
bool		checkunique_args(int ac, char **av);
int			pushswap_main(int ac, char **av);

bool 		sort_asc(list_t *one);
bool 		sort_desc(list_t *two);
void 		sort_two(list_t *one, list_t **two, flag_t *flag);

list_t		*rotate_one(list_t *one, list_t *two, flag_t flag);
list_t		*rotate_two(list_t *one, list_t *two, flag_t flag);
list_t 		*swap_one(list_t *one, list_t *two, flag_t flag);
list_t 		*swap_two(list_t *one, list_t *two, flag_t flag);
void 		push_one(list_t **one, list_t **two, flag_t *flag);
void 		push_two(list_t **one, list_t **two, flag_t *flag);

void 		free_list(list_t *list);
void 		show_list(list_t *list);

void 		display_iteration(int iteration, flag_t flag);
void		display_lists(list_t *a, list_t *b, char *c, flag_t f);
void 		display_action(char *action);

# endif