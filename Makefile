##
## EPITECH PROJECT, 2017
## pushswap
## File description:
## Makefile
##

.PHONY			=	all, library, clean, fclean, re, tests

SRC_DIR			=	./src

TESTS_DIR		=	./tests

LIB_DIR			=	./lib

SRC 			=	$(SRC_DIR)/pushswap.c			\
					$(SRC_DIR)/rotating.c			\
					$(SRC_DIR)/sorting.c			\
					$(SRC_DIR)/swaping_pushing.c	\
					$(SRC_DIR)/utils.c 				\
					$(SRC_DIR)/list_utils.c 		\
					$(SRC_DIR)/displaying.c

UT_SRC			=	$(TESTS_DIR)/pushswap_tests1.c

INC_DIR			=	./include

NAME			=	push_swap

CFLAGS			= 	-Wall -Wextra -I$(INC_DIR) -L$(LIB_DIR) -lmy

all:			$(NAME)

library:
				make -C $(LIB_DIR)/my 

$(NAME):		library
				gcc -o $(NAME) $(SRC) $(SRC_DIR)/main.c $(CFLAGS)

clean:
				rm -f *.o
				rm -f *.gc*
				rm -f vgcore.*

fclean:			clean
				rm -f $(NAME)
				rm -f units
				make fclean -C $(LIB_DIR)/my

re:				fclean all

tests_run:		re
				gcc -o units $(SRC) $(UT_SRC) -lcriterion -lgcov --coverage $(CFLAGS)
				./units