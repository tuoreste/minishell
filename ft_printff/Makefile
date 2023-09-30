NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
CC = cc
SRC = ft_printf.c ft_external.c ft_external2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean

.PHONY:	all clean fclean re