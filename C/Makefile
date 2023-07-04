##
## EPITECH PROJECT, 2021
## makefile
## File description:
## i
##

MAIN	=	main.c

SRC	=	$(shell find ./src/ -name '*.c')

SRCTEST	=	$(shell find ./tests/ -name '*.c')

OBJMAIN	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

OBJTEST	=	$(SRCTEST:.c=.o)

NAME	=	my_to_do

LDFLAGS	=	-L -lmy

CPPFLAGS	=	-I include/

CFLAGS =	-Wall -Wextra

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJMAIN)
	gcc -o $(NAME) $(OBJMAIN) $(OBJ) $(LDFLAGS) $(CPPFLAGS)

debug: CFLAGS += -g3
debug: re

test_run: $(OBJ) $(OBJTEST)
	 gcc -o unit_tests $(OBJ) $(OBJTEST) $(LDFLAGS) $(CPPFLAGS) -lcriterion --coverage
	./unit_tests

clean:
	$(RM) $(OBJMAIN)
	$(RM) $(OBJ)
	$(RM) $(OBJTEST)
	$(RM) $(NAME)

fclean:	clean
	$(RM) src/*.c~
	$(RM) vgcore.*
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda

re: fclean all

.PHONY: test_run debug clean fclean re all
