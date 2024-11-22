/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:01:17 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/21 20:59:05 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
char	*ft_strdup(const char *s1);
int		print_many(char c, int amount);
void	init_flags(t_flags *flags);
int		num_len(long long num);
int		is_flag(char c);
int		is_conversion(char c);
int		ft_atoi(const char *str);
int		ft_printnbr(long n);
int		ft_printstr(char *s);
int		ft_printchar(char c);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_isascii(int c);

#endif