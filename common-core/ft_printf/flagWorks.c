/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagWorks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:20:52 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/25 12:39:29 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(const char **format, t_flags *flags);
static void	conv_work(const char **str, va_list *args_p, int *count_p);

void	flag_work(const char **str, va_list *args_p, int *count_p, int cont_len)
{
	t_flags	flags;

	init_flags(&flags);
	parse_flags(str, &flags);
	while (is_flag(**str))
		(*str)++;
	if (!flags.has_flag)
		conv_work(str, args_p, count_p);
	else if (flags.conv == 'c')
		c_flag(args_p, count_p, flags);
	else if (flags.conv == 's')
		str_flag(args_p, count_p, flags, cont_len);
	else if (flags.conv == 'i', flags.conv == 'd', flags.conv == 'u')
		num_flag(args_p, count_p, flags, cont_len);
	else if (flags.conv == 'x', flags.conv == 'X', flags.conv == 'p')
		hex_flag(args_p, count_p, flags, cont_len);
}

void	c_flag(va_list args_p, int *count_p, t_flags flags)
{
	if (!flags.l_just && flags.width)
	{
		*count_p += print_many(' ', flags.width - 1);
		*count_p += ft_printchar(va_arg(args_p, int));
	}
	else if (flags.l_just && flags.width)
	{
		*count_p += ft_printchar(va_arg(args_p, int));
		*count_p += print_many(' ', flags.width - 1);
	}
	else
		*count_p += ft_printchar(va_arg(args_p, int));
}

void	str_flag(va_list args_p, int *count_p, t_flags flags, int cont_len)
{
	int	trim;

	trim = 0;
	if (cont_len > flags.precision)
		trim = cont_len - flags.precision;
	if (!flags.l_just && (flags.width > cont_len))
	{
		*count_p += print_many(' ', (flags.width - cont_len) + trim);
		*count_p += ft_printstr(va_arg(*args_p, char *), trim);
	}
	else if (flags.l_just && (flags.width > cont_len))
	{
		*count_p += ft_printstr(va_arg(*args_p, char *), trim);
		*count_p += print_many(' ', (flags.width - cont_len) + trim);
	}
}

void	num_flag(va_list args_p, int *count_p, t_flags flags, int cont_len)
{
	long	num;

	if (flags.conv == 'i' || flags.conv == 'd')
	{
		num = va_arg(args_p, int);
		if (num < 0)
		{
			*count_p += ft_printchar('-');
			num = -num;
		}
	}
	else if (flags.conv == 'u')
		num = va_arg(args_p, unsigned int);
	if (cont_len >= flags.width)
	{
		*count_p += ft_printnbr(num);
		return ;
	}
	else
		num_flag_help(count_p, flags, cont_len, num);
}

void	num_flag_help(int *count_p, t_flags flags, int cont_len, int num)
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
		*count_p += ft_printnbr(num);
	}
	else if (flags.l_just)
		num_flag_left(count_p, flags, cont_len, num);
}

void	num_flag_left(int *count_p, t_flags flags, int cont_len, int num)
{
	if (flags.precision > cont_len)
	{
		*count_p += print_many('0', (flags.precision - cont_len));
		*count_p += ft_printnbr(num);
		if (flags.width > flags.precision)
			*count_p += print_many(' ', (flags.width - flags.precision));
	}
	else
	{
		*count_p += ft_printnbr(num);
		if (flags.width > cont_len)
			*count_p += print_many(' ', (flags.width - cont_len));
	}
}

void	init_flags(t_flags *flags)
{
	flags->has_flag = 0;
	flags->l_just = 0;
	flags->zero_pad = ' ';
	flags->precision = -1;
	flags->width = 0;
	flags->conv = '\0';
}

static void	parse_flags(const char **format, t_flags *flags)
{
	while (**format && (ft_isdigit(**format) || is_flag(**format)))
	{
		flags->has_flag = 1;
		if (**format == '-')
		{
			flags->l_just = 1;
			flags->zero_pad = 0;
		}
		else if (**format == '0' && flags->width == 0 && flags->l_just == 0)
			flags->zero_pad = '0';
		else if (**format == '.')
		{
			flags->precision = ft_atoi(*format + 1);
			*format += -1 + num_len(flags->precision);
		}
		else if (ft_isdigit(**format) && flags->precision == -1)
		{
			flags->width = ft_atoi(*format);
			*format += -1 + num_len(flags->width);
		}
		(*format)++;
	}
	if (is_conversion(**format))
		flags->conv = **format;
}

static void	conv_work(const char **str, va_list *args_p, int *count_p)
{
	if (is_conversion(**str))
	{
		if (**str == 'c')
			*count_p += ft_printchar(va_arg(*args_p, int));
		else if (**str == 's')
			*count_p += ft_printstr(va_arg(*args_p, char *), 0);
		else if (**str == 'i' || **str == 'd')
			*count_p += ft_printnbr(va_arg(*args_p, int));
		else if (**str == 'u')
			*count_p += ft_printnbr(va_arg(*args_p, unsigned int));
		else if (**str == 'p')
		{
			ft_printstr("0x", 0);
			*count_p += 2 + print_hex((uintptr_t)va_arg(*args_p, void *), 0,
					'x');
		}
		else if (**str == 'x' || **str == 'X')
			*count_p += print_hex((uintptr_t)va_arg(*args_p, unsigned int), 0,
					**str);
		(*str)++;
	}
}
// TODO
// arriving at flag_works, possible cases:
// there are no flags, proceed to conv_work
// a special case for strings:
//		precision crops, width aligns
// 		zero pad gets ignored and pad is done with spaces normally
// a special case for i and d
//		if it's negative, the sign gets printed first, count_p is incremented
// cases with left justification overrides zero padding
// 		and change the order of printing, conv_work being called first
// some functions must have redundant logic,
// if I separate by type there's redundant logic in left justication
// if I separate by left justifcation or not there will be redundant logic for strings and integer cases
// minus sign can be printed before everything,
// but conv_work should not re-print it if this is the case