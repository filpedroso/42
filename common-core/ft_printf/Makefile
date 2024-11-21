# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 17:30:13 by fpedroso          #+#    #+#              #
#    Updated: 2024/11/20 20:38:07 by fpedroso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Wall -Werror
SRC = $(FILES)
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

TEST = test


FILES = 	ft_printf.c \
			ft_printf_helpers.c \
			ft_printf_tools.c \


$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	ar -x $(LIBFT)
	ar -rcs $(NAME) *.o
	$(RM) *.o

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

clean:
	$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

test: fclean $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(TEST)


.PHONY: all clean fclean re test
