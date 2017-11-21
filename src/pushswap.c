/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap functions
*/

# include "pushswap.h"
# include "utils.h"
# include "my.h"

void pushswap(list_t *one, list_t *two)
{
	
}

int main(int ac, char **av)
{
	list_t *one = create_list();
	list_t *two = create_list();

	if (!one || !two) {
		my_printerr("Malloc failed.\n");
		return (84);
	}

	one = params_to_list(ac, av);

	if (list_size(one) != (ac - 1)) {
		my_printerr("The args count is different. Aborded.\n");
		return (84);
	}

	pushswap(one, two);

	return (0);
}