include libft/Makefile
# Main Makefile

NAME = minishell

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = minishell.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Compile the NAMEutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the NAMEutable
fclean:
	rm -f $(OBJS) $(NAME)
	rm -f libft/*.o libft/libft.a
clean:
	rm -f $(OBJS)

re: fclean all

# Phony targets
.PHONY: all fclean clean

# Include sub-Makefiles