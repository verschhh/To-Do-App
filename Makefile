##
## EPITECH PROJECT, 2021
## makefile
## File description:
## i
##

SRC	=	src/main.c	\
		src/listing.c	\
		src/addition.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_to_do

LDFLAGS	=	-L -lmy

CPPFLAGS	=	-I include/

CFLAGS =	-Wall -Wextra

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

fclean:	clean
	$(RM) src/*.c~
	$(RM) vgcore.*

re: fclean all

.PHONY: test_run debug clean fclean re all
