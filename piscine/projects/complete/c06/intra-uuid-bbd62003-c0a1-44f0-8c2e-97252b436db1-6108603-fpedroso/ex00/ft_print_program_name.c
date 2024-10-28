/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:15:25 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/07 17:47:55 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc)
	{
		while (**argv)
		{
			write (1, *argv, 1);
			*argv = *argv + 1;
		}
		write (1, "\n", 1);
		return (0);
	}
}
