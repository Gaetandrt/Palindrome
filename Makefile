##
## EPITECH PROJECT, 2021
## makefile for my_sifleinfo
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	-g3 -W -Wall -Wextra -Iinclude/

SRC		=	$(wildcard *.c) \
			$(wildcard src/*.c) \
			$(wildcard lib/*.c) \
			$(wildcard src/error_handling/*.c) \

SRC 	:= 	$(filter-out requirement.c, $(SRC))

OBJ		=	$(SRC:.c=.o)

TARGET	=	palindrome

all:	$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(TARGET)
	rm -f a.out

re: fclean all
