/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:08 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/10/09 22:10:20 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_temp
{
	int	x;
	int	y;
	int	size;
}		t_square_info;

// ft functions:

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strndup(const char *s, int n);
char	*ft_strdup(char *s);
int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_tiktok(char *str, char delim);

// specific functions:
void	print_map_error(void);

// atoi
int		ft_atoi(char *str);
int		calculate_sign(int sign, char c);
int		calculate_result(int result, char *str);
int		is_space(char c);

// from find_map.c >>>OK!!!
# define ROWS 10
# define COLS 10
# define CHAR_EMPTY '.'
# define CHAR_FULL 'X'

void	find_max_square(char map[ROWS][COLS]);
void	check_all_squares(char map[ROWS][COLS], int square_size,
			t_square_info *max_square, int *found_space);
int		check_fit_square(char map[ROWS][COLS], int coord_x, int coord_y,
			int square_size);
void	mark_square(char map[ROWS][COLS], t_square_info square);
void	update_max_square_info(int coord_x, int coord_y, int square_size,
			t_square_info *max_square);
void	print_map(char mapa[ROWS][COLS]);

#endif
