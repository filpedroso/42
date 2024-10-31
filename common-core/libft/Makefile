# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 16:59:24 by fpedroso          #+#    #+#              #
#    Updated: 2024/10/31 19:40:37 by fpedroso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror
NAME = libft.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TEST = test

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ) $(TEST)

fclean: clean
	rm -f $(NAME)

obliterate:
	find . \( -type f -o -type d \) \
    ! -name "*.c" \
    ! -name "libft.h" \
    ! -name "Makefile" \
	! -name "." \
	! -name ".." \
    -exec rm -rf {} +

re: fclean all

test: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJ)

.PHONY: all clean fclean re test
