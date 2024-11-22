# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 17:30:13 by fpedroso          #+#    #+#              #
#    Updated: 2024/11/21 20:26:52 by fpedroso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
SRC = $(FILES)
OBJ = $(SRC:.c=.o)

TEST = test


FILES = 	ft_printf.c \
			ft_printf_helpers.c \
			ft_printf_tools.c \
			ft_printf_trinkies.c \
			ft_printf_atoi.c \
			ft_printf_printnbr.c \



$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ) $(TEST)

test: fclean $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TEST)

fclean: clean
	rm -f $(NAME)

re: fclean all


oblit:
	find . \( -type f -o -type d \) \
    ! -name "*.c" \
    ! -name "ft_printf.h" \
    ! -name "Makefile" \
	! -name "." \
	! -name ".." \
    -exec rm -rf {} +

.PHONY: all clean fclean re test
