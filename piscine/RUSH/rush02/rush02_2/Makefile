# Name of your executable
NAME = rush-02

# Compiler to use
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = rush-02.c dict_parser.c number_converter.c utils.c string_manip.c

# Main rule to build your program
$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Clean rule to remove object files
clean:
	rm -f *.o

# Full clean rule to remove object files and executable
fclean: clean
	rm -f $(NAME)

# Phony targets
.PHONY: clean fclean
