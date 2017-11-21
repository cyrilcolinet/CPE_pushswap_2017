##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## Makefile
##

.PHONY			= 	all re clean fclean tests

SRC_DIR			=	./src

UT_DIR			=	./tests

INC_DIR			=	./include

SRC 			= 	$(SRC_DIR)/my_functions.c 			\
					$(SRC_DIR)/my_printf.c 				\
					$(SRC_DIR)/my_put_nbr.c				\
					$(SRC_DIR)/print_char.c 			\
					$(SRC_DIR)/print_integer.c 			\
					$(SRC_DIR)/print_octal.c 			\
					$(SRC_DIR)/print_string.c 			\
					$(SRC_DIR)/print_uint.c 			\
					$(SRC_DIR)/utils.c

OBJ				= 	$(SRC:.c=.o)

UT_SRC			=	$(UT_DIR)/my_printf_tests_one.c 	\
					$(UT_DIR)/my_printf_tests_two.c

CFLAGS			=	-Wall -Wextra -I$(INC_DIR)

LDFLAGS			= 	-lcriterion -lgcov

NAME			= 	libmy.a

all:			$(NAME) tests 		## Compile

$(NAME):		$(OBJ) 				## Compile inta library named $(NAME)
				ar rc $(NAME) $(OBJ)

clean: 								## Clean output files, and coverage files
				rm -f $(OBJ)
				rm -f *.gc*

fclean:			clean 				## Clean units and $(NAME) file and basic clean
				rm -f $(NAME)
				rm -f units

re:				fclean all 			## Recompile

tests:			$(NAME) 			## Unitary tests
				cc -o units $(SRC) $(UT_SRC) $(CFLAGS) $(LDFLAGS) --coverage -L. -lmy
				./units