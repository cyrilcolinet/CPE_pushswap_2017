/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushswap tests 1
*/

# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include "pushswap.h"

void redirect_std_one()
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(pushswap, already_sorted_list, .init = redirect_std_one)
{
	char **av = malloc(sizeof(char**) * 7);

	av[0] = "./pushswap";
	av[1] = "2";
	av[2] = "1";
	av[3] = "3";
	av[4] = "6";
	av[5] = "5";
	av[6] = "8";
	pushswap_main(7, av);

	cr_assert_stdout_eq_str("sa pb pb pb sa pa pa pa");
}