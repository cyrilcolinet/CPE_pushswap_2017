/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** operations functions
*/

# include "pushswap.h"
# include "operations.h"
# include "utils.h"

void sa_sb(list_t *list)
{
	if (list_size(list) >= 2) {
		int tmp = list[0].num;
		list[0].num = list[1].num;
		list[1].num = tmp;
	}
}

void sc(list_t *one, list_t *two)
{
	sa_sb(one);
	sa_sb(two);
}

void pa(list_t *one, list_t *two)
{
	if (list_size(two) > 0) {

	}
}

void pb(list_t *one, list_t *two)
{
	if (list_size(one) > 0) {
		
	}
}