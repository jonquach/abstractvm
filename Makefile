##
## Makefile for  in /home/quach_a/Dropbox/EPITECH PROJET/TEK2/lin_c/Abstract_VM
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Sun Mar  1 19:47:13 2015 Jonathan Quach
## Last update Sun Mar  1 22:10:49 2015 LIN Chaohui
##

NAME =	avm

SRC =	main.cpp \
	Action.cpp \
	Operand.cpp \
	Lexer.cpp \
	Parse.cpp \
	Exception.cpp \

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS += -W -Wall -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	 g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)


fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
