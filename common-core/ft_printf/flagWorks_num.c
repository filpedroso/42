/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagWorks_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:22:46 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/25 14:24:57 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	num_flag_help(int *count_p, t_flags flags, int cont_len, int num);
static void	num_flag_left(int *count_p, t_flags flags, int cont_len, int num);
static int	printnbr_hub(long num, char conv_type);

void	num_flag(va_list *args_p, int *count_p, t_flags flags, int cont_len)
{
	long	num;

	num = 0;
	if (flags.conv == 'i' || flags.conv == 'd')
	{
		num = va_arg(*args_p, int);
		if (num < 0)
		{
			*count_p += ft_printchar('-');
			num = -num;
		}
	}
	else if (flags.conv == 'u' || flags.conv == 'X' || flags.conv == 'x')
		num = va_arg(*args_p, unsigned int);
	else if (flags.conv == 'p')
	{
		*count_p += ft_printstr("0x", 0);
		num = (long)(uintptr_t)va_arg(*args_p, void *);
	}
	num_flag_help(count_p, flags, cont_len, num);
}

static void	num_flag_help(int *count_p, t_flags flags, int cont_len, int num)
{
	if (!flags.l_just)
	{
		if (flags.precision > cont_len)
		{
			if (flags.precision > flags.width)
				*count_p += print_many('0', (flags.precision - cont_len));
			else
			{
				*count_p += print_many(' ', (flags.width - flags.precision));
				*count_p += print_many('0', (flags.precision - cont_len));
			}
		}
		else if (flags.width > cont_len)
			*count_p += print_many(flags.zero_pad, (flags.width - cont_len));
		*count_p += printnbr_hub(num, flags.conv);
	}
	else if (flags.l_just)
		num_flag_left(count_p, flags, cont_len, num);
}

static void	num_flag_left(int *count_p, t_flags flags, int cont_len, int num)
{
	if (flags.precision > cont_len)
	{
		*count_p += print_many('0', (flags.precision - cont_len));
		*count_p += printnbr_hub(num, flags.conv);
		if (flags.width > flags.precision)
			*count_p += print_many(' ', (flags.width - flags.precision));
	}
	else
	{
		*count_p += printnbr_hub(num, flags.conv);
		if (flags.width > cont_len)
			*count_p += print_many(' ', (flags.width - cont_len));
	}
}

static int	printnbr_hub(long num, char conv_type)
{
	if (conv_type == 'i' || conv_type == 'd' || conv_type == 'u')
		return (ft_printnbr(num));
	if (conv_type == 'p' || conv_type == 'x' || conv_type == 'X')
		return (print_hex((uintptr_t)num, 0, conv_type));
	else
		return (0);
}
