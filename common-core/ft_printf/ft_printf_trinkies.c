/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_trinkies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:31:24 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/21 20:17:07 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	size_t	buffer;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (s[0] == '\0')
		return (0);
	buffer = ft_strlen(s);
	write(1, s, buffer);
	return ((int)buffer);
}

int	ft_printchar(char c)
{
	if (!c || !(ft_isascii(c)))
		return (0);
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
