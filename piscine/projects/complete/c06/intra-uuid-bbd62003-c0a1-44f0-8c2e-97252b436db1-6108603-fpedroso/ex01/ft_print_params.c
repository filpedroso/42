/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:31:58 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/07 17:51:46 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc)
	{
		while (*++argv)
		{
			while (**argv)
			{
				write (1, *argv, 1);
				(*argv)++;
			}
			write (1, "\n", 1);
		}
		return (0);
	}
}
