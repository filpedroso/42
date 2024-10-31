# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 16:59:24 by fpedroso          #+#    #+#              #
#    Updated: 2024/10/30 21:03:20 by fpedroso         ###   ########.fr        #
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

re: fclean all

test: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJ)

.PHONY: all clean fclean re test
