/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:01:17 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/20 20:23:50 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_flags
{
	int	left_justify;
	int	zero_padding;
	int	precision;
	int	width;
}		t_flags;

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
void	parse_flags(const char **format, t_flags *flags);
int		content_len(const char **str, va_list *args_p);
int		print_many(char c, int amount);
void	init_flags(t_flags *flags);
int		num_len(long long num);
int		is_flag(char c);
int		is_conversion(char c);

#endif