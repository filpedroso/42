/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagWorks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:20:52 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/25 17:41:13 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_flag(va_list *args_p, int *count_p, t_flags flags);
static void	str_flag(va_list *args_p, int *count_p, t_flags flags,
				int cont_len);
static void	parse_flags(const char **format, t_flags *flags);
static void	conv_work(const char **str, va_list *args_p, int *count_p);

void	flag_works(const char **str, va_list *args_p, int *count_p,
		int cont_len)
{
	t_flags	flags;

	init_flags(&flags);
	parse_flags(str, &flags);
	while (!is_conversion(**str))
		(*str)++;
	if (!flags.has_flag)
		conv_work(str, args_p, count_p);
	else if (flags.conv == 'c')
		c_flag(args_p, count_p, flags);
	else if (flags.conv == 's')
		str_flag(args_p, count_p, flags, cont_len);
	else if (is_conversion(flags.conv))
		num_flag(args_p, count_p, flags, cont_len);
	(*str)++;
}

static void	c_flag(va_list *args_p, int *count_p, t_flags flags)
{
	if (!flags.l_just && flags.width)
	{
		*count_p += print_many(' ', flags.width - 1);
		*count_p += ft_printchar(va_arg(*args_p, int));
	}
	else if (flags.l_just && flags.width)
	{
		*count_p += ft_printchar(va_arg(*args_p, int));
		*count_p += print_many(' ', flags.width - 1);
	}
	else
		*count_p += ft_printchar(va_arg(*args_p, int));
}
static void	str_flag(va_list *args_p, int *count_p, t_flags flags, int cont_len)
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
			*count_p += ft_printstr("0x", 0);
			*count_p += print_hex((uintptr_t)va_arg(*args_p, void *), 0,
					'x');
		}
		else if (**str == 'x' || **str == 'X')
			*count_p += print_hex((uintptr_t)va_arg(*args_p, unsigned int), 0,
					**str);
	}
}