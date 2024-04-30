##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Elias Josué HAJJAR LLAUQUEN
##

NAME	=	my_paint

CPPFLAGS	=	-I./include

CSFML	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio

SRC	= 	src/events.c	\
		src/main.c	\
		src/hud_handler.c	\
		src/draw_system.c	\
		src/buttons_handler.c	\
		src/sys_functions.c	\
		src/button_color_handler.c	\
		src/keyboard_shortcuts.c	\
		src/tools.c	\
		src/drop_menu.c	\
		src/window_save.c	\
		src/size_display.c	\
		src/help_message.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

tests_run:
	$(MAKE) -C tests/ tests_run
