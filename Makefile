##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

FILE_O = *.o
LIBMY_A = libmy.a
INCLUDE = include
CONV = $(SRCS:.c=.o)
MY_HUNTER = my_hunter
CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

$(LIBMY_A):
	gcc -c window.c -Iinclude
	ar rcs $(LIBMY_A) $(FILE_O)
	gcc -c my_hunter.c $(LIBMY_A) -Iinclude
	gcc -o $(MY_HUNTER) my_hunter.c $(CFLAGS) $(LIBMY_A) -Iinclude
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
