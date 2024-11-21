/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:30:17 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/20 20:33:34 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	percent_work(const char **str, va_list *args_p, int *count_p);
static void	flag_work(const char **str, va_list *args_p, int *count_p);
static void	conv_work(const char **str, va_list *args_p, int *count_p);
static int	print_hex(uintptr_t num, int counter, char upper);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
	{
		return (-1);
	}
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			percent_work(&str, &args, &count);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

static void	percent_work(const char **str, va_list *args_p, int *count_p)
{
	while (**str == '%' && *(*str + 1) == '%')
	{
		ft_putchar_fd('%', 1);
		*str += 2;
		(*count_p)++;
	}
	if (**str == '%')
		(*str)++;
	if (is_flag(**str))
		flag_work(str, args_p, count_p);
	else if (is_conversion(**str))
		conv_work(str, args_p, count_p);
}

static void	flag_work(const char **str, va_list *args_p, int *count_p)
{
	t_flags	flags;
	va_list	copy_args;
	int		cont_len;
	int		padding_len;

	init_flags(&flags);
	parse_flags(str, &flags);
	while (is_flag(**str))
		(*str)++;
	va_copy(copy_args, *args_p);
	cont_len = content_len(str, &copy_args);
	va_end(copy_args);
	if (**str == 's' && flags.precision >= 0 && cont_len > flags.precision)
		cont_len = flags.precision;
	padding_len = (flags.width - cont_len);
	if (padding_len < 0)
		padding_len = 0;
	if (!flags.left_justify && !flags.zero_padding)
		*count_p += print_many(' ', padding_len);
	if (!flags.left_justify && flags.zero_padding)
		*count_p += print_many('0', padding_len);
	conv_work(str, args_p, count_p);
	if (flags.left_justify)
		*count_p += print_many(' ', padding_len);
}

static void	conv_work(const char **str, va_list *args_p, int *count_p)
{
	while (is_conversion(**str))
	{
		if (**str == 'c')
			*count_p += ft_putchar_fd(va_arg(*args_p, int), 1);
		else if (**str == 's')
			*count_p += ft_putstr_fd(va_arg(*args_p, char *), 1);
		else if (**str == 'i' || **str == 'd')
			*count_p += ft_putnbr_fd(va_arg(*args_p, int), 1);
		else if (**str == 'u')
			*count_p += ft_putnbr_fd(va_arg(*args_p, unsigned int), 1);
		else if (**str == 'p')
		{
			ft_putstr_fd("0x", 1);
			*count_p += 2 + print_hex((uintptr_t)va_arg(*args_p, void *), 0,
					'x');
		}
		else if (**str == 'x' || **str == 'X')
			*count_p += print_hex((uintptr_t)va_arg(*args_p, unsigned int), 0,
					**str);
		(*str)++;
	}
}

static int	print_hex(uintptr_t num, int counter, char upper)
{
	if (num >= 16)
		counter = print_hex(num / 16, counter, upper);
	if (upper == 'X')
	{
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
		counter++;
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
		counter++;
	}
	return (counter);
}

/* int	main(void)
{
	int count = ft_printf("jacarezinho danado %%\n");
	//int count2 = printf("jacarezinho danado %%\n");
	ft_printf("ft: %p, %c\n", &count, 'c');
	//printf("std: %p, %c", &count, 'c');
	ft_printf("1: Hello, %s!\n", "World");
	ft_printf("2: Number: %d\n", 42);
	ft_printf("3: Width and precision: %10.5d\n", 42);
	ft_printf("4: Left justify: %-10d|\n", 42);
} */

/* int main(void)
{
	int ret1, ret2;

	// Simple strings
	ret1 = printf("1: Hello, %s!\n", "World");
	ret2 = ft_printf("1: Hello, %s!\n", "World");
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	// Integers
	ret1 = printf("2: Number: %d\n", 42);
	ret2 = ft_printf("2: Number: %d\n", 42);
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	// Width and precision
	ret1 = printf("3: Width and precision: %10.5d\n", 42);
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	// Flags
	ret1 = printf("4: Left justify: %-10d\n", 42);
	ret2 = ft_printf("4: Left justify: %-10d\n", 42);
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	// Hexadecimal
	ret1 = printf("5: Hex: %#x\n", 255);
	ret2 = ft_printf("5: Hex: %#x\n", 255);
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	// Pointers
	int num = 42;
	ret1 = printf("6: Pointer: %p\n", &num);
	ret2 = ft_printf("6: Pointer: %p\n", &num);
	printf("printf: %d, ft_printf: %d\n\n", ret1, ret2);

	return (0);
} */
