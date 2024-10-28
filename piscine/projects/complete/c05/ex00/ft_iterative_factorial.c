/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:03:23 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 12:17:38 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fac;

	if (nb < 0)
		return (0);
	fac = 1;
	while (nb > 0)
	{
		fac *= nb;
		nb--;
	}
	return (fac);
}

/*int	main(void)
{
	int nb = 4;
	int fac = ft_iterative_factorial(nb);
	printf("fac of %i is %i", nb, fac);
}*/
