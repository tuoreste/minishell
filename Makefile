# NAMEutable name
NAME = minishell

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = #main.c shell.c commands.c

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

clean:
	rm -f $(OBJS)

re:fclean all

# Phony targets
.PHONY: all fclean clean 
