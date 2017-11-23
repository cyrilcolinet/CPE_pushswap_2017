/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap functions
*/

# include "pushswap.h"
# include "utils.h"
# include "my.h"

void pushswap(list_t *one, bool flaged)
{
	int iterations = 1;
	list_t *two = NULL;
	flag_t flag;

	initiate_flags(&flag, flaged);
	display_iteration(0, flag);
	display_lists(one, two, "nothing, default list", flag);
	while (!flag.passed) {
		if (one->value > last_elem(one)->value) {
			display_iteration(iterations++, flag);
			one = rotate_one(one, two, flag);
		} else if (one->value > one->next->value) {
			display_iteration(iterations++, flag);
			one = swap_one(one, two, flag);
		}

		flag.one = sort_asc(one);

		if (!flag.one && one->value < one->next->value) {
			display_iteration(iterations++, flag);
			push_two(&one, &two, &flag);
			//display_iteration(iterations++, flag);
			sort_two(one, &two, &flag);
		}

		while (flag.one && two != NULL) {
			display_iteration(iterations++, flag);
			push_one(&one, &two, &flag);
			flag.one = sort_asc(one);
		}

		if (flag.one && flag.two && two == NULL)
			flag.passed = true;
	}

	free_list(one);
	free_list(two);
}

bool check_parameter(char *arg)
{
	for (int i = 0; arg[i]; i++) {
		if ((arg[i] == '-' || arg[i] == '+') &&
			!(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
			return (false);
		if (!(arg[i] >= '0' && arg[i] <= '9')) {
			if (arg[i] != '-' && arg[i] != '+')
				return (false);
		}
	}

	return (true);
}

bool check_flags(char *str)
{
	if (str[0] == '-' && str[1] == 'v')
		return (true);

	return (false);
}

int pushswap_main(int ac, char **av)
{
	list_t *one = NULL;
	bool flagged = false;

	if (ac <= 2) {
		my_puterr("Usage: ./pushswap [-vT] <num1> <num2> ... <n>\n");
		return (84);
	} else if (ac > 2) {
		flagged = check_flags(av[1]);

		for (int i = (flagged ? 2 : 1); av[i]; i++) {
			if (!check_parameter(av[i])) {
				my_puterr("Only integer authorized.\n");
				return (84);
			}

			one = insert_end_elem(one, my_atoi(av[i]));
		}

		pushswap(one, flagged);
	}

	free_list(one);
	return (0);
}