/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:48:39 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/29 19:26:56 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	final[7];

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			final[0] = (i / 10) + '0';
			final[1] = (i % 10) + '0';
			final[2] = ' ';
			final[3] = (j / 10) + '0';
			final[4] = (j % 10) + '0';
			final[5] = ',';
			final[6] = ' ';
			if (!(i == 98 && j == 99))
				write (1, final, 7);
			else
				write (1, final, 5);
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
}*/
