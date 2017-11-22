/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** displaying functions
*/

# include "my.h"
# include "pushswap.h"

void display_iteration(int iteration, flag_t flag)
{
	if (flag.flagged) {
		my_putstr("Iteration number: ");
		my_put_nbr(iteration);
		my_putchar('\n');
	}
}

void display_action(char *action)
{
	my_putstr(" - Action: ");
	my_putstr(action);
	my_putchar('\n');
}

void display_lists(list_t *one, list_t *two, char *action, flag_t flag)
{
	if (flag.flagged) {
		my_putstr(" - List A: ");
		show_list(one);
		my_putchar('\n');
		my_putstr(" - List B: ");
		show_list(two);
		my_putchar('\n');
		display_action(action);
		my_putchar('\n');
		my_putchar('\n');
	}
}