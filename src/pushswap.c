/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap functions
*/

# include "pushswap.h"
# include "utils.h"
# include "my.h"

void pushswap(list_t *one)
{
	list_t *two = NULL;
	flag_t flag;

	initiate_flags(&flag);
	while (!flag.passed) {
		if (one->value > last_elem(one)->value)
			one = rotate_one(one, two);
		else if (one->value > one->next->value)
			one = swap_one(one, two);

		flag.one = sort_asc(one);

		if (!flag.one && one->value < one->next->value) {
			push_two(&one, &two, &flag);
			sort_two(&two, &flag);
		}

		while (flag.one && two != NULL) {
			push_one(&one, &two, &flag);
			flag.one = sort_asc(one);
		}

		if (flag.one && flag.two && two == NULL)
			flag.passed = true;
	}

	/*free(one->prev);
	free(one->next);
	free(one);
	free(two->prev);
	free(two->next);
	free(two);*/
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

int pushswap_main(int ac, char **av)
{
	int offset = 1;
	list_t *one = NULL;

	if (ac == 2 && !check_parameter(av[offset])) {
		my_puterr("Bad argument. Check if argument contains only digits and \n");
		return (84);
	} else if (ac > 2) {
		while (av[offset]) {
			if (!check_parameter(av[offset])) {
				my_puterr("Arguments must contains only digits.\n");
				return (84);
			}

			one = insert_end_elem(one, my_atoi(av[offset]));
			offset++;
		}

		pushswap(one);
	}

	free_list(one);
	return (0);
}