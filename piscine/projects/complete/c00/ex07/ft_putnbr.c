/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:17:59 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/29 20:45:25 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	mod;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	if (nb < 10)
	{
		mod = nb + '0';
		write (1, &mod, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	mod = (nb % 10) + '0';
	write (1, &mod, 1);
}

/*int	main(void)
{
	int nb = -24456;
	ft_putnbr(nb);
}*/
