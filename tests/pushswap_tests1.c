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

Test(pushswap, no_sorted_list, .init = redirect_std_one)
{
	char *av[] = { "./pushswap", "2", "1", "3", "6", "5", "8" };

	pushswap_main(7, av);
	cr_assert_stdout_eq_str("sa pb pb pb sa pa pa pa\n");
}

Test(pushswap, already_sorted_list, .init = redirect_std_one)
{
	char *av[] = { "./pushswap", "14", "50", "134", "243", "9742", "9999" };

	pushswap_main(7, av);
	cr_assert_stdout_eq_str("\n");
}

Test(pushswap, error_no_integer, .init = redirect_std_one)
{
	char *av[] = { "./pushswap", "a", "b" };

	pushswap_main(3, av);
	cr_assert_stderr_eq_str("Only integer authorized.\n");
}

Test(pushswap, error_less_arguments, .init = redirect_std_one)
{
	char *av[] = { "./pushswap" };

	pushswap_main(1, av);
	cr_assert_stderr_eq_str("Usage: ./pushswap [-vT] <num1> <num2> ... <n>\n");
}

Test(pushswap, no_unique_parameter, .init = redirect_std_one)
{
	char *av[] = { "./pushswap", "3", "6", "3", "7" };

	pushswap_main(5, av);
	cr_assert_stderr_eq_str("Arguments must be unique.\n");
}