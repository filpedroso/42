/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:27:58 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/01 18:39:22 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	strtol(const char *str, char **endptr, int base);
static int	checkbase(const char *str, int base);
static char	*advance_and_sign(const char *str, int *sign);

int	atoi(const char *str)
{
	return ((int)strtol(str, (char **)NULL, 10));
}

static long	strtol(const char *str, char **endptr, int base)
{
	int	sign;
	int	result;

	if (!(base == 0 || (base >= 2 && base <= 36)))
	{
		return (errno EINVAL);
	}
	base = checkbase(str, base);
	sign = 1;
	result = 0;
	str = advance_and_sign(str, &sign);
	while (ft_isvaliddig(*str, base))
	{
		result *= base + (*str - '0');
		str++;
	}
	*endptr = str;
	return (result * sign);
}

static int	ft_isvaliddig(char c, int base)
{
	const char *bases;
	int	i;

	bases = "0123456789abcdefghijklmnopqrstuvwxyz"
	c = (char)ft_tolower(c);
	if (base >=2 && base <= 9)
	{
		if (ft_isdigit(c))
			return (1);
	}
	if (base >= 10 && base <= 36)
	{
		while (i < base)
		{
			if (c == bases[i])
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

static char	*advance_and_sign(const char *str, int *sign)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			*sign = -1;
		}
		str++;
	}
	return (str);
}

static int	checkbase(const char *str, int base)
{
	if ((base == 0 || base == 16) && str[0] == '0' && str[1] == 'x')
	{
		return (16);
	}
	else if (base == 0 && str[0] == '0')
	{
		return (8);
	}
	else if (base == 0)
	{
		return (10);
	}
	else
		return (base);
}
