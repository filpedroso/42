/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:09:16 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/20 19:55:47 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_many(char c, int amount)
{
	int	count;

	if (amount <= 0)
		return (0);
	count = 0;
	while (amount)
	{
		count += write(1, &c, 1);
		amount--;
	}
	return (count);
}

void	init_flags(t_flags *flags)
{
	flags->left_justify = 0;
	flags->zero_padding = 0;
	flags->precision = -1;
	flags->width = 0;
}

int	num_len(long long num)
{
	int	len;
	int	minus_flag;

	minus_flag = 0;
	len = 1;
	if (num < 0)
	{
		num = -num;
		minus_flag = 1;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len + minus_flag);
}

int	is_flag(char c)
{
	return (c == '-' || c == '.' || c == '0');
}

int	is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}
