/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:20:06 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/21 20:18:40 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		deli_rec(long long num, int *count);

int	ft_printnbr(long n)
{
	long long	num;
	int			count;

	num = n;
	count = 0;
	if (num < 0)
	{
		num = -num;
		ft_printchar('-');
		count++;
	}
	deli_rec(num, &count);
	return (count);
}

static void	deli_rec(long long num, int *count)
{
	if (num >= 10)
		deli_rec(num / 10, count);
	ft_printchar(num % 10 + '0');
	(*count)++;
}
