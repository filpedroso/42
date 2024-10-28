/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:05:07 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 12:59:39 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);
int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
	{
		return (2);
	}
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	sqrt = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;
	int	lower;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	lower = i - 1;
	if (nb - (lower * lower) <= (i * i) - nb)
	{
		return (lower);
	}
	else
	{
		return (i);
	}
}

/*int main()
{

	int i = ft_find_next_prime(10);
	int j = ft_find_next_prime(20);
	int k = ft_find_next_prime(50);
	int l = ft_find_next_prime(80);
	int m = ft_find_next_prime(200);

	printf ("%i %i %i %i %i", i, j, k, l, m);
}*/
