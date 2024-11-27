/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:06 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/12 13:52:09 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	args;

	va_start(args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
			count += pv_parse_args(*(++input), args);
		else if (*input == '%' && *(input + 1) == '%')
			count += write(1, ++input, 1);
		else
			count += write(1, input, 1);
		input++;
	}
	va_end(args);
	return (count);
}

int	pv_parse_args(char letter, va_list args)
{
	int		count;
	char	c;

	count = 0;
	if (letter == 'c')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (letter == 's')
		count += pv_putstr(va_arg(args, char *));
	else if (letter == 'p')
		count += pv_putaddress(va_arg(args, void *), 1);
	else if (letter == 'd' || letter == 'i')
		count += pv_puthex_n_deci(va_arg(args, int), 10, 0);
	else if (letter == 'u')
		count += pv_puthex_n_deci(va_arg(args, unsigned int), 10, 0);
	else if (letter == 'x')
		count += pv_puthex_n_deci(va_arg(args, unsigned int), 16, 0);
	else if (letter == 'X')
		count += pv_puthex_n_deci(va_arg(args, unsigned int), 16, 1);
	return (count);
}

int	pv_putstr(char *s)
{
	if (!s)
		return (pv_putstr("(null)"));
	if (!*s)
		return (0);
	return (write(1, s, 1) + pv_putstr(s + 1));
}

int	pv_putaddress(void *p, int prefix)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long)p;
	if (!n)
		return (pv_putstr("(nil)"));
	if (prefix)
		count += pv_putstr("0x");
	if (n >= 16)
		count += pv_putaddress((void *)(n / 16), 0);
	return (count += write(1, &"0123456789abcdef"[n % 16], 1));
}

int	pv_puthex_n_deci(long n, int base, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= base)
		count += pv_puthex_n_deci(n / base, base, upper);
	return (count += write(1, &digits[n % base], 1));
}

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("???%%%???\n");
	printf("???%%%???");
	/* char			character = 'z';
	char			*string = '\0';
	char			*pointer = "";
	int				integer = INT_MIN;
	unsigned int	u_int = UINT_MAX;
	int				hex = 0xffffff;
	int				result;

	ft_printf("\nft_printf:\n");
	result = ft_printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	ft_printf("\nft_printf return value: %d\n", result);

	printf("\n\nprintf:\n");
	result = printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	printf("\nprintf return value: %d\n", result); */
}