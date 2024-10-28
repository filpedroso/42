/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:39:03 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/30 12:55:34 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;
	char	buffer[3];

	hexa = "0123456789abcdef";
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			buffer[0] = '\\';
			buffer[1] = hexa[(*str >> 4) & 0xF];
			buffer[2] = hexa[*str & 0xF];
			write(1, buffer, 3);
		}
		str++;
	}
}

/* int	main(void)
{
	char	str[] = "asdf\ndf";

	ft_putstr_non_printable(str);
} */
