##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Elias Josué HAJJAR LLAUQUEN
##

NAME	=	unit_tests

TEST_SRC	=	*.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

tests_run:	$(TEST_OBJ)
	$(CC) -o $(NAME) $(TEST_OBJ) --coverage -lcriterion
	./$(NAME)
	$(RM) $(NAME)
	$(RM) '*.o'
