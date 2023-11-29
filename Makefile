##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

SRC = analyse_event.c \
	animation.c \
	in_game.c \
	music.c \
	my_hunter.c \
	sprite_game.c \
	sprite_menu.c \
	my_gameplay.c \
	my_display_in_game.c \
	help.c \
	mpsomething.c \
	my_strcmp.c

FILE_O = *.o
LIBMY_A = libmy.a
INCLUDE = include
CONV = $(SRCS:.c=.o)
MY_HUNTER = my_hunter
CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio


$(LIBMY_A):
	gcc -c $(SRC) -Iinclude
	ar rcs $(LIBMY_A) $(FILE_O)
	gcc -c my_hunter.c $(LIBMY_A) -Iinclude
	gcc -o $(MY_HUNTER) my_hunter.c $(CFLAGS) $(LIBMY_A) -Iinclude -g3
	make clean

clean:
	find -type f -iname '*.o' -delete
	find -type f -iname '*.a' -delete

fclean:
	make clean
	rm -f $(MY_HUNTER)

re:
	make fclean
	make
