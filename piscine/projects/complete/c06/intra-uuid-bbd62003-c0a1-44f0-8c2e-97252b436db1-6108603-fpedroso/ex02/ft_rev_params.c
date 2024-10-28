/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:38 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/07 17:53:54 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	while (--argc > 0)
	{
		while (*argv[argc])
		{
			write (1, argv[argc], 1);
			(argv[argc])++;
		}
		write (1, "\n", 1);
	}
	return (0);
}
