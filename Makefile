##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	gcc -g3 -o my_rpg *.c -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	find -name "*~*" -delete -or -name "#*#" -delete

fclean:    clean
	rm -f my_rpg

re:	fclean all
